#include "DualMC33926MotorHat.h"

// Constructors ////////////////////////////////////////////////////////////////

DualMC33926MotorHat::DualMC33926MotorHat()
{
  //Pin map
  _M1E = 22;
  _M1DIR = 24;
  _M2DIR = 25;
  _M2E = 23;

}

DualMC33926MotorHat::DualMC33926MotorHat(unsigned char M1DIRB, unsigned char M1PWMB, 
                                               unsigned char M2DIRB, unsigned char M2PWMB, 
                                               unsigned char M1EB, unsigned char M2EB)
{
  //Pin map
  

  _M1DIR = M1DIRB;
  _M2DIR = M2DIRB;

  _M1E = M1EB; 
  _M2E = M2EB;
}

// Public Methods //////////////////////////////////////////////////////////////
void DualMC33926MotorHat::init()
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
void DualMC33926MotorHat::setM1Speed(int speed)
{
  unsigned char reverse = 0;
 gpioWrite(_M1E,1);
  
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
void DualMC33926MotorHat::setM2Speed(int speed)
{
  unsigned char reverse = 0;
gpioWrite(_M2E,1);
  
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
void DualMC33926MotorHat::setSpeeds(int m1Speed, int m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}


