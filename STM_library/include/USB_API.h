#ifndef USB_API_H_INCLUDED
#define USB_API_H_INCLUDED

void send(BaseSequentialStream *chp, uint8_t data);

uint8_t receive(BaseSequentialStream *chp);

/* DataBuffer to be sent to the stream -> data  */
void send_bulk(BaseSequentialStream *chp, uint8_t *data, int8_t bytes);

/*****/
 /* bytes -> no. of bytes to be received */
 /* receiveBuffer -> buffer to be filled in received data to */
 /* bytes should be always less than size of receiveBuffer  */

 /* Until specified no.of bytes are available this method will return nothing  */
 /* Possible dead lock in system, use it carefully. */
/******/

uint8_t * receive_bulk(BaseSequentialStream *chp, uint8_t * receiveBuffer,int8_t bytes);


#endif // USB_API_H_INCLUDED
