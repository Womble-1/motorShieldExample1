//tracking in GitHub
//Pulse Width Modulation (PWM) 

//
//Rotates motor Clockwise and Counter Clockwise
//Motor 1 using pointers as suggested here: https://github.com/wemos/WEMOS_Motor_Shield_Arduino_Library/issues/2 
//Motor 2 as per the Wemos Example. 
// have not made this change to the library:  https://github.com/wemos/WEMOS_Motor_Shield_Arduino_Library/pull/3

#include <WEMOS_Motor.h>
#include <Wire.h>

int pwm;
Motor *M1 = NULL;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)

Motor M2(0x30,_MOTOR_B, 1000);//Motor B


void setup() {
  Serial.begin(250000);
  M1 = new Motor (0x30,_MOTOR_A, 1000);//Motor A
}

void loop() {

  for (pwm = 0; pwm <= 100; pwm++)
  {
    M1->setmotor( _CW, pwm);
    M2.setmotor(_CW, 100-pwm);
    Serial.printf("A:%d%, B:%d%, DIR:CW\r\n", pwm,100-pwm);
  }
  
  M1->setmotor(_STOP);
  M2.setmotor( _STOP);
  Serial.println("Motor A&B STOP");
  delay(200);
  
  for (pwm = 0; pwm <=100; pwm++)
  {
    M1->setmotor(_CCW, pwm);
    M2.setmotor(_CCW, 100-pwm);
    Serial.printf("A:%d%, B:%d%, DIR:CCW\r\n", pwm,100-pwm);

  }
  
  M1->setmotor(_STOP);
  M2.setmotor( _STOP);
  delay(200);
  Serial.println("Motor A&B STOP");

  M1->setmotor(_SHORT_BRAKE);
  M2.setmotor( _SHORT_BRAKE);
  Serial.println("Motor A&B SHORT BRAKE");  
  delay(1000);
  
  M1->setmotor(_STANDBY);//Both Motor standby
  M2.setmotor( _STANDBY);
  Serial.println("Motor A&B STANDBY");  
  delay(1000);
  
}
