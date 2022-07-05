#include "tienda.h"
#include "excepcionesTienda.h"
#include <string>
#include <string.h>
#include <iostream>
#include "tienda.h"

using namespace std;

Tienda::Tienda()
{
}

Tienda::Tienda(string nombreTienda, string dirWeb, string dirFisica, string telefono){

    if (nombreTienda.size() == 0 || nombreTienda.size() > 15)
    {
        throw ExcepcionNombreTienda();
    }
    if (dirWeb.size() == 0 || dirWeb.size() > 24)
    {
        throw ExcepcionDireccionInternet();
    }
    if (dirFisica.size() == 0 || dirFisica.size() > 24)
    {
        throw ExcepcionDireccionFisica();
    }
    if (telefono.size() == 0 || telefono.size() > 8);
    {
        throw ExcepcionTelefonoTiendaInvalido();
    }

    strcpy(this->nombre, nombreTienda.c_str());
    strcpy(this->direccionDeInternet, dirWeb.c_str());
    strcpy(this->direccionFisica, dirFisica.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::~Tienda()
{
    for (Producto *producto : this->arregloDeProductos){

        delete producto;
    }
}

string Tienda::getNombre(string nom)

{

    string nombre = {strcpy(this->nombre, nom.c_str())};

    return nombre;

}

string Tienda::getDireccionDeInternet(string direccionWeb)
{

    string direccionDeInternet = string {strcpy(this->direccionDeInternet, direccionWeb.c_str())};

    return direccionDeInternet;
}

string Tienda::getDireccionFisica(string direccionF)
{

    string direccionFisica = string {strcpy(this->direccionFisica, direccionF.c_str())};

    return direccionFisica;
}

string Tienda::getTelefono(string tel)
{

    string telefono = string {strcpy(this->telefono, tel.c_str())};

    return telefono;
}

void Tienda::agregarProducto(Producto *p)
{
    this->arregloDeProductos.push_back(p);
}

void Tienda::eliminarProducto(int idProd){

    if(idProd < 0){

        throw ExcepcionNegativo();
    }

     for(int i = 0; i < arregloDeProductos.size();i++){

         if(arregloDeProductos.at(i)->getIdProducto() == idProd){

             arregloDeProductos.erase(arregloDeProductos.begin()+i);

        }
    }
}

void Tienda::modificarProducto(int idProd,string nom, int exis){
     for(int i = 0; i<arregloDeProductos.size();i++){
         if(arregloDeProductos.at(i)->getIdProducto() == idProd){ 
             arregloDeProductos.at(i)->setNombreProducto(nom);
             arregloDeProductos.at(i)->setExistenciasTotales(exis);
         }
     }
}


void Tienda::generarStreamBinario(ostream *streamSalida){

    for (Producto *producto : this->arregloDeProductos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

string Tienda::consultarInventario() {
    stringstream s;
    s << this->getNombre(nombre) << " " << this->getDireccionDeInternet(direccionDeInternet) << " " << this->getDireccionFisica(direccionFisica)
      << " " << this->getTelefono(telefono) << endl;

    for (int i = 0; i < arregloDeProductos.size(); i++)
    {

        s << arregloDeProductos.at(i)->getIdProducto() << " "
          << arregloDeProductos.at(i)->getNombreProducto() << " "
          << arregloDeProductos.at(i)->getExistenciasTotales() << endl;
    }
    return s.str(); 
}
