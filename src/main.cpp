#include "producto.h"
#include "tienda.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    Tienda *tienda = new Tienda();

    Producto *producto1 = new Producto(1,"Celular",10);
    Producto *producto2 = new Producto(2,"Computadora",20);
    Producto *producto3 = new Producto(3,"Reloj",18);
    Producto *producto4 = new Producto(4,"Teclado",6);
    Producto *producto5 = new Producto(5, "Licuadora", 15);

    tienda->agregarProducto(producto1);
    tienda->agregarProducto(producto2);
    tienda->agregarProducto(producto3);
    tienda->agregarProducto(producto4);
    tienda->agregarProducto(producto5);

    ofstream archivoSalida;
    archivoSalida.open("inventarioTotal.dat", ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "ERROR AL ABRIR EL ARCHIVO.DAT";
        return -1;
    }

    tienda->generarStreamBinario(&archivoSalida);
    
    // cout<<"Tienda 1"<<endl<<endl<<tienda->consultarInventario()<<endl;  
    // tienda->eliminarProducto(4);
    // cout<<"Tienda 2"<<endl<<endl<<tienda->consultarInventario()<<endl;  
    // tienda->modificarProducto(1,"Audifonos",3);
    // cout<<"Tienda 3"<<endl<<endl<<tienda->consultarInventario()<<endl;   
    // tienda->generarStreamBinario(&archivoSalida);

    archivoSalida.close();
    delete tienda;

    

}