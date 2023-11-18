/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   appUsa.c
 * Author: brand
 *
 * Created on 4 de noviembre de 2023, 3:00 p. m.
 */

#include "grafos.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cJSON.h"
int main(){


        createRoom("Sala A", 10);
        createRoom("Sala B", 8);
        createRoom("Sala C", 100); createRoom("Sala D", 50);
        showRooms();
        assign_room("Usuario3", "Sala B", "09:30", "10:30", 30);
        assign_room("Usuario1", "Sala A", "09:00", "10:30", 20);
        assign_room("Usuario2", "Sala A", "10:45", "11:45", 10);
        assign_room("Usuario4", "Sala A", "09:15", "10:00", 40);
        assign_room("Usuario5", "Sala B", "10:00", "11:00", 50);
        assign_room("Usuario6", "Sala C", "14:00", "16:00", 50);
        assign_room("Usuario7", "Sala B", "14:00", "16:00", 5);
    return 0;
}



