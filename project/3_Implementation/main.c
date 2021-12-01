#include<avr/io.h>

#include<util/delay.h>

#include<uart.h>

#include<lcd.h>

 

void read_finger_1()          //for char_buffer1

{

      int i=0;

      char k=1,ch=1;

 

      sendchar_uart(239);

      sendchar_uart(1);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(3);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(5);

 

      for(i=0;i<10;i++)

      {

            k=getchar_uart();

            if(i==9)

            {

                  ch=k;

                  k=getchar_uart();

                  k=getchar_uart();

                  if(ch==0x00)

                  {

                        PORTC|=(1<<0);

                        k=1;

                        sendchar_uart(239);

                        sendchar_uart(1);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(1);

                        sendchar_uart(0);

                        sendchar_uart(4);

                        sendchar_uart(2);

                        sendchar_uart(1);

                        sendchar_uart(0);

                        sendchar_uart(8);

                        i=0;

                        for(i=0;i<10;i++)

                        {

                              k=getchar_uart();

                              if(i==9)

                              {

                                    ch=k;

                                    k=getchar_uart();

                                    k=getchar_uart();

                                    if(ch==0x00)

                                    {

                                          PORTC|=(1<<1);

                                    }

                              }

                        }

                  }

            }

      }

}

 

void read_finger_2()          //for char_buffer2

{

      int i=0;

      char k=1,ch=1;

 

      sendchar_uart(239);

      sendchar_uart(1);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(3);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(5);

 

      for(i=0;i<10;i++)

      {

            k=getchar_uart();

            if(i==9)

            {

                  ch=k;

                  k=getchar_uart();

                  k=getchar_uart();

                  if(ch==0x00)

                  {

                        PORTC|=(1<<2);

                        k=1;

                        sendchar_uart(239);

                        sendchar_uart(1);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(255);

                        sendchar_uart(1);

                        sendchar_uart(0);

                        sendchar_uart(4);

                        sendchar_uart(2);

                        sendchar_uart(2);

                        sendchar_uart(0);

                        sendchar_uart(9);

                        i=0;

                        for(i=0;i<10;i++)

                        {

                              k=getchar_uart();

                              if(i==9)

                              {

                                    ch=k;

                                    k=getchar_uart();

                                    k=getchar_uart();

                                    if(ch==0x00)

                                    {

                                          PORTC|=(1<<3);

                                    }

                              }

                        }

                  }

            }

      }

}

 

void make_template()

{

      int i=0;

      char k=1,ch=1;

 

      k=1;

      sendchar_uart(239);

      sendchar_uart(1);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(3);

      sendchar_uart(5);

      sendchar_uart(0);

      sendchar_uart(9);

 

      for(i=0;i<10;i++)

      {

            k=getchar_uart();

            if(i==9)

            {

                  ch=k;

                  k=getchar_uart();

                  k=getchar_uart();

                  if(ch==0x00)

                        PORTC|=(1<<4);

            }

      }

 

}

 

void check_finger()

{

int i=0;

char k=1,ch=1;

 

sendchar_uart(239);

sendchar_uart(1);

sendchar_uart(255);

sendchar_uart(255);

sendchar_uart(255);

sendchar_uart(255);

sendchar_uart(1);

sendchar_uart(0);

sendchar_uart(8);

sendchar_uart(4);

sendchar_uart(1);

sendchar_uart(0);

sendchar_uart(0);

sendchar_uart(0);

sendchar_uart(10);

sendchar_uart(0);

sendchar_uart(24);

 

for(i=0;i<10;i++)

      {

            k=getchar_uart();

            if(i==9)

            {

                  ch=k;

                  k=getchar_uart();

                  k=getchar_uart();

                  k=getchar_uart();

                  k=getchar_uart();

                  k=getchar_uart();

                  k=getchar_uart();

                  LCDclr();

                  if(ch==0x00)

                        {

                              PORTC|=(1<<5);

                              LCDdisplay("FINGER FOUND");

                        }

                  else

                        LCDdisplay("FINGER NOT FOUND");

            }

      }

}

 

void store(int ID)

{

      int i=0,sum=14+ID;

      char k=1,ch=1;

   sendchar_uart(239);

      sendchar_uart(1);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(6);

      sendchar_uart(6);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(ID);

      sendchar_uart(0);//C

      sendchar_uart(sum);//C

 

      for(i=0;i<10;i++)

            {

                  k=getchar_uart();

                  if(i==9)

                  {

                        ch=k;

                        k=getchar_uart();

                        k=getchar_uart();

                        if(ch==0x00)

                              PORTC|=(1<<6);

                  }

            }

}

 

void empty()

{

      int i=0;

      char k=1,ch=1;

 

      sendchar_uart(239);

      sendchar_uart(1);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(255);

      sendchar_uart(1);

      sendchar_uart(0);

      sendchar_uart(3);

      sendchar_uart(13);

      sendchar_uart(0);

      sendchar_uart(17);

 

      for(i=0;i<10;i++)

            {

                  k=getchar_uart();

                  if(i==9)

                  {

                        ch=k;

                        k=getchar_uart();

                        k=getchar_uart();

                        if(ch==0x00)

                              PORTC|=(1<<7);

                  }

            }

}

 

void main()

{

      DDRC=0xff;

      PORTC=0;

 

      enable_uart(9600);

      LCDinit();

      LCDclr();

      _delay_ms(5000);  //plenty of delay for modules initialization

      LCDdisplay("Scanning.....");

      read_finger_1();  //scans and stores in char_buffer1

      read_finger_2();  //scans and stores in char_buffer2

      make_template();  //makes the template with info in char_buffer1 & char_buffer2 and stores it in char_buffer1

      check_finger();         //checks for the finger authentication

//    store(0);               //stores the scanned value to the given parametric location in flash library

//    empty();                //empties the flash library

}

 

   
