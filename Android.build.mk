include $(CLEAR_VARS)
LOCAL_ADDITIONAL_DEPENDENCIES := $(common_additional_dependencies)
LOCAL_CLANG := true

LOCAL_MODULE := simpleperf_runtest_$(module)
LOCAL_CPPFLAGS := -std=c++11 -g -O0
LOCAL_SRC_FILES := $($(module)_src_files)
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)

ifeq ($(HOST_OS),linux)
include $(CLEAR_VARS)
LOCAL_ADDITIONAL_DEPENDENCIES := $(common_additional_dependencies)
LOCAL_CLANG := true

LOCAL_MODULE := simpleperf_runtest_$(module)
LOCAL_CPPFLAGS := -std=c++11 -g -O0
LOCAL_SRC_FILES := $($(module)_src_files)
LOCAL_MODULE_TAGS := optional
include $(BUILD_HOST_EXECUTABLE)
endif