#include <main.h>
#use fast_io(b)

#define LCD_ENABLE_PIN  PIN_B2
#define LCD_RS_PIN      PIN_B0
#define LCD_RW_PIN      PIN_B1
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7

#include <lcd.c>

#use rs232 (baud=9600, xmit=pin_C6, rcv=pin_C7, parity=N, stop = 1,errors)
char klavye[80];

#int_rda
void serial_interrupt(){   
   output_high(pin_c5);
   gets(klavye); 
   printf(lcd_putc,"\f%s",klavye);
   

}


void setup();

void main()
{  
   
   setup();
   
   while(True)
   {
   printf("AT\r\n");
   delay_ms(2000);
   output_high(pin_c5);
   }
}

void setup(){
     
   set_tris_b(0x00);
   output_low(pin_c5);
   lcd_init();
   enable_interrupts(GLOBAL);
   enable_interrupts(int_rda);
   
}

