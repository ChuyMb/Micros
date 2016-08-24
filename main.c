#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */




interrupt 12 void MTIM(void){
	(void)MTIMSC; //cast al vacio,
	MTIMSC_TOF=0;//apagar bandera
	PTBD_PTBD7=!PTBD_PTBD7;
	
}




void main(void) {
	EnableInterrupts;
  /* include your code here */
	MTIMSC_TOIE=1;//habilitador local
  PTBDD_PTBDD7=1; //Salida del led de la tarjeta
  MTIMCLK=0b00000100;
  MTIMSC_TSTP=0;
  MTIMMOD=250;// comparador
  

  for(;;) {
	  
	  __RESET_WATCHDOG();
		
	  
  } /* loop forever */
}
