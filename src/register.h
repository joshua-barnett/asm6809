/*

6809 register attributes

Copyright 2013-2014 Ciaran Anscomb

This file is part of asm6809.

asm6809 is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

See COPYING.GPL for redistribution conditions.

*/

#ifndef ASM6809_REGISTERS_H_
#define ASM6809_REGISTERS_H_

#include <stdint.h>

enum reg_id {
	REG_INVALID = -1,

	REG_CC = 0,
	REG_A,
	REG_B,
	REG_DP,
	REG_X,
	REG_Y,
	REG_U,
	REG_S,
	REG_PC,
	REG_D,

	REG_PCR,

	REG_E,
	REG_F,
	REG_W,
	REG_Q,
	REG_V,

	REG_MAX
};

/* Useful lookup tables.  Index by positive reg_id only. */
extern int8_t const reg_tfr_size[REG_MAX];  // -1 indicates invalid, else 8 or 16
extern int8_t const reg_tfr_nibble[REG_MAX];  // -1 indicates invalid, else 0-15
extern uint8_t const reg_stack_bit[REG_MAX];  // 0 indicates invalid, else single bit set

/*
 * These functions will only handle registers valid in the current ISA
 */

enum reg_id reg_name_to_id(const char *name);
const char *reg_id_to_name(enum reg_id id);

#endif
