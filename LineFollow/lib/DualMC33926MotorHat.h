#ifndef DualMC33926MotorShield_h
#define DualMC33926MotorShield_h

#include <pigpio.h>

class DualMC33926MotorShield
{
  public:  
    // CONSTRUCTORS
    DualMC33926MotorShield(); // Default pin selection.
    DualMC33926MotorShield(unsigned char M1DIR, unsigned char M1PWM, 
                           unsigned char M2DIR, unsigned char M2PWM, 
                           unsigned char M1E, unsigned char M2E); // User-defined pin selection. 
    
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
