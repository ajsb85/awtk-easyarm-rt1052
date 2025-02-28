﻿/**
 * File:   thread.c
 * Author: AWTK Develop Team
 * Brief:  thread on rtthread
 *
 * Copyright (c) 2018 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2020-06-08 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "tkc/thread.h"
#include "tkc/mutex.h"

tk_thread_t* tk_thread_create(tk_thread_entry_t entry, void* args) 
{
  return NULL;
}

ret_t tk_thread_set_name(tk_thread_t* thread, const char* name) {
  return RET_NOT_IMPL;
}

ret_t tk_thread_set_stack_size(tk_thread_t* thread, uint32_t stack_size) 
{
  return RET_NOT_IMPL;
}

ret_t tk_thread_set_priority(tk_thread_t* thread, uint32_t priority)
{
  return RET_NOT_IMPL;
}

ret_t tk_thread_start(tk_thread_t* thread) 
{
  return RET_NOT_IMPL;
}

ret_t tk_thread_join(tk_thread_t* thread) 
{
  return RET_NOT_IMPL;
}

void* tk_thread_get_args(tk_thread_t* thread) 
{
  return NULL;
}

ret_t tk_thread_destroy(tk_thread_t* thread) 
{
  return RET_NOT_IMPL;
}
