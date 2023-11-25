# Grafos_reserva

Esta es la parte del codigo que seria para que se pueda usar en java, asi que vamos a hacer un breve resumen de la compilacion y el uso de la libreria.
Recordemos que en la otra rama esta Code.c para poder compilarla en c correctamente.
se uso otra libreria para este proyecto que esta en este link
```https://github.com/DaveGamble/cJSON.git```
## Proceso
Se crea un archivo en java en el que se van a escribir los metodos nativamente

```java

    public native void createRoom(String Json);
    public native Boolean assign_room(String Json);
    public native void showRooms();
    
```

Despues de hacer este codigo se compila a traves de este comando para la generacion del .h

```
javac Grafos.java -h .
```

Ya que se genero el .h ahora se va a hacer uso de esa creacion y se va a copiar a un .c

```
cp libgrafos_Grafos.h libgrafos_Grafos.c 
```
Hecho eso se puede poner ahi todo el codigo c que se necesite con las integraciones del .h

Ahora llega la compilacion de la libreria
```
gcc -c -fPIC -I/usr/lib/jvm/java-17-openjdk-amd64/include/ -I/usr/lib/jvm/java-17-openjdk-amd64/include/linux -o libgrafos_grafos.o libgrafos_grafos.c
```

Luego se termina de compilar con el .o y aparte agregandole la otra libreria que se necesita que es cJSON
```
gcc -shared -o libgrafos_grafos.so libgrafos_grafos.o -lcjson
```

Se copia en las librerias nativas del codigo 
```
sudo cp libgrafos_grafos.so /usr/lib
```
Y se hace el comando para la configuracion
```
sudo ldconfig
```
Despues de esos pasos el usuario hara las modificaciones respectivas para cargar la libreria y poder usarla
