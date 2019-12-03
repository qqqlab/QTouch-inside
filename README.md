# QTouch-inside
QTouch capacitor measurement

## What is this
A small test of Atmel's QTouch closed source library to see if it can be used to measure capacity of a capacitor. Various capacitors were connected to a single ended button QTouch input pin and the QTouch output recorded. As QTouch recalibrates itself, it is difficult to relate the output back to a capacitor value. It appears that the cc_val value is more or less useful after calibration to measure capacitance up to 21 pF.

## Results
![Graph](/doc/graph.png)
