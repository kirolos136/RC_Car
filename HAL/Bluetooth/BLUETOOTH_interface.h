#ifndef BLUETOOTH_INTERFACE_H
#define BLUETOOTH_INTERFACE_H
#include "../../LIB/std_types.h"

typedef enum {BLUETOOTH_OK , BLUETOOTH_NOK} bluetoothErrorStatus;

bluetoothErrorStatus bluetooth_init(void);

bluetoothErrorStatus bluetooth_sendByte(u8 byte);

bluetoothErrorStatus bluetooth_receiveByte(u8* ptr_byte);

#endif