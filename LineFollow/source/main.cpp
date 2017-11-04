#include "../lib/DualMC33926MotorHat.h"

DualMC33926MotorHat md;




int main()
{



  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i); 
    
    gpioDelay(20000);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i);    
   gpioDelay(20000);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    gpioDelay(20000);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    gpioDelay(20000);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM2Speed(i);
    gpioDelay(20000);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    gpioDelay(20000);
  }

gpioTerminate();

return 0;
}

