/*
 *
 * Copyright (c) 2015, alipay.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * 	art_method_replace.cpp
 *
 * @author : sanping.li@alipay.com
 *
 */
#include <time.h>
#include "art.h"
#include <android/log.h>

static int apilevel;

static size_t getMethodSize(JNIEnv* env) {
	jclass cls = env->FindClass("com/lionel/andfix2/library/NativeStructsModel");
	size_t methodIdFirst = (size_t) env->GetStaticMethodID(cls, "f1", "()V");
	size_t methodIdSecond = (size_t) env->GetStaticMethodID(cls, "f2", "()V");
	size_t methodSize = methodIdSecond - methodIdFirst;
    __android_log_print(ANDROID_LOG_ERROR, "AndFixJni", "method size: %ld", methodSize);
	return methodSize;
}

static void replace_method_wholy(JNIEnv* env, jobject src, jobject dest) {
	jmethodID src_method = env->FromReflectedMethod(src);
	jmethodID dest_method =  env->FromReflectedMethod(dest);
	memcpy(src_method, dest_method, getMethodSize(env));
}

extern jboolean __attribute__ ((visibility ("hidden"))) art_setup(JNIEnv* env,
		int level) {
	apilevel = level;
	return JNI_TRUE;
}

extern void __attribute__ ((visibility ("hidden"))) art_replaceMethod(
		JNIEnv* env, jobject src, jobject dest) {

/*
	replace_method_wholy(env, src, dest);
    return;
*/

    if (apilevel > 23) {
        replace_7_0(env, src, dest);
    } else if (apilevel > 22) {
		replace_6_0(env, src, dest);
	} else if (apilevel > 21) {
		replace_5_1(env, src, dest);
	} else if (apilevel > 19) {
		replace_5_0(env, src, dest);
    }else{
        replace_4_4(env, src, dest);
    }
}

extern void __attribute__ ((visibility ("hidden"))) art_setFieldFlag(
		JNIEnv* env, jobject field) {
    if (apilevel > 23) {
        setFieldFlag_7_0(env, field);
    } else if (apilevel > 22) {
		setFieldFlag_6_0(env, field);
	} else if (apilevel > 21) {
		setFieldFlag_5_1(env, field);
	} else  if (apilevel > 19) {
		setFieldFlag_5_0(env, field);
    }else{
        setFieldFlag_4_4(env, field);
    }
}

