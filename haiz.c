//#include "D:\Proteus 8.8\pic16f887\final-test\haiz.h"


#include <16F887.h>
#device ADC = 10
#fuses HS,NOWDT,NOPROTECT,NOLVP                       
#use delay(clock = 8MHz)
#use rs232(UART1, baud = 9600)
//#use fast_io(D)
//#define DHT11_PIN PIN_D4  
float pot;
void main()
{
  set_tris_a(0xFF);
 //set_tris_b(0x00);
 //set_tris_c(0x00);
  setup_oscillator(OSC_8MHZ);                    // Set the internal oscillator to 8MHz
  setup_adc(ADC_CLOCK_INTERNAL);                 // ADC Module uses its internal oscillator
  setup_adc_ports(sAN0);                         // Configure AN0 pin as analog
  set_adc_channel(0);  
  printf("CLEARDATA\r\n");                             // Clear all Excel sheet data
  // Label columns: A for date, B for time, C for temperature and D for humidity
  printf("LABEL, Time, Started Time, Date, Analog Value\r\n");
 
  while(TRUE) {
    pot = read_adc();
    printf("DATA, TIME, TIMER, DATE, ");                         // Write date and time on row A and row B respectively
    
    printf("%f \r\n",pot);
    delay_ms(1000);
}
}
