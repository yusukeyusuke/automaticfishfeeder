#include <Wire.h>
#include <MsTimer2.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  530
#define SERVOMAX  610

uint8_t servonum = 0;
uint8_t doFeed = 1;
uint8_t now = 15;

void setup() {
  Serial.begin(9600);
  Serial.println("Auto Feeders Servo!");

  MsTimer2::set(3600000UL, flagtimer);
  MsTimer2::start();
  pwm.begin();
  pwm.setPWMFreq(60);
  yield();
}

void flagtimer() {
  now++;
  if(now == 24){
    now = 0;
  }
  if(now == 9 || now == 15) {
    doFeed = 1;
  }
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  while(doFeed == 0) {
    delay(1000);
  }
  
  doFeed = 0;

  servonum = 0;
  Serial.println(servonum);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(1500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(500);
    
  servonum = 1;
  Serial.println(servonum);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(1500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(500);
}
