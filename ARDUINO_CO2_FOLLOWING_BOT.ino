//ARDUINO LINE FOLLOWING CAR//
// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //

//including the libraries
#include <AFMotor.h>

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);


void setup() {
  //begin serial communication
  Serial.begin(9600);
}

void loop() {
  //printing values of the sensors to the serial monitor
  int adc_MQ = analogRead(A0);
              //CO2 detected by CQ-125
  if (adc_MQ > 120) {
    //Forward
    motor1.run(BACKWARD);
    motor1.setSpeed(255);
    motor2.run(BACKWARD);
    motor2.setSpeed(255);
  } else if (adc_MQ < 120) {
    //turn left
    motor1.run(BACKWARD);
    motor1.setSpeed(255);
    motor2.run(FORWARD);
    motor2.setSpeed(255);
  };
  
  Serial.print("adc:");
  Serial.print(adc_MQ);

}
