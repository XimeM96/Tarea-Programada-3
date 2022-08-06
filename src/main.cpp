#include "producto.h"
#include "tienda.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    Tienda *tienda = new Tienda();
    tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");

    Producto *producto1 = new Producto(1,"Celular",10);
    Producto *producto2 = new Producto(2,"Computadora",20);
    Producto *producto3 = new Producto(3,"Reloj",18);
    Producto *producto4 = new Producto(4,"Teclado",6);
    Producto *producto5 = new Producto(5, "Licuadora", 15);

    tienda->AgregarProducto(producto1);
    tienda->AgregarProducto(producto2);
    tienda->AgregarProducto(producto3);
    tienda->AgregarProducto(producto4);
    tienda->AgregarProducto(producto5);

    ofstream archivoSalida;
    archivoSalida.open("InventarioTotal.dat", ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "ERROR AL ABRIR EL ARCHIVO.DAT";
        return -1;
    }

    tienda->GuardarStreamBinario(&archivoSalida);
    
    cout<<"Tienda 1"<<endl<<endl<<tienda->ConsultarInventario()<<endl;  
    tienda->EliminarProducto(4);
    cout<<"Tienda 2"<<endl<<endl<<tienda->ConsultarInventario()<<endl;  
    tienda->ModificarProducto(1,"Audifonos",3);
    cout<<"Tienda 3"<<endl<<endl<<tienda->ConsultarInventario()<<endl;   
    tienda->GuardarStreamBinario(&archivoSalida);

    cout<<"Cantidad de productos: "<<tienda->getCantidadProductos()<<endl;

    archivoSalida.close();

    delete tienda;

    

}