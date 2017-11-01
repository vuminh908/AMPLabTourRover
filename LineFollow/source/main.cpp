#include "DualMC33926MotorHat.h"

DualMC33926MotorShield md;




#include <stdio.h>
int main()
{if (gpioInitialise() < 0)
{
  return -1;
}



  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i); 
    
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i);    
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM2Speed(i);
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    delay(2);
  }

gpioTerminate();

return 0;
}

