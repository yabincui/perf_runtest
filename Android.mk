#
# Copyright (C) 2015 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

common_additional_dependencies := $(LOCAL_PATH)/Android.mk $(LOCAL_PATH)/Android.build.mk

module := one_function
one_function_src_files := one_function.cpp
include $(LOCAL_PATH)/Android.build.mk

module := two_functions
two_functions_src_files := two_functions.cpp
include $(LOCAL_PATH)/Android.build.mk

module := function_loop
function_loop_src_files := function_loop.cpp
include $(LOCAL_PATH)/Android.build.mk

module := function_fork
function_fork_src_files := function_fork.cpp
include $(LOCAL_PATH)/Android.build.mk

module := function_pthread
function_pthread_src_files := function_pthread.cpp
include $(LOCAL_PATH)/Android.build.mk

module := comm_change
comm_change_src_files := comm_change.cpp
include $(LOCAL_PATH)/Android.build.mk

module := function_recursive
function_recursive_src_files := function_recursive
include $(LOCAL_PATH)/Android.build.mk