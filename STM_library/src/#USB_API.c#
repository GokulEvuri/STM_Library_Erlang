#include "ch.h"
#include "hal.h"
#include "chprintf.h"


void send(BaseSequentialStream *chp, uint8_t data){
   chSequentialStreamPut(chp,data);
}

uint8_t receive(BaseSequentialStream *chp){
  return (uint8_t) chSequentialStreamGet(chp);
}


void send_bulk(BaseSequentialStream *chp, uint8_t *data, int8_t bytes){

  chSequentialStreamWrite(chp,data,bytes);

}


/******/
 /* Until specified no.of bytes are available this method will return nothing  */
 /* Possible dead lock in system, use it carefully. */
/******/

uint8_t * receive_bulk(BaseSequentialStream *chp, uint8_t * receiveBuffer,int8_t bytes){

  chSequentialStreamRead(chp,receiveBuffer,bytes);
 
  return  receiveBuffer;
}
