# Tarea Programada 3

Estudiante: Jimena Méndez Chacón | Carné: B84832 | Curso: Programación II | Profesor: Mauricio Ulate Quirós

Consiste de una librería que permite administrar los productos de una tienda. Permite:

1. Crear una tienda
2. Crear productos y agregarlos a una tienda
3. Modificar productos
4. Eliminar productos
5. Listar todos los productos

Un producto se constituye por:

|    Campo    | Offset | Bytes |
| ----------- |:------:|:-----:|
| ID          | 0      | 4     |
| Nombre      | 4      | 20    |
| Existencias | 24     | 4     |
| Total Bytes |        | 28    |

Una tienda se constituye por:


|       Campo        | Offset |   Bytes   |
| -----------------  |:------:|:---------:|
| Nombre             | 0      | 15        |
| Direccion Web      | 15     | 24        |
| Direccion Física   | 39     | 24        |
| Teléfono           | 63     |  8        |


# Instrucciones de compilación:

Para compilar la librería, ejecute esta instrucción:

make

Para compilar las pruebas unitarias, ejecute esta instrucción:

make test

Para ejecutar las pruebas unitarias, ejecute esta instrucción:

./bin/tests

Para limpiar el bin, ejecute esta instrucción:

make clean
