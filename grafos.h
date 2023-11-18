/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   grafos.h
 * Author: Usuario
 *
 * Created on 1 de noviembre de 2023, 3:53 p. m.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "grafos.h"
#include "cJSON.h"


struct Room rooms[MAX_ROOMS];
struct Reservation reservations[MAX_RESERVATIONS];

int num_rooms = 0;
int num_reservations = 0;

void createRoom(const char* name, int capacidad) {
    if (num_rooms < MAX_ROOMS) {
        strcpy(rooms[num_rooms].name, name);
        rooms[num_rooms].capacity = capacidad;
        num_rooms++;
        printf("Sala %s creada con éxito.\n", name);
    } else {
        printf("No se pueden crear más salas, se alcanzó el límite.\n");
    }
}

void showRooms() {
    printf("Salas disponibles:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%s\n", rooms[i].name);
    }
}

bool assign_room(char user[], char room[], char start_time[], char end_time[], int capacity_r) {
    bool room_exists = false;
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(room, rooms[i].name) == 0) {
            room_exists = true;
            break;
        }
    }

    if (!room_exists) {
        printf("La sala %s no existe.\n", room);
        return false;
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
            return false;
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

    return !room_occupied;
}