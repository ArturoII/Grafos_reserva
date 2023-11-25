#include "grafos.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <jni.h>
#include "libgrafos_grafos.h"
#include "cJSON.h"

struct Room rooms[MAX_ROOMS];
struct Reservation reservations[MAX_RESERVATIONS];

int num_rooms = 0;
int num_reservations = 0;

JNIEXPORT void JNICALL Java_libgrafos_grafos_createRoom(JNIEnv *env, jobject obj, jstring jsonstring) {
    const char *jsonString = (*env)->GetStringUTFChars(env, jsonstring, NULL);

    cJSON *json = cJSON_Parse(jsonString);
    bool JsonError = true;

    if (json == NULL) {
        printf("%s \n", jsonString);
        fprintf(stderr, "Error al parsear el JSON.\n");
        JsonError = false;
    }

    if (JsonError) {
        cJSON *capacity = cJSON_GetObjectItemCaseSensitive(json, "capacidad");

        if (cJSON_IsNumber(capacity)) {
            int valorEntero = capacity->valueint;

            cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "room");

            if (cJSON_IsString(name) && (name->valuestring != NULL)) {
                const char *valorString = name->valuestring;

                if (num_rooms < MAX_ROOMS) {
                    strcpy(rooms[num_rooms].name, valorString);
                    rooms[num_rooms].capacity = valorEntero;
                    num_rooms++;
                    printf("Sala %s creada con éxito.\n", name->valuestring);
                } else {
                    printf("No se pueden crear más salas, se alcanzó el límite.\n");
                }

                printf("El nombre es: %s\n", valorString);
            } else {
                fprintf(stderr, "No se pudo obtener el valor de \"nombre\" del JSON como una cadena.\n");
            }

        } else {
            fprintf(stderr, "No se pudo obtener el valor de \"edad\" del JSON como un entero.\n");
        }
    }

    (*env)->ReleaseStringUTFChars(env, jsonstring, jsonString);
}

JNIEXPORT jobject JNICALL Java_libgrafos_grafos_assign_1room(JNIEnv *env, jobject obj, jstring jsonString) {
    const char *jsonStringC = (*env)->GetStringUTFChars(env, jsonString, NULL);

    printf("%s \n", jsonStringC);

    cJSON *json = cJSON_Parse(jsonStringC);

    if (json == NULL) {
        fprintf(stderr, "Error al parsear el JSON.\n");
        return NULL;
    }

    char *user;

    cJSON *nombre = cJSON_GetObjectItemCaseSensitive(json, "usuario");

    if (cJSON_IsString(nombre) && (nombre->valuestring != NULL)) {
        user = nombre->valuestring;
        printf("El User es: %s\n", user);
    } else {
        fprintf(stderr, "No se pudo obtener el valor de \"nombre\" del JSON como una cadena.\n");
    }

    char *room;

    cJSON *hab = cJSON_GetObjectItemCaseSensitive(json, "room");

    if (cJSON_IsString(hab) && (hab->valuestring != NULL)) {
        room = hab->valuestring;
        printf("la habitacion es: %s\n", room);
    } else {
        fprintf(stderr, "No se pudo obtener el valor de \"nombre\" del JSON como una cadena.\n");
    }

    char *start_time;

    cJSON *ini = cJSON_GetObjectItemCaseSensitive(json, "horainicio");

    if (cJSON_IsString(ini) && (ini->valuestring != NULL)) {
        start_time = ini->valuestring;
        printf("la hora inicial es: %s\n", start_time);
    } else {
        fprintf(stderr, "No se pudo obtener el valor de \"nombre\" del JSON como una cadena.\n");
    }

    char *end_time;

    cJSON *fin = cJSON_GetObjectItemCaseSensitive(json, "horafinal");

    if (cJSON_IsString(fin) && (fin->valuestring != NULL)) {
        end_time = fin->valuestring;
        printf("la hora final es: %s\n", end_time);
    } else {
        fprintf(stderr, "No se pudo obtener el valor de \"nombre\" del JSON como una cadena.\n");
    }

    int capacity_r;

    cJSON *cap = cJSON_GetObjectItemCaseSensitive(json, "capacidad");

    if (cJSON_IsNumber(cap)) {
        capacity_r = cap->valueint;
        printf("La capacidad es: %d\n", capacity_r);
    } else {
        fprintf(stderr, "No se pudo obtener el valor de \"edad\" del JSON como un entero.\n");
    }

    bool room_exists = false;
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(room, rooms[i].name) == 0) {
            room_exists = true;
            break;
        }
    }

    if (!room_exists) {
        printf("La sala %s no existe.\n", room);
        return NULL;
    }

    bool room_occupied = false;
    int available_rooms[MAX_ROOMS];
    int num_available_rooms = 0;

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(room, reservations[i].room) == 0 && (strcmp(start_time, reservations[i].end_time) < 0) && (strcmp(end_time, reservations[i].start_time) > 0)) {
            room_occupied = true;
            break;
        }
    }

    if (room_occupied) {
        for (int i = 0; i < num_rooms; i++) {
            if (strcmp(room, rooms[i].name) != 0) {
                bool room_available = true;

                for (int j = 0; j < num_reservations; j++) {
                    if (strcmp(rooms[i].name, reservations[j].room) == 0) {
                        if ((strcmp(start_time, reservations[j].end_time) < 0) && (strcmp(end_time, reservations[j].start_time) > 0)) {
                            room_available = false;
                            break;
                        }
                    }
                }

                if (room_available && rooms[i].capacity >= capacity_r) {
                    available_rooms[num_available_rooms] = i;
                    num_available_rooms++;
                }
            }
        }

        if (num_available_rooms > 0) {
            printf("Salas disponibles con capacidad suficiente y sin solapamiento de horarios:\n");
            for (int i = 0; i < num_available_rooms; i++) {
                printf("Sala %s (Capacidad %d):\n", rooms[available_rooms[i]].name, rooms[available_rooms[i]].capacity);
            }
        } else {
            printf("No hay salas disponibles con capacidad suficiente y sin solapamiento de horarios.\n");
            return NULL;
        }
    }

    if (!room_occupied) {
        strcpy(reservations[num_reservations].room, room);
        strcpy(reservations[num_reservations].user, user);
        strcpy(reservations[num_reservations].start_time, start_time);
        strcpy(reservations[num_reservations].end_time, end_time);
        reservations[num_reservations].capacity_r = capacity_r;
        printf("La sala %s ha sido asignada a %s de %s a %s de %d.\n", room, user, start_time, end_time, capacity_r);
        num_reservations++;
    }

    (*env)->ReleaseStringUTFChars(env, jsonString, jsonStringC);

    // Creating a Boolean object and returning it
    jclass booleanClass = (*env)->FindClass(env, "java/lang/Boolean");
    jmethodID valueOfMethod = (*env)->GetStaticMethodID(env, booleanClass, "valueOf", "(Z)Ljava/lang/Boolean;");
    return (*env)->CallStaticObjectMethod(env, booleanClass, valueOfMethod, !room_occupied);
}

JNIEXPORT void JNICALL Java_libgrafos_grafos_showRooms(JNIEnv *env, jobject obj) {
    printf("Salas disponibles:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%s\n", rooms[i].name);
    }
}
