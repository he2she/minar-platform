// Copyright (C) 2015 ARM Limited. All rights reserved.

#include "minar_platform/minar_platform.h"

#define __CMSIS_GENERIC
#if defined(TARGET_LIKE_CORTEX_M3)
  #include "cmsis-core/core_cm3.h"
#elif defined(TARGET_LIKE_CORTEX_M4)
  #include "cmsis-core/core_cm4.h"
#else
  #error MINAR is only supported on Cortex-M3 and Cortex-M4 MCUs at the moment
#endif

namespace minar {
namespace platform {

irqstate_t pushDisableIRQState() {
    uint32_t ret = __get_PRIMASK();
    __disable_irq();
    return (irqstate_t)ret;
}

void popDisableIRQState(irqstate_t restore){
    __set_PRIMASK((uint32_t)restore);
}

}; // namespace platform
}; // namespace minar

