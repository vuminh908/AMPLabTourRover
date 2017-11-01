#ifndef DualMC33926MotorHat_h
#define DualMC33926MotorHat_h

#include <pigpio.h>

class DualMC33926MotorHat
{
  public:  
    // CONSTRUCTORS
    DualMC33926MotorHat(); // Default pin selection.
    DualMC33926MotorHat(unsigned char M1DIRB, unsigned char M1PWMB, 
                           unsigned char M2DIRB, unsigned char M2PWMB, 
                           unsigned char M1EB, unsigned char M2EB); // User-defined pin selection. 
    
    // PUBLIC METHODS
    void init(); // Initialize TIMER 1, set the PWM to 20kHZ. 
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.

    
    
  private:
    unsigned char _M1E;
    unsigned char _M1DIR;
    unsigned char _M2DIR;
    static const unsigned char _M1PWM = 12;
    static const unsigned char _M2PWM = 13;
    unsigned char _M2E;

};

#endif
