#ifndef _GAME_BOY_H
#define _GAME_BOY_H

#include <linux/ioctl.h>

#define GAME_BOY_MAGIC 'q'

/* ioctls and their arguments */
#define GAME_BOY_WRITE_JOYPAD      _IOW(GAME_BOY_MAGIC, 1, uint8_t *)

#endif
