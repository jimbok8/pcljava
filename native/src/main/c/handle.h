#include <jni.h>

#ifndef HANDLE_H
#define HANDLE_H

inline jfieldID getHandleField(JNIEnv *env, jobject obj) 
{
	jclass cls = env->GetObjectClass(obj);

	return env->GetFieldID(cls, "handle", "J");
}

template <typename T>
inline T *getHandle(JNIEnv *env, jobject obj) 
{
	jlong handle = env->GetLongField(obj, getHandleField(env, obj));

	return reinterpret_cast<T *>(handle);
}

template <typename T>
inline void setHandle(JNIEnv *env, jobject obj, T *ptr) 
{
	jlong handle = reinterpret_cast<jlong>(ptr);

	env->SetLongField(obj, getHandleField(env, obj), handle);
}

#endif