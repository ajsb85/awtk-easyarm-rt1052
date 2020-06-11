﻿/**
 * File:   app_conf.c
 * Author: AWTK Develop Team
 * Brief:  config for application
 *
 * Copyright (c) 2020 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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
 * 2020-05-31 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mutex.h"
#include "conf_io/app_conf.h"

static object_t* s_conf;
static tk_mutex_t* s_conf_lock;

ret_t app_conf_set_instance(object_t* obj) {
  return_value_if_fail(s_conf == NULL, RET_BAD_PARAMS);
  return_value_if_fail(obj != NULL, RET_BAD_PARAMS);

  s_conf = obj;
  s_conf_lock = tk_mutex_create();
  ENSURE(s_conf_lock != NULL);

  return RET_OK;
}

object_t* app_conf_get_instance(void) {
  return s_conf;
}

ret_t app_conf_save(void) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = object_exec(s_conf, "save", NULL);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_deinit(void) {
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  OBJECT_UNREF(s_conf);
  tk_mutex_unlock(s_conf_lock);
  tk_mutex_destroy(s_conf_lock);
  s_conf_lock = NULL;

  return RET_OK;
}

ret_t app_conf_set(const char* key, const value_t* v) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(key != NULL && v != NULL, RET_BAD_PARAMS);
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = object_set_prop(s_conf, key, v);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_get(const char* key, value_t* v) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(key != NULL && v != NULL, RET_BAD_PARAMS);
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = object_get_prop(s_conf, key, v);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

bool_t app_conf_exist(const char* key) {
  bool_t ret = FALSE;
  return_value_if_fail(key != NULL, FALSE);
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, FALSE);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = object_has_prop(s_conf, key);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_set_int(const char* key, int32_t v) {
  value_t value;
  value_set_int32(&value, v);

  return app_conf_set(key, &value);
}

ret_t app_conf_set_int64(const char* key, int64_t v) {
  value_t value;
  value_set_int64(&value, v);

  return app_conf_set(key, &value);
}

ret_t app_conf_set_bool(const char* key, bool_t v) {
  value_t value;
  value_set_bool(&value, v);

  return app_conf_set(key, &value);
}

ret_t app_conf_set_double(const char* key, double v) {
  value_t value;
  value_set_double(&value, v);

  return app_conf_set(key, &value);
}

ret_t app_conf_set_str(const char* key, const char* v) {
  value_t value;
  value_set_str(&value, v);

  return app_conf_set(key, &value);
}

int32_t app_conf_get_int(const char* key, int32_t defval) {
  value_t value;

  if (app_conf_get(key, &value) == RET_OK) {
    defval = value_int(&value);
  }

  return defval;
}

int64_t app_conf_get_int64(const char* key, int64_t defval) {
  value_t value;

  if (app_conf_get(key, &value) == RET_OK) {
    defval = value_int64(&value);
  }

  return defval;
}

bool_t app_conf_get_bool(const char* key, bool_t defval) {
  value_t value;

  if (app_conf_get(key, &value) == RET_OK) {
    defval = value_bool(&value);
  }

  return defval;
}

double app_conf_get_double(const char* key, double defval) {
  value_t value;

  if (app_conf_get(key, &value) == RET_OK) {
    defval = value_double(&value);
  }

  return defval;
}

const char* app_conf_get_str(const char* key, const char* defval) {
  value_t value;

  if (app_conf_get(key, &value) == RET_OK) {
    defval = value_str(&value);
  }

  return defval;
}

uint32_t app_conf_on_changed(event_func_t on_event, void* ctx) {
  uint32_t ret = TK_INVALID_ID;
  return_value_if_fail(on_event != NULL, ret);
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, ret);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, ret);
  ret = emitter_on(EMITTER(s_conf), EVT_PROP_CHANGED, on_event, ctx);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_off_changed(uint32_t id) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = emitter_off(EMITTER(s_conf), id);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_off_changed_by_ctx(void* ctx) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = emitter_off_by_ctx(EMITTER(s_conf), ctx);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}

ret_t app_conf_remove(const char* key) {
  ret_t ret = RET_FAIL;
  return_value_if_fail(s_conf != NULL && s_conf_lock != NULL, RET_BAD_PARAMS);

  return_value_if_fail(tk_mutex_lock(s_conf_lock) == RET_OK, RET_BAD_PARAMS);
  ret = object_remove_prop(s_conf, key);
  tk_mutex_unlock(s_conf_lock);

  return ret;
}
