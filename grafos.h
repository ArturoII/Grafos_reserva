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

#define GRAFOS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ROOMS 50
#define MAX_RESERVATIONS 200

struct Room {
    char name[20];
    int capacity;
};

struct Reservation {
    char room[20];
    char user[20];
    char start_time[10];
    char end_time[10];
    int capacity_r;
};

extern struct Room rooms[MAX_ROOMS];
extern struct Reservation reservations[MAX_RESERVATIONS];
extern int num_rooms;
extern int num_reservations;

void createRoom(const char* name, int capacidad);
void showRooms();
bool assign_room(char user[], char room[], char start_time[], char end_time[], int capacity_r);

#endif /* GRAFOS_H */ 