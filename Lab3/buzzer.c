#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
//#include "switches.h"

#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

//Song notes: 
#define A 1254
#define B 1117
#define Cc 1054
#define D 939
#define E 1674
#define F 1580
#define G 2109
#define Zz 0
  
static int ABC[] = {Cc, Zz, Cc, Zz, G, Zz, G, Zz, A, Zz, A, Zz, G, Zz, F, Zz, F, Zz, E, Zz, D, Zz, D, Zz, D, Zz, D, Zz, Cc, Zz, G, Zz, G, Zz, F, Zz, E, Zz, E, Zz, D, Zz, G, Zz, G, Zz, G, Zz, F, Zz, E, Zz, E, Zz, D};
static int Twinkle[] = {G, G, G, Zz, G, Zz, G, Zz, G, Zz, G, Zz, G, Zz, F, Zz, E, Zz, E, Zz, D, Zz, D, Zz, C};
static int Drums[] = {A, Zz, A, Zz, E, E, E, E, Zz, E, E, E, G, Zz, G, Zz, F, Zz, F, Zz, D, Zz, D, Zz, D, Zz, C, C};
static int Small[] = {G, Zz, G, G, Zz, A, A, Zz, D, D, Zz, D, Zz, B, Zz, B, Zz, B};

static int n = 0; //Used to traverse throught the song array
static unsigned int period = 1000;
static signed int rate = 200;	

void buzzer_init()
{
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

//Song for button1
void buzzer1() 
{ 
  if(n == sizeof(ABC)) //If n reaches the end of the array reset your n to play from the beggining again..
  {
    n = 0;
  }
    period = ABC[n];
    buzzer_set_period(period);
    n++;
}

//Song for button2
void buzzer2() 
{
  if(n == sizeof(Twinkle))
  {
    n = 0;
  }
  
  period = Twinkle[n];
  buzzer_set_period(period);
  n++;
}

//Song for button3
void buzzer3() 
{
  if(n == sizeof(Drums))
  {
    n = 0;
  }
  
  period = Drums[n];
  buzzer_set_period(period);
  n++;
}

//Song for button4
void buzzer4() 
{
  if(n == sizeof(Small))
  {
    n = 0;
  }
  
  period = Small[n];
  buzzer_set_period(period);
  n++;
}

void buzzer_advance_frequency() 
{
  period += rate;
  if ((rate > 0 && (period > MAX_PERIOD)) || 
      (rate < 0 && (period < MIN_PERIOD))) {
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
}


void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

