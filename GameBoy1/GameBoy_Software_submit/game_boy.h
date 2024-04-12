#ifndef _GAME_BOY_H
#define _GAME_BOY_H

#include <linux/ioctl.h>

#define GAME_BOY_MAGIC 'q'

/* ioctls and their arguments */
#define GAME_BOY_SEND_JOYPAD_STATUS      _IOW(GAME_BOY_MAGIC, 1, uint8_t *)

#endif
