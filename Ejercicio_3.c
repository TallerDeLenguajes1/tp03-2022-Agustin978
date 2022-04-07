/*
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Producto
{
    int ProductoID;  
    int Cantidad;  //Entre 1 y 10
    char *TipoProducto;  //Valor del arreglo de TipoProductos
    float PrecioUnitario;  //Entre 10 - 100
};

typedef struct Producto* Prod;

struct Cliente
{
    int ClienteID;
    char *NombreCliente; //Ingresado por el usuario
    int CantidadProdAPedir;
    Prod Productos; //El tamanio de este arreglo depende de la variable CantidadProdAPedir
};

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

//Declaracion de funciones
void altaCliente(int cant); //Creara a cada cliente

int main()
{
    int cantClientes;

    printf("\nQue cantidad de clientes desea ingresar: ");
    gets(cantClientes);
    altaCliente(cantClientes);
    return 0;
}

void altaCliente(int cant)
{
    struct Cliente *ListadoClientes;
    int i;
    ListadoClientes = 
    for(i=0;i<cant;i++)
    {
    }
}