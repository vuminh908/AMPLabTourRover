#include "DualMC33926MotorHat.h"

// Constructors ////////////////////////////////////////////////////////////////

DualMC33926MotorShield::DualMC33926MotorShield()
{
  //Pin map
  _M1E = 22;
  _M1DIR = 24;
  _M2DIR = 25;
  _M2E = 23;

}

DualMC33926MotorShield::DualMC33926MotorShield(unsigned char M1DIR, unsigned char M1PWM, 
                                               unsigned char M2DIR, unsigned char M2PWM, 
                                               unsigned char M2E, unsigned char M2E)
{
  //Pin map
  

  _M1DIR = M1DIR;
  _M2DIR = M2DIR;

  _M1E = M1E; 
  _M2E = M2E;
}

// Public Methods //////////////////////////////////////////////////////////////
void DualMC33926MotorShield::init()
{
// Define pinMode for the pins and set the frequency for timer1.

  gpioSetMode(_M1DIR,PI_OUTPUT);
  gpioSetMode(_M1PWM,PI_OUTPUT);
  gpioSetMode(_M1E,PI_OUTPUT);
  gpioSetMode(_M2DIR,PI_OUTPUT);
  gpioSetMode(_M2PWM,PI_OUTPUT);
  gpioSetMode(_M2E,PI_OUTPUT);
 gpioSetPWMfrequency(_M1PWM, 20000); // Set GPIO24 to 20000Hz.
 gpioSetPWMfrequency(_M2PWM, 20000); // Set GPIO24 to 20000Hz.


 
}
// Set speed for motor 1, speed is a number betwenn -400 and 400
void DualMC33926MotorShield::setM1Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  
  gpioPWM(_M1PWM,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255

  if (reverse)
    gpioWrite(_M1DIR,1);
  else
    gpioWrite(_M1DIR,0);
}

// Set speed for motor 2, speed is a number betwenn -400 and 400
void DualMC33926MotorShield::setM2Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
 
  gpioPWM(_M2PWM,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255

  if (reverse)
    gpioWrite(_M2DIR,1);
  else
    gpioWrite(_M2DIR,0);
}

// Set speed for motor 1 and 2
void DualMC33926MotorShield::setSpeeds(int m1Speed, int m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}


