#ifndef USB_H_INCLUDED
#define USB_H_INCLUDED

extern SerialUSBDriver SDU1;

void myUSBinit(void);
int isUsbActive(void);

#endif // USB_H_INCLUDED
