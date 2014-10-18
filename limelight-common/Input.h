#pragma once

#pragma pack(push, 1)

typedef struct _NV_INPUT_HEADER {
	int packetType;
} NV_INPUT_HEADER, PNV_INPUT_HEADER;

#define PACKET_TYPE_KEYBOARD 0x0A
typedef struct _NV_KEYBOARD_PACKET {
	NV_INPUT_HEADER header;
	char keyAction;
	int zero1;
	short keyCode;
	char modifiers;
	short zero2;
} NV_KEYBOARD_PACKET, *PNV_KEYBOARD_PACKET;

#define PACKET_TYPE_MOUSE_MOVE 0x08
#define MOUSE_MOVE_MAGIC 0x06000000
typedef struct _NV_MOUSE_MOVE_PACKET {
	NV_INPUT_HEADER header;
	int magic;
	short deltaX;
	short deltaY;
} NV_MOUSE_MOVE_PACKET, *PNV_MOUSE_MOVE_PACKET;

#define PACKET_TYPE_MOUSE_BUTTON 0x05
typedef struct _NV_MOUSE_BUTTON_PACKET {
	NV_INPUT_HEADER header;
	char action;
	int button;
} NV_MOUSE_BUTTON_PACKET, *PNV_MOUSE_BUTTON_PACKET;

#define PACKET_TYPE_CONTROLLER 0x18
#define HEADER_A 0x0000000A
#define HEADER_B 0x1400
#define TAIL_A 0x0000009C
#define TAIL_B 0x0055
typedef struct _NV_CONTROLLER_PACKET {
	NV_INPUT_HEADER header;
	int headerA;
	short headerB;
	short buttonFlags;
	char leftTrigger;
	char rightTrigger;
	short leftStickX;
	short leftStickY;
	short rightStickX;
	short rightStickY;
	int tailA;
	short tailB;
} NV_CONTROLLER_PACKET, *PNV_CONTROLLER_PACKET;

#define PACKET_TYPE_SCROLL 0xA
#define MAGIC_A 0x09
typedef struct _NV_SCROLL_PACKET {
	NV_INPUT_HEADER header;
	char magicA;
	char zero1;
	short zero2;
	short scrollAmt1;
	short scrollAmt2;
	short zero3;
} NV_SCROLL_PACKET, *PNV_SCROLL_PACKET;

#pragma pack(pop)