#ifndef TIENDA_H
#define TIENDA_H
#include "producto.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Tienda {

    private:

    char nombre[15];
    char direccionDeInternet[24];
    char direccionFisica[24];
    char telefono[8];
    vector <Producto*> arregloDeProductos;

    public:

    Tienda();
    Tienda(string, string, string , string);
    ~Tienda();
    
    string getNombre();
    string getDireccionDeInternet();
    string getDireccionFisica();
    string getTelefono();
    int getCantidadProductos();
    Producto *getProducto(int idProducto);

    void setNombre(string);
    void setDireccionDeInternet(string);
    void setDireccionFisica(string);
    void setTelefono(string);

    void CrearTienda(string,string,string,string);
    void AgregarProducto(Producto*);
    void ModificarProducto(int,string,int);
    void EliminarProducto(int);
    void Guardar();
    void GuardarStreamBinario(ostream *streamSalida);
    void CargarStreamBinario(istream *streamEntrada);
    string ConsultarInventario();

    friend ostream& operator << (ostream &o, const Tienda *tienda);

};

#endif
