LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libVulnApp
LOCAL_SRC_FILES := VulnApp.c

LOCAL_C_INCLUDES := $(JNI_H_INCLUDE)

LOCAL_MODULE_TAGS := eng

LOCAL_LDLIBS := -llog

LOCAL_CFLAGS := -fno-stack-protector

LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)
