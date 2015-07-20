// Copyright (C) 2013 ARM Limited. All rights reserved.

#ifndef __MINAR_PLATFORM_MINAR_PLATFORM_H__
#define __MINAR_PLATFORM_MINAR_PLATFORM_H__

#include <stdint.h>
#include "minar-platform/minar_platform_types.h"

namespace minar {
namespace platform {

/// @name Initialisation
void init();


/// @name Energy Management
void sleep();
void sleepFromUntil(tick_t now, tick_t until);


/// @name Time
tick_t getTime();
uint32_t getTimeOverflows();
uint32_t getTimeInMilliseconds();

/// @name IRQ State Management
irqstate_t pushDisableIRQState();
void popDisableIRQState(irqstate_t);

}; // namespace platform
}; // namespace minar

#endif // ndef __MINAR_PLATFORM_MINAR_PLATFORM_H__
