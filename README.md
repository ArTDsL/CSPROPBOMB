# CSGO2 PROP BOMB

**Password:** _7355608_

A CSGO2 BOMB prop made in arduino.

**DISCLAIMER:** THIS IS NOT A REAL BOMB/EXPLOSIVE DEVICE, IT'S A PROP (just like in movies they create fake stuff to represent real ones), JUST AN ART OBJECT!

### LICENSE

This source code is free, provided under the MIT License! Please, do not forget to give credits on your project, this will be appreciated! Free software takes time to make,  we love to do, but we also love when people get happy using it, by crediting a piece you let me know that you want more content and that i make a good work :)

Check the full MIT License [here](./LICENSE).

### INFORMATION

Before you start, be sure to check if the hardware are compatible with the library Keypad (version 3.1.1 from Mark Stanley & Alexander Brevig) and LiquidCrystal (version 1.0.7 from Arduino and Adafruit).

### Components used in the original build
_Next to the component is the model i use and the manufacturer!_

- Matrix Keypad 3x4 (**AITEXM ROBOT**)
- LCD Screen I2C 16x2 (**LCDC1602 - BYY**)
- Buzzer (**HXD-G**)
- Green LED
- Lever Switch (**6A 125AC** - 2 Connectors ON/OFF)
- Robocore Blackboard 1.0 (**Same as Arduino Uno R3**)
- 20 Ohms (5%) Resistor
- Wires
- Soldering iron
- Mood and patience!

### Step-by-Step

First step is wiring everything up and test to see if everything works as expected!

Follow the schematics bellow :)!

**The Keypad scheme**
![teclado](https://github.com/ArTDsL/CSPROPBOMB/assets/10051552/690a2743-e223-4d2d-af82-12281e3d5135)


**The rest of the circuit**
![csgo_lcd_bb](https://github.com/ArTDsL/CSPROPBOMB/assets/10051552/6ccc138c-eeda-48c9-8445-6f957baa0d08)


**In the end your circuit must look like this:**
![1](https://github.com/ArTDsL/CSPROPBOMB/assets/10051552/3f544d57-05dc-4cf8-94fa-8837ef7c9c3d)

OK, now we need to connect our board!

Next step will require that you have [Arduino](https://www.arduino.cc/en/software) installed, configured, and running!

- Download and/or clone the repo `git clone https://github.com/ArTDsL/CSGO2-PROP-BOMB.git`
- Open the file `CSGO2_BOMB_ARDUINO.ino` in Arduino IDE.
- Connect your board in your computer and config the COM port...

***We need to setup 3 libs to continue...***

The first lib will be **Keypad** and the Second one will be **LiquidCrystal**, and the third one will be the **ezButton**, to setup those libs go to **→ Sketch** on top menu, select "**Include Library**" then select "**Manage Libraries**", on search bar look for "**Keypad**" (without quotes) and install the version **3.1.1** by **Mark Stanley & Alexander Brevig**, after that return to the search bar and look for "**LiquidCrystal**" (without quotes) and install the version **1.0.7** by **Arduino & Adafruit**, again, return to the search bar and look for "**ezButton**" (without quotes) and install the version **1.0.4** by **ArduinoGetStarted.com**

→ **Hit the button with a arrow pointing to the right ![image](https://github.com/ArTDsL/CSPROPBOMB/assets/10051552/b60486a0-a8d7-4071-86b3-c7273f2d7170) at the left top corner** ←

**Wait until the code load's into the board**...

When the code finish load's into the board you will see a text writed on your LCD Screen "**DEACTIVATED**", if you didn't see this, don't worrie, **MAKE SURE THAT THE SWITCH LEVER IS SET TO → ON ←** before panic!

- If your lever is set to OFF, **set to ON and the text should apear**!
- **If your lever is already in 'ON'** and your **text won't show**: Means that **you wire something wrong**... **Go back and check** your wiring!

If everything is set and running that means it works! And i i'll let you and your creativity decide what to do now!

**Password:** _7355608_ (same in the game xD)

### Video

Check out my [youtube channel](https://www.youtube.com/@arth3062), i made a video building this prop xD

[![How do i create a Counter-Strike C-4 Bomb (PROP)](https://i.imgur.com/v5SlyUm.png 'How do i create a Counter-Strike C-4 Bomb (PROP)')](https://www.youtube.com/watch?v=yy5OT9nvQkc "How do i create a Counter-Strike C-4 Bomb (PROP)")

