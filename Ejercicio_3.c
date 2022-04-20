/*
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Producto
{
    int ProductoID;  
    int Cantidad;  //Entre 1 y 10
    char *TipoProducto;  //Valor del arreglo de TipoProductos
    float PrecioUnitario;  //Entre 10 - 100
};
typedef struct Producto Producto;
typedef struct Producto* Prod;

struct Cliente
{
    int ClienteID;
    char *NombreCliente; //Ingresado por el usuario
    int CantidadProdAPedir; //Entre 1 y 5
    Prod Productos; //El tamanio de este arreglo depende de la variable CantidadProdAPedir
};

typedef struct Cliente Cliente;
//Declaracion de funciones
void altaClientes(int cant, Cliente *cliente, char *TiposProductos); //Creara a cada cliente
void mostrar(Cliente *Cliente);

int main()
{
    int cantClientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    

    printf("\nQue cantidad de clientes desea ingresar: ");
    scanf("%d",cantClientes);
    fflush(stdin);
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente)*cantClientes);
    printf("%s", TiposProductos[2]);

    altaClientes(cantClientes, cliente, *TiposProductos);
    return 0;
}

void altaClientes(int cant, Cliente *cliente, char *TiposProductos)
{
    int i,j;
    //char nombre;
    char *Buff = (char *)malloc(sizeof(char)*100);
    char *Buff_2 = (char *)malloc(sizeof(char)*100);

    for(i=0; i<cant; i++)
    {
        printf("\n-----Cargado del cliente %d -----", (i+1));
        cliente[i].ClienteID = i+1;

        printf("\nIngrese el nombre del cliente");
        gets(Buff);
        fflush(stdin);
        //scanf("%s",nombre);
        //strcpy(Buff,nombre);

        cliente[i].NombreCliente = (char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(cliente[i].NombreCliente, Buff);

        cliente[i].CantidadProdAPedir = 1 + rand() % 6;
        cliente[i].Productos = (Prod)malloc(sizeof(Producto)*cliente[i].CantidadProdAPedir);

        for(j=0; j<cliente[i].CantidadProdAPedir; j++)
        {
            cliente[i].Productos[j].Cantidad = rand()%11;  //Pido la cantidad que va a pedir de ese mismo producto
            cliente[i].Productos[j].PrecioUnitario = (rand()%101 + 10)/1;
            int productoT = rand()%5;
            //printf("%d", &productoT);
            //printf("%s", TiposProductos[2]);
            Buff_2 = TiposProductos[productoT];
            cliente[i].Productos[j].TipoProducto = (char *)malloc((strlen(Buff_2)+1)*sizeof(char));
            strcpy(cliente[i].Productos[j].TipoProducto, Buff_2); //Paso el contenido del buff a tipoPorducto del cliente
            cliente[i].Productos[j].ProductoID = rand()%11 + 1;
        }
    }
    free(Buff);
    mostrar(cliente);
}

void mostrar(Cliente *cliente)
{
    printf("\n--------Clientes--------\n");
    for(int i=0; i<sizeof(cliente); i++)
    {
        printf("Cliente %d:\n", cliente[i].ClienteID);
        printf("\nNombre: %s", cliente[i].NombreCliente);
        printf("\nProductos solicitados: %d", cliente[i].CantidadProdAPedir);
        for(int j=0; j<cliente[i].CantidadProdAPedir; j++)
        {
            printf("\nCliente %s // Pedido %d",cliente[i].NombreCliente,j+1);
            printf("\nProducto: %s / ID: %d", cliente[i].Productos[j].TipoProducto, cliente[i].Productos[j].ProductoID);
            printf("\nPrecio untario: %d", cliente[i].Productos[j].PrecioUnitario);
            printf("\nCantidad %s que se solicito: %d\n", cliente[i].Productos->TipoProducto, cliente[i].Productos[j].Cantidad);
        }

        
        printf("\n");
    }
    free(cliente);
}