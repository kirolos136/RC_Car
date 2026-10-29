#ifndef BLUETOOTH_INTERFACE_H
#define BLUETOOTH_INTERFACE_H
#include "../../LIB/std_types.h"

typedef enum {BLUETOOTH_OK , BLUETOOTH_NOK , BLUETOOTH_NO_DATA} bluetoothErrorStatus;

bluetoothErrorStatus bluetooth_init(void);

bluetoothErrorStatus bluetooth_sendByte(u8 byte);

bluetoothErrorStatus bluetooth_receiveByte(u8* ptr_byte);

bluetoothErrorStatus bluetooth_receiveByteNonBlocking(u8* ptr_byte);

#endif