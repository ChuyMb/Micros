#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

unsigned char arreglo[] = {0x0E, 0x0D, 0x0B, 0x07}; //char para 8 bits
unsigned char j;

interrupt 23 void RTI_ISR(void){
		
		PTBD = arreglo[j];
		if(PTAD_PTAD2 == 0){
			j++;
			if(j==4)
				j=0;
		}else{
			j--;
			if(j==255) //le dimos la vuelta al rango de 0 a 255 de los 8 bits de j
				j=3;
			
		}
		SRTISC_RTIACK=1;
}




void main(void) {
  /* include your code here */
  PTBDD =  0x0F; //del 0 al 3 son salidas, y del 4 al 7 son entradas
  PTAPE_PTAPE2 = 1;
  SRTISC=0b00010110;
  j=0;
 
  for(;;) {
	  
	  __RESET_WATCHDOG();
		
		

  } /* loop forever */
}
