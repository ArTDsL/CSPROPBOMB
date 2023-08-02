//********************************************
//
// @created_in: 2023-07-23
// @lst_update: 2023-02-08 
// @author: Arthur 'ArTDsL'/'ArThDsL' Dias dos Santos Lasso 
// @project: Counter-Strike - PROP BOMB (https://github.com/ArTDsL/CSPROPBOMB)
// 
// [PROVIDED UNDER MIT LICENSE]
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//********************************************
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <ezButton.h>
//variables
int led_state = LOW;
int contrast = 75;
const byte LINES = 4;
const byte COLS = 3;
char * memclear = "";
String password_store = "";
String password = "";
int pass_stored = 0;
int bomb_status = 0;
int bomb_idle = 0;
int bomb_steps = 0;
int bomb_count = 0;
const int bomb_seconds_explosion = 45;
unsigned long bomb_secs_prev = 0;
long interval_bomb = 1000;
int show_info = 0;
//
unsigned long buzzerled_prev = 0;
long buzzerled_step = 1000;
int bomb_ms[9] = {600, 600, 500, 400, 300, 200, 150, 100, 50};
char keys[LINES][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte lineP[LINES] = {3, 8, 7, 5};
byte colsP[COLS] = {4, 2, 6};
//
Keypad kpd = Keypad(makeKeymap(keys), lineP, colsP, LINES, COLS);
LiquidCrystal lcd(9, 10, 11, 12, 13, A2);
ezButton toggleSwitch(A4);
//
void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A3, OUTPUT);
  toggleSwitch.setDebounceTime(50);
  analogWrite(A1, contrast);
  lcd.begin(16, 2);
  lcd.print("DEACTIVATED");
}
void BombBlew(){
  tone(A3, 0, 100);
  bomb_count = -1;
  led_state = LOW;
  buzzerled_step = 0;
  lcd.clear();
  delay(500);
  lcd.print("BOOOOM!");
  delay(10000);
  AD_Bomb(false);
  return;
}
void AD_Bomb(bool status){ //Activate / Deactivate Bomb
  password_store = "";
  pass_stored = 0;
  password = "";
  lcd.clear();
  delay(500);
  if(status == true){
    lcd.print("ACTIVATED");
    bomb_status = 1;
    show_info = 0;
  }else{
    bomb_steps = 0;
    bomb_secs_prev = 0;
    buzzerled_prev = 0;
    lcd.print("DEACTIVATED");
    bomb_status = 0;
    bomb_count = -1;
  }
}
void ClearScreen(){
  lcd.clear();
  delay(500);
}
void BombAdjust(int BUZZERSTEP_PRM){
  if(led_state == LOW){
    led_state = HIGH;
    buzzerled_step = bomb_ms[BUZZERSTEP_PRM];
    tone(A3, 4096, bomb_ms[BUZZERSTEP_PRM]);
  }else{
    led_state = LOW;
    buzzerled_step = bomb_ms[BUZZERSTEP_PRM];
    tone(A3, 0, bomb_ms[BUZZERSTEP_PRM]);
  }
}
void loop(){
  toggleSwitch.loop();
  if(toggleSwitch.getState() == HIGH && bomb_status == 0){
    AD_Bomb(false);
    lcd.clear();
    bomb_idle = 1;
    show_info = 0;
    return;
  }
  if(toggleSwitch.getState() == HIGH && bomb_status == 1){
    AD_Bomb(true);
    lcd.clear();
    bomb_idle = 1;
    show_info = 0;
    return;
  }
  if(bomb_status == 0 && toggleSwitch.getState() == LOW && bomb_idle == 0 && show_info == 0){
    lcd.clear();
    delay(500);
    lcd.print("DEACTIVATED");
    show_info = 1;
  }
  if(toggleSwitch.getState() == LOW && bomb_status == 0){
    bomb_idle = 0;
  }
  char key = kpd.getKey();
  if(password_store == "7355608"){
    if(bomb_status == 0 && bomb_idle == 0){
      AD_Bomb(true);
      return;
    }
    if(bomb_status == 1){
      AD_Bomb(false);
      ClearScreen();
      lcd.print("DEFUSED");
      delay(1500);
      ClearScreen();
      lcd.print("DEACTIVATED");
      bomb_status = 0;
      return;
    }
  }
  if(key && bomb_idle == 0){
    //press # to reset bomb
    if(strcmp(key, '#') == 0){
      if(bomb_status == 1){
        AD_Bomb(true);
        return;
      }
      if(bomb_status == 0){
        AD_Bomb(false);
        return;
      }
    }
    if(!strcmp(key, '#') == 0){
      Serial.println(key); //debug
      digitalWrite(A0, HIGH);
      tone(A3, 4096, 200);
      delay(100);
      digitalWrite(A0, LOW);
      tone(A3, 0, 100);
      //deal with the password
      lcd.clear();
      delay(200);
      password_store.concat(key);
      pass_stored++;
      lcd.setCursor(1, 0);
      password.concat("*");
      lcd.print(password);
      return;
    }
  }
  if(!key){
    if(bomb_steps >= bomb_seconds_explosion){
      BombBlew();
    }
    if(bomb_steps < bomb_seconds_explosion){
      if(bomb_status == 1){
        unsigned long bomb_secs_cur = millis();
        unsigned long buzzerled_beep = millis();
        if (buzzerled_beep - buzzerled_prev >= buzzerled_step){
          buzzerled_prev = buzzerled_beep;
          int seconds_square = int(sqrt(bomb_seconds_explosion));
          if(bomb_count == -1 || bomb_count == 0){
            bomb_count = 1;
          }
          if(bomb_count > 0){
            if(bomb_steps >= (bomb_count * seconds_square)){
              bomb_count += 1;
            }
          }
          BombAdjust(bomb_count);
          if(bomb_secs_cur - bomb_secs_prev >= interval_bomb){
            bomb_secs_prev = bomb_secs_cur;
            interval_bomb = 1000;
            bomb_steps++;
          }
          digitalWrite(A0, led_state);
        }
        return;
      }
    }
  }
}
