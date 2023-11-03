#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ROOMS 50
#define MAX_RESERVATIONS 200

// estructura Room
struct Room {
    char name[20];
    int capacity;

};
// instacioamos en un arreglo la estrcutura
struct Room rooms[50];


// Estructura para representar una reserva
struct Reservation {
    char room[20];
    char user[20];
    char start_time[10];
    char end_time[10];
    int capacity_r;
};


// Instaciamos el arreglo de reservas
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
//verifica si la havitacion existe y si existe verifica si esta ocupada,
//en el caso de que no este ocupada se manda a el objeto reserva

/*
que busque la habitacion que cumpla con la capacidad y el horario si la cumple agregue la reserva,
pero que le muestre cuales cumplen o sean mayores a la capacidad para que le de a escoger
y la que el escoja guarde la posicion.
*/

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

    int cont=0;
    for (int i = 0; i < num_reservations; i++) {
        // Verificar si la sala está ocupada en el horario solicitado por el usuario
        if (strcmp(room, reservations[i].room) == 0) {
            if ((strcmp(start_time, reservations[i].end_time) < 0) && (strcmp(end_time, reservations[i].start_time) > 0)) {
                printf("La sala %s está ocupada en ese horario.\n", room);
                return false;

            }else{
                if( !(reservations[i].capacity_r >= capacity_r) ){
                    printf("no hay salas para una capacidad de %d ", capacity_r);
                    return false;
                }
            }

        }
    }

    int rommsHability[num_rooms];  cont=0; int select;
     for (int i = 0; i < num_rooms; i++) {
        if (capacity_r >= rooms[i].capacity) {
           rommsHability[cont]=i;
           cont++;
        }
    }
     printf("\nselecciones una de las salas disponibles que cumplen con la capacidad: ");
     for (int i = 0; i <= cont; i++) {
        printf("\n %d ): sala %s  capacidad %s  ", i, reservations[i].room, reservations[i].capacity_r);
    }
    scanf("%d", select);




    //crear un metodo que me guarde los numeros de las salas que cumplan con la capacidad
    //y los guaarde en un arreglo



    // Si la sala está disponible, asignarla al usuario en ese horario
    strcpy(reservations[num_reservations].room, rooms[select].name);
    strcpy(reservations[num_reservations].user, user);
    strcpy(reservations[num_reservations].start_time, start_time);
    strcpy(reservations[num_reservations].end_time, end_time);
    // strcpy(reservations[num_reservations].capacity_r, capacity_r);
    strcpy(reservations[num_reservations].capacity_r, rooms[select].capacity);


    printf("La sala %s ha sido asignada a %s de %s a %s de %d.\n", room, user, start_time, end_time, capacity_r);

    num_reservations++;
    return true;
}


int main() {

    createRoom("Sala A", 10);
    createRoom("Sala B", 8);
    showRooms();
    int opc=1, capacidad;
    char usuario[100]="", sala[100]="", horaIni[100]="", horaFin[100]="";

    while (!(opc==0))
    {
        printf("usuario: /n");
        scanf("%s", usuario);
        printf("\nsala: /n");
        scanf("%s", sala);
        printf("\nhora inicio: /n");
        scanf("%s", horaIni);
        printf("\nhora fin: /n");
        scanf("%s", horaFin);
        printf("\ncapacidad: /n");
        scanf("%d", capacidad);
        printf("\ningrese 0 para salir /n");
        scanf("%d", opc);

        assign_room(usuario, sala, horaIni, horaFin, capacidad);
        usuario[100]="", sala[100]="", horaIni[100]="", horaFin[100]="";

    }



/*
    assign_room("Usuario1", "Sala A", "09:00", "10:30", 20);
    assign_room("Usuario2", "Sala A", "10:45", "11:45", 10);
    assign_room("Usuario3", "Sala B", "09:30", "10:30", 30);
    assign_room("Usuario4", "Sala A", "09:15", "10:00", 40);
    assign_room("Usuario5", "Sala B", "10:00", "11:00", 50);
*/
    return 0;
}
