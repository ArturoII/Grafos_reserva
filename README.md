# Grafos_reserva

Esta es la parte del codigo que seria para que se pueda usar en java, asi que vamos a hacer un breve resumen de la compilacion y el uso de la libreria.
## Proceso
se crea un archivo en java en el que se van a escribir los metodos nativamente

```java

    public native void createRoom(String Json);
    public native Boolean assign_room(String Json);
    public native void showRooms();
    
```

Despues de hacer este codigo se compila a traves de este comando para la generacion del .h

```
javac Grafos.java -h .
```

ya que se genero el .h ahora se va a hacer uso de esa creacion y se va a copiar a un .c

```
cp libgrafos_Grafos.h libgrafos_Grafos.c 
```
hecho eso se puede poner ahi todo el codigo c que se necesite
