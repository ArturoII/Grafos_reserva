/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class libgrafos_grafos */

#ifndef _Included_libgrafos_grafos
#define _Included_libgrafos_grafos
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     libgrafos_grafos
 * Method:    createRoom
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_libgrafos_grafos_createRoom
  (JNIEnv *, jobject, jstring);

/*
 * Class:     libgrafos_grafos
 * Method:    assign_room
 * Signature: (Ljava/lang/String;)Ljava/lang/Boolean;
 */
JNIEXPORT jobject JNICALL Java_libgrafos_grafos_assign_1room
  (JNIEnv *, jobject, jstring);

/*
 * Class:     libgrafos_grafos
 * Method:    showRooms
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_libgrafos_grafos_showRooms
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif