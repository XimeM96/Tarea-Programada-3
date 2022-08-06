#include "tienda.h"
#include "excepcionesTienda.h"
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <regex>
#include <cstring>


using namespace std;

Tienda::Tienda()
{
    strcpy(this->nombre, "");
    strcpy(this->direccionDeInternet, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

Tienda::Tienda(string nombreTienda, string dirWeb, string dirFisica, string telefono){

    if (nombreTienda.size() == 0 || nombreTienda.size() > 15)
    {
        throw ExcepcionNombreTienda();
    }
    else if (dirWeb.size() == 0 || dirWeb.size() > 24)
    {
        throw ExcepcionDireccionInternet();
    }
    else if (dirFisica.size() == 0 || dirFisica.size() > 24)
    {
        throw ExcepcionDireccionFisica();
    }
    else if (telefono.size() > 8 || telefono.size() <= 0)
    {
       throw ExcepcionTelefono();
        
    } else{

    strcpy(this->nombre, nombreTienda.c_str());
    strcpy(this->direccionDeInternet, dirWeb.c_str());
    strcpy(this->direccionFisica, dirFisica.c_str());
    strcpy(this->telefono, telefono.c_str());

    }
}

Tienda::~Tienda()
{
    for (Producto *producto : this->arregloDeProductos){

        delete producto;
    }
}

void Tienda::CrearTienda(string nombreTienda, string dirWeb, string dirFisica, string telefono){

    if (nombreTienda.size() == 0 || nombreTienda.size() > 15)
    {
        throw ExcepcionNombreTienda();
    }
    else if (dirWeb.size() == 0 || dirWeb.size() > 24)
    {
        throw ExcepcionDireccionInternet();
    }
    else if (dirFisica.size() == 0 || dirFisica.size() > 24)
    {
        throw ExcepcionDireccionFisica();
    }
    else if (telefono.size() > 8 || telefono.size() <= 0)
    {
       throw ExcepcionTelefono();
    } else{

    strcpy(this->nombre, nombreTienda.c_str());
    strcpy(this->direccionDeInternet, dirWeb.c_str());
    strcpy(this->direccionFisica, dirFisica.c_str());
    strcpy(this->telefono, telefono.c_str());

    }

}

string Tienda::getNombre()

{

    return this->nombre;

}

string Tienda::getDireccionDeInternet()
{

    return this->direccionDeInternet;

}

string Tienda::getDireccionFisica()
{

    return this->direccionFisica;

}

string Tienda::getTelefono()
{

    return this->telefono;

}

Producto* Tienda::getProducto(int id){

    if (id <= 0)
    {
        throw ExcepcionIDProducto();
    }

    return this->arregloDeProductos.at(id - 1);

}

int Tienda::getCantidadProductos(){


    return this->arregloDeProductos.size();
}

void Tienda::AgregarProducto(Producto *p)
{
    this->arregloDeProductos.push_back(p);
}

void Tienda::EliminarProducto(int idProd){

    if(idProd < 0){

        throw ExcepcionNegativo();
    }

     for(int i = 0; i < arregloDeProductos.size();i++){

         if(arregloDeProductos.at(i)->getIdProducto() == idProd){

             arregloDeProductos.erase(arregloDeProductos.begin()+i);

        }
    }
}

void Tienda::ModificarProducto(int idProd,string nom, int exis){

    if (idProd <= 0 ){

        throw ExcepcionIDProducto();

    } else if(nom.size() == 0 || nom.size() > 20){

        throw ExcepcionNombreProducto();

    } else if (exis < 0){

        throw ExcepcionExistenciasDisponibles();

    } 
    
    else {
    
        for(int i = 0; i < arregloDeProductos.size();i++){

            if(arregloDeProductos.at(i)->getIdProducto() == idProd){ 
                arregloDeProductos.at(i)->setNombreProducto(nom);
                arregloDeProductos.at(i)->setExistenciasTotales(exis);
            }
        }

    }
}


void Tienda::GuardarStreamBinario(ostream *streamSalida){

    streamSalida->write(this->nombre, 15);
    streamSalida->write(this->direccionDeInternet, 24);
    streamSalida->write(this->direccionFisica, 24);
    streamSalida->write(this->telefono, 8);

    for (Producto *producto : this->arregloDeProductos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

string Tienda::ConsultarInventario() {

    stringstream s;
    s << this->getNombre() << " " << this->getDireccionDeInternet() << " " << this->getDireccionFisica()
      << " " << this->getTelefono() << endl;

    for (int i = 0; i < arregloDeProductos.size(); i++)
    {

        s << arregloDeProductos.at(i)->getIdProducto() << " "
          << arregloDeProductos.at(i)->getNombreProducto() << " "
          << arregloDeProductos.at(i)->getExistenciasTotales() << endl;
    }
    return s.str(); 
}

void Tienda::CargarStreamBinario(istream *streamEntrada){


    streamEntrada->read(this->nombre, 15);
    streamEntrada->read(this->direccionDeInternet, 24);
    streamEntrada->read(this->direccionFisica, 24);
    streamEntrada->read(this->telefono, 8);

    streamEntrada->seekg(0, ios::end);
    int cantidadBytesArchivo = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytesArchivo - 71) / sizeof(Producto);
    
    streamEntrada->seekg(71);
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->AgregarProducto(producto);
    }
}
    
ostream& operator << (ostream &o, const Tienda *tienda){

    o << tienda->nombre << endl
      << tienda->direccionDeInternet << endl
      << tienda->direccionFisica << endl
      << tienda->telefono << endl;

    for (Producto *producto : tienda->arregloDeProductos)
    {
        o << producto << endl;
    }
    
    return o;

    
}

