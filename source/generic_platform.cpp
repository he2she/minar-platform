// Copyright (C) 2015 ARM Limited. All rights reserved.

#include "minar_platform/minar_platform.h"

#include "cmsis-core/core_generic.h"

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

