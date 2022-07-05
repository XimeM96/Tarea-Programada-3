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
    TEST(Biblioteca_Test, VerificarNombre_Test)
    {
        
        Biblioteca *biblioteca = new Biblioteca();
        char esperada[15] = {"Juan Perez"};

        string actual = biblioteca->getNombre("Juan Perez");
    
        EXPECT_EQ(esperada, actual);

        delete biblioteca;

    }

        TEST(Biblioteca_Test, VerificarDireccionDeInternet_Test)
    {
        
        Biblioteca *biblioteca = new Biblioteca();
        char esperada[24] = {"tiendaelectronicos.com"};

        string actual = biblioteca->getDireccionDeInternet("tiendaelectronicos.com");
    
        EXPECT_EQ(esperada, actual);

        delete biblioteca;

    }

        TEST(Biblioteca_Test, VerificarDireccionFisica_Test)
    {
        
        Biblioteca *biblioteca = new Biblioteca();
        char esperada[24] = {"Tres Rios, Cartago"};

        string actual = biblioteca->getDireccionFisica("Tres Rios, Cartago");
    
        EXPECT_EQ(esperada, actual);

        delete biblioteca;

    }    

        TEST(Biblioteca_Test, VerificarTelefono_Test)
    {
        
        Biblioteca *biblioteca = new Biblioteca();
        char esperada[8] = {"5553390"};

        string actual = biblioteca->getDireccionFisica("5553390");
    
        EXPECT_EQ(esperada, actual);

        delete biblioteca;

    }        
    
}