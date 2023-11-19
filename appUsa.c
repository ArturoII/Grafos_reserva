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



        createRoom("{\room\":\"Sala A\",\"capacidad\":40}");
        createRoom("{\room\":\"Sala B\",\"capacidad\":50}");
        createRoom("{\room\":\"Sala C\",\"capacidad\":100}");
        createRoom("{\room\":\"Sala D\",\"capacidad\":50}");
        showRooms();
        assign_room("{\"usuario\":\"Usuario3\",\"room\":\"Sala B\",\"horainicio\":\"09:30\",\"horafinal\":\"10:30\",\"capacidad\":30}");
        assign_room("{\"usuario\":\"Usuario1\",\"room\":\"Sala A\",\"horainicio\":\"09:00\",\"horafinal\":\"10:30\",\"capacidad\":20}");
        assign_room("{\"usuario\":\"Usuario2\",\"room\":\"Sala A\",\"horainicio\":\"10:45\",\"horafinal\":\"11:45\",\"capacidad\":10}");
        assign_room("{\"usuario\":\"Usuario4\",\"room\":\"Sala A\",\"horainicio\":\"09:15\",\"horafinal\":\"10:00\",\"capacidad\":40}");
        assign_room("{\"usuario\":\"Usuario5\",\"room\":\"Sala B\",\"horainicio\":\"10:00\",\"horafinal\":\"11:00\",\"capacidad\":50}");
        assign_room("{\"usuario\":\"Usuario6\",\"room\":\"Sala C\",\"horainicio\":\"14:00\",\"horafinal\":\"16:00\",\"capacidad\":500}");
        assign_room("{\"usuario\":\"Usuario7\",\"room\":\"Sala B\",\"horainicio\":\"14:00\",\"horafinal\":\"16:00\",\"capacidad\":5}");
        
        
    return 0;
}


