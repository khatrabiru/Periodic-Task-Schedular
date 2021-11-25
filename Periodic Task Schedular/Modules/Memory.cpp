//
//  Memory.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include "Memory.hpp"
#include <mach/mach.h>

long getMemoryUsage(){
    struct task_basic_info t_info;
    mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

    if (KERN_SUCCESS != task_info(mach_task_self(),
                                  TASK_BASIC_INFO, (task_info_t)&t_info,
                                  &t_info_count)) {
        return -1;
    }

    return t_info.resident_size;
}

