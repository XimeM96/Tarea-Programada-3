#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>
#include "./../src/tienda.h"
#include "./../src/producto.h"
#include "./../src/biblioteca.h"

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

        
    
}