# Arduino-up_and_down
this is the project about the arduino which controls the machine up and down.


### Step 1 : Install IRremote library

Download the zip from [GitHub - IRremote](https://github.com/z3t0/Arduino-IRremote) and add to the Arduino IDLE library.

### Step 2 : Get IRremote code

Connect the IR receiver to `pin 11` on the Arduion board and upload `readIR.pde`

Open the `serial monitor` in IDLE, then press the `up` and `down` button on the IR Controller. The result will show on the monitor window.

### Step 3 : Set parameter

Copy the hex code get from `Step 2` and paste it in `sketch.pde`.
