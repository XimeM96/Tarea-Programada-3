#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>
#include "./../src/producto.h"
#include "./../src/tienda.h"
#include "./../src/excepcionesProducto.h"
#include "./../src/excepcionesTienda.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, CrearTienda_Test)
    {
        
        Tienda *tienda = new Tienda();

        tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");

        string nombreActual = tienda->getNombre();
        string direccionWebActual = tienda->getDireccionDeInternet();
        string direccionFisicaActual = tienda->getDireccionFisica();
        string telefonoActual = tienda->getTelefono();

        string nombreEsperado = "Los Patitos";
        string direccionWebEsperada = "lospatitos.com";
        string direccionFisicaEsperada = "San Jose";
        string telefonoEsperado = "12345678";

    
        EXPECT_EQ(nombreEsperado, nombreActual);
        EXPECT_EQ(direccionWebEsperada, direccionWebActual);
        EXPECT_EQ(direccionFisicaEsperada, direccionFisicaActual);  
        EXPECT_EQ(telefonoEsperado, telefonoActual);  

    }

    TEST(Tienda_Test, ExcepcionesTienda_Test){

        Tienda *tienda = new Tienda();                      

        EXPECT_THROW({
            tienda->CrearTienda("Los Patitos Woooooooooooooooo", "lospatitos.com", "San Jose", "12345678");
        }, ExcepcionNombreTienda);

        EXPECT_THROW({
            tienda->CrearTienda("Los Patitos", "lospatitos.commmmmmmmmmmmmmmmmm", "San Jose", "12345678");
        }, ExcepcionDireccionInternet);

        EXPECT_THROW({
            tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Joseeeeeeeeeeeeeeeeeeeeeeeeeeeee", "12345678");
        }, ExcepcionDireccionFisica);  

        EXPECT_THROW({
            tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678123345345312423");
        }, ExcepcionTelefono);               

    }

    TEST(Tienda_Test, ModificarProducto_Test){

        Tienda *tienda = new Tienda();
        tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");
        Producto *producto1 = new Producto();
        producto1->CrearProducto(1, "Camara", 6);
        Producto *producto2 = new Producto();
        producto2->CrearProducto(2, "Celular", 9);
        Producto *producto3 = new Producto();
        producto3->CrearProducto(3, "Laptop", 2);

        tienda->AgregarProducto(producto1);
        tienda->AgregarProducto(producto2);
        tienda->AgregarProducto(producto3);

        tienda->ModificarProducto(3, "Teclado", 5);

        string streamEsperado = tienda->ConsultarInventario();
        string streamActual = "Los Patitos lospatitos.com San Jose 12345678\n1 Camara 6\n2 Celular 9\n3 Teclado 5\n";

        EXPECT_EQ(streamEsperado, streamActual);

    }

    TEST(Tienda_Test, EliminarProducto_Test){

        Tienda *tienda = new Tienda();
        tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");
        Producto *producto1 = new Producto();
        producto1->CrearProducto(1, "Camara", 6);
        Producto *producto2 = new Producto();
        producto2->CrearProducto(2, "Celular", 9);
        Producto *producto3 = new Producto();
        producto3->CrearProducto(3, "Laptop", 2);

        tienda->AgregarProducto(producto1);
        tienda->AgregarProducto(producto2);
        tienda->AgregarProducto(producto3);

        tienda->EliminarProducto(2);

        string streamEsperado = tienda->ConsultarInventario();
        string streamActual = "Los Patitos lospatitos.com San Jose 12345678\n1 Camara 6\n3 Laptop 2\n";

        EXPECT_EQ(streamEsperado, streamActual);     

    }

    TEST(Tienda_Test, AgregarProducto_Test){

        Tienda *tienda = new Tienda();
        tienda->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");
        Producto *producto1 = new Producto();
        producto1->CrearProducto(1, "Camara", 6);
        Producto *producto2 = new Producto();
        producto2->CrearProducto(2, "Celular", 9);
        Producto *producto3 = new Producto();
        producto3->CrearProducto(3, "Laptop", 2);

        tienda->AgregarProducto(producto1);
        tienda->AgregarProducto(producto2);
        tienda->AgregarProducto(producto3);

        int actual = tienda->getCantidadProductos();
        int esperado = 3;

        EXPECT_EQ(esperado, actual);

    }

    TEST(Tienda_Test, GuardarYCargarStreamBinario_Test){

        Tienda *tiendaEsperada = new Tienda();
        tiendaEsperada->CrearTienda("Los Patitos", "lospatitos.com", "San Jose", "12345678");
        Producto *producto_1 = new Producto();
        producto_1->CrearProducto(1, "Camara", 6);
        Producto *producto_2 = new Producto();
        producto_2->CrearProducto(2, "Celular", 9);
        Producto *producto_3 = new Producto();
        producto_3->CrearProducto(3, "Laptop", 2);

        tiendaEsperada->AgregarProducto(producto_1);
        tiendaEsperada->AgregarProducto(producto_2);
        tiendaEsperada->AgregarProducto(producto_3);

        ofstream archivoSalida;
        archivoSalida.open("InventarioTotal.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "ERROR AL ABRIR EL ARCHIVO.DAT";
            
        }

        tiendaEsperada->GuardarStreamBinario(&archivoSalida);

        archivoSalida.close();

        ifstream archivoEntrada;

        archivoEntrada.open("InventarioTotal.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "ERROR AL ABRIR EL ARCHIVO.DAT 2";
            
        }
    
        Tienda *tiendaALeer = new Tienda();
        tiendaALeer->CargarStreamBinario(&archivoEntrada);

        ostringstream streamTiendaEsperada;
        streamTiendaEsperada << tiendaEsperada;

        string esperado = "Los Patitos lospatitos.com San Jose 12345678\n1 Camara 6\n2 Celular 9\n3 Laptop 2\n";
        string streamEsperado = tiendaALeer->ConsultarInventario();

        EXPECT_EQ(esperado, streamEsperado);
        string streamLeido = tiendaALeer->ConsultarInventario();
        EXPECT_EQ(esperado, streamLeido);

    }
    
}
