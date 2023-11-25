# Grafos_reserva
en este repositorio se encontrara  la creacion de una lobreria que usa grafos bipartitos para la aignacion de salas esta esta contruida con un madelo el cual corre en c y otro que corre en java hecha en otra rama

se utilizo en esta libreria el uso de otra la cual es cJSON
```https://github.com/DaveGamble/cJSON.git```

comandos para C
se genera el .so a el compilar 
```
gcc -c -I/usr/lib/jvm/java-17-openjdk-amd64/include -I/usr/lib/jvm/java-17-openjdk-amd64/include/linux -fPIC grafos.c -o grafos.o
```

compila el archivo "grafos.c" utilizando GCC, busca archivos de encabezado en el directorio actua
```
gcc -I. -c grafos.c -o grafos.o
```

trae de grafos.c y se crea el bgrafos .o y el -lcjson compila la libreria necesaria para que funcione correctamente 
```
gcc -I. -c grafos.c -o grafos.o -lcjson
```



