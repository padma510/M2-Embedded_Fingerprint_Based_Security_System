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

 
