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

