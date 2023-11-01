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

struct Room rooms[50];


// Estructura para representar una reserva
struct Reservation {
char room[20];
char user[20];
char start_time[10];
char end_time[10];
};

// Arreglos para almacenar las salas y las reservas


struct Reservation reservations[MAX_RESERVATIONS];

int num_rooms = 0;
int num_reservations = 0;

void createRoom(const char* name, int capacidad) {
    if (num_rooms < 50) {
        strcpy(rooms[num_rooms].name, name);
        rooms[num_rooms].capacity = capacidad;
        num_rooms++;
        printf("Sala %s creada con éxito.\n", name);
    } else {
        printf("No se pueden crear más salas, se alcanzó el límite.\n");
    }
}

// Función para mostrar las salas disponibles
void showRooms() {
    printf("Salas disponibles:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%s\n", rooms[i].name);
    }
}

// Función para asignar una sala a un usuario en un horario específico
bool assign_room(char user[], char room[], char start_time[], char end_time[]) {

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


    for (int i = 0; i < num_reservations; i++) {
        // Verificar si la sala está ocupada en el horario solicitado por el usuario
        if (strcmp(room, reservations[i].room) == 0) {
            if ((strcmp(start_time, reservations[i].end_time) < 0) && (strcmp(end_time, reservations[i].start_time) > 0)) {
                printf("La sala %s está ocupada en ese horario.\n", room);
                return false;
            }
        }
    }

    // Si la sala está disponible, asignarla al usuario en ese horario
    strcpy(reservations[num_reservations].room, room);
    strcpy(reservations[num_reservations].user, user);
    strcpy(reservations[num_reservations].start_time, start_time);
    strcpy(reservations[num_reservations].end_time, end_time);

    printf("La sala %s ha sido asignada a %s de %s a %s.\n", room, user, start_time, end_time);

    num_reservations++;
    return true;
}


int main() {

    createRoom("Sala A", 10);
    createRoom("Sala B", 8);
    showRooms();

    assign_room("Usuario1", "Sala A", "09:00", "10:30");
    assign_room("Usuario2", "Sala A", "10:45", "11:45");
    assign_room("Usuario3", "Sala B", "09:30", "10:30");
    assign_room("Usuario4", "Sala A", "09:15", "10:00");
    assign_room("Usuario5", "Sala B", "10:00", "11:00");

    return 0;
}