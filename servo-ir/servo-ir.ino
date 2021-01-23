//www.elegoo.com
//2018.12.19
#include <Servo.h>
#include "IRremote.h"
#include "IR.h"
/* After including the corresponding libraries,
   we can use the "class" like "Servo" created by the developer for us.
   We can use the functions and variables created in the libraries by creating 
   objects like the following "myservo" to refer to the members in ".".*/

Servo myservo;
//it created an object called myservo.

int receiver = 3;

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'
/*  you can see Servo as a complex date type(Including functions and various data types)
    and see myservo as variables.               */

void setup(){
  /*"attach" and "write" are both functions,
     and they are members contained in the complex structure of "Servo". 
     We can only use them if we create the object "myservo" for the complex structure of "Servo".
  */
  myservo.attach(9);//connect pin 9 with the control line(the middle line of Servo) 
  myservo.write(90);// move servos to center position -> 90°
  irrecv.enableIRIn(); // Start the receiver.
} 
void loop(){
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    if (results.value == KEY_0) {
      myservo.write(30);
    }
    if (results.value == KEY_1) {
      myservo.write(135);
    }

    irrecv.resume();
  }
}
