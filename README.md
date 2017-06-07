# LEDProgress

Simulate a progress bar using several LEDs.

Create an instance of the class using the *LEDProgress* constructor, telling how many LEDs you have, their pins and maximum progress. Progress can then be changed using the *setProgress()* function, and checked with the *getProgress()* function.

The below example shows what the constructor expects to set up 4 LEDs as a progress meter, with maximum progress 100. If the LEDs are connected to PWM pins, they will be partially light up, so this code excerpt would light up the first two LEDs fully and the third partially, leaving the fourth untouched.

```c
int leds[4] = {6,9,10,11};
int nleds = 4;
int maxprogress = 100;

LEDProgress ledprogress(leds, nleds, 100);

ledprogress.setProgress(60);
```

