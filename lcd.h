/* Header file for LCD */
   /* Created by Vinuthan.B */

#define LCD P2

sbit RS=P3^0;
sbit RW=P3^1;
sbit en=P3^2;



 
  
void delay(unsigned int time)
 {
  unsigned int i,j;
   for(i=0;i<time;i++)
   for(j=0;j<1275;j++);
 }

void command(unsigned char a)
 {
   LCD=a;
   RS=0;
   RW=0;
   en=1;
   delay(1);
   en=0;
 }

data1(unsigned char b)
 {
   LCD=b;
   RS=1;
   RW=0;
   en=1;
   delay(1);
   en=0;
 }

 void Initlcd()
  {
   command(0x38);	/* Initialises the LCD to 2 lines and 5*7 matrix */
   delay(10);
   command(0x0c);
   delay(10);	/* Display ON and Cursor OFF, to make cursor ON change command data to 0x0e */
  }

 void clrlcd()
  {
   	command(0x01);	 /* Clears the LCD screen */
	delay(10);
  }

 void Position(unsigned char x)
  {
   command(x);
   delay(10);
  }

 void Write(unsigned char c[])
  {
  unsigned char i;

  for(i=0;i<16;i++)
  {
   data1(c[i]);
   delay(1);
  }
  }

 
 
