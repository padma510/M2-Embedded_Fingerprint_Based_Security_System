#include<avr/io.h>
#include<util/delay.h>
#include<uart.h>
#include<lcd.h>
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
      make_template();  //makes the template with info in char_buffer1 & char_buffer2 and stores it in char_buffer
      check_finger();         //checks for the finger authentication
//    store(0);               //stores the scanned value to the given parametric location in flash library
//    empty();                //empties the flash library

}

 

   
