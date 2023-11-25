# Grafos_reserva
En este repositorio se encontrara  la creacion de una libreria que usa grafos bipartitos para la aignacion de salas, esta está contruida con un madelo el cual corre en c y otro que corre en java hecha en otra rama

Se utilizo en esta libreria el uso de otra la cual es cJSON
```https://github.com/DaveGamble/cJSON.git```


Trae de grafos.c y se crea el grafos.o y el -lcjson compila la libreria necesaria para que funcione correctamente 
```
gcc -I. -c grafos.c -o grafos.o -lcjson
```



