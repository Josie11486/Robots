# CIM-542-Robots


<h1>The Party Meter by Josie Argento</h1>

<p> 
Questions
What is the title of your project?
Briefly explain why did you want to make this project?
Talk about what form factor/size your project would ideally be.
Explain what your input is?
Explain how a user interacts with your input, What do they do?
What components did you use?
Why did you decide to use that component?
Explain what your output is?
What components did you use?
Why did you decide to use that component?
What parts did you use?
How does your program work? (Explain your code)
Reflect on what worked/did not work?
If you had more time what would you change in your project?
</p>


<h3> Images </h3>

// 2 - Progress images
// 1 - Finished input
// 1 - Finished output
// 1 - Finished Breadboard


<h3>Video</h3>
<a href="https://youtu.be/k4vKIYBBacI">Watch here!</a>

<h3>The Code</h3>

<p>
  
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 600

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

const int analogInPin = A0;  // Analog input pin that the microfone is attached to
const int greenOutPin = 3; // Analog output pin that the green LED is attached to
const int yellowOutPin = 5; // Analog output pin that the yellow LED is attached to
const int redOutPin = 6; // Analog output pin that the red LED is attached to

int previous = 0;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
    Serial.begin(9600);
}

void loop() {
  // get the sensor value

   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   int volts = ((peakToPeak * 5.0) / 1024) * 100;  // convert to volts
 
   Serial.println(volts);
// Mic read code ends



  // read the analog in value:
  //sensorValue = analogRead(analogInPin);

  // map it to the range of the analog out:
  outputValue =   map(volts, 0,244, 0,255);

  
  if (outputValue < 50) {
    analogWrite(greenOutPin, 255);
    analogWrite(yellowOutPin, 0);
    analogWrite(redOutPin, 0);


  } else if (outputValue > 180) {
    analogWrite(greenOutPin, 255);
    analogWrite(yellowOutPin, 255);
    analogWrite(redOutPin, 0);

    
  } else if (outputValue > 220) {
    analogWrite(greenOutPin, 255);
    analogWrite(yellowOutPin, 255);
    analogWrite(redOutPin, 255);

  }

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);  
  Serial.print("\t output = ");
  Serial.println(outputValue);


  int stepperMove = map(volts, 0,244, 0,500);

// move a number of steps equal to the change in the sensor reading
 stepper.step(stepperMove - previous);
//
// remember the previous value of the sensor
  previous = stepperMove;
}
</p>
