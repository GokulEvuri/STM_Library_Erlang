// Example module to show initiation of USB_API functions to send and receive single byte values from SerialUSBDriver

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"


#include "USB.h"

#include "USB_API.h"

int main(void) {

  uint8_t * usbreceiveBuffer[?Size];
  uint8_t * usbsendBuffer[?Size];
  
  halInit();
  chSysInit();

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   */
  myUSBinit();
 
  while(TRUE){
    receive_bulk((BaseSequentialStream *)&SDU1,usbreceiveBuffer,2);
    if(compare_data(usbreceiveBuffer,STARTBYTE)){
      while (TRUE) { 
	if (getinterrupt() == 0){
	getSensorData(usbsendBuffer);
	send_bulk(usbsendBuffer,?size);
	receive_bulk((BaseSequentialStream *)&SDU1,usbreceiveBuffer,2);
	control_motors(usbreceiveBuffer);
	} // interrupt from user radio
	
	else{
	  send((BaseSequentialStream *)&SDU1,'I');
	}

      }
    } // in operation


  }// main while loop
}

