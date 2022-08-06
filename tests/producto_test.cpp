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
    TEST(Producto_Test, CrearProducto_Test)
    {
        
        Producto *producto1 = new Producto(9, "Camara", 6);
        
        int idActual = producto1->getIdProducto();
        string nombreActual = producto1->getNombreProducto();
        int existenciasActuales = producto1->getExistenciasTotales();

        int idEsperado = 9;
        char nombreEsperado[20] = "Camara";
        int existenciasEsperadas = 6;

        EXPECT_EQ(idEsperado, idActual);
        EXPECT_EQ(nombreEsperado, nombreActual);
        EXPECT_EQ(existenciasEsperadas, existenciasActuales);                

        delete producto1;

    }

    TEST(Producto_Test, ExcepcionesProducto_Test){

        Producto *producto = new Producto();                      

        EXPECT_THROW({
            producto->CrearProducto(3, "Ventilador de maxima potencia version 2000", 7);
        }, ExcepcionNombreProducto);

        EXPECT_THROW({
            producto->CrearProducto(-3, "Ventilador", 7);
        }, ExcepcionIDProducto);

        EXPECT_THROW({
            producto->CrearProducto(3, "Ventilador", -9);
        }, ExcepcionExistenciasDisponibles);            

    }

        
    
}