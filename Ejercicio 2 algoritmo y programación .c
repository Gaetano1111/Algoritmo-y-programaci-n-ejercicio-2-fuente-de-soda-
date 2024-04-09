#include <stdio.h>
#include <stdlib.h>

//structura de cada uno de los datos que van a ir impresos en la factura
struct Persona {
    char nombre[50];
    char apellido[50];
    char cedula[20];
};

struct Fecha {
    char Fecha[50];
};

struct Item {
    char nombre[50];
    float precio;
};

//empezamos a declarar las funciones
int main() {
    int numItems;
    float total = 0.0;
    float descuento = 0.0;
    struct Persona persona;
    struct Fecha fecha;

    //esta parte del codigo funciona como si la pesona es que introduce los datos es el vendedor por eso los printf escritos de esa manera
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", persona.nombre);
    printf("Ingrese el apellido del cliente: ");
    scanf("%s", persona.apellido);
    printf("Ingrese la cedula del cliente: ");
    scanf("%s", persona.cedula);
    printf("Ingrese la Fecha (dd/mm/aaaa): ");
    scanf("%s", fecha.Fecha);

    printf("Cuantos items compro el cliente?: ");
    scanf("%d", &numItems);

    struct Item items[numItems];

    //este for lo uso para que para que dependiendo el numero de items comprados toda esta parte del codigo de repita
    for (int i = 0; i < numItems; i++) {
        printf("Ingrese el nombre del item %d: ", i + 1);
        scanf("%s", items[i].nombre);
        printf("Ingrese el precio del item %d: ", i + 1);
        scanf("%f", &items[i].precio);

        total += items[i].precio;
    }

    // esto evalua si se aplicara o no descuento
    if (numItems > 2) {
        descuento = total * 0.1; // 10% de descuento
        total -= descuento;
    }

    //abro el archivo
    FILE *archivo = fopen("factura.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    //esto imprime la factura
    fprintf(archivo, "              Cines Unidos\n\nFactura para: %s %s \nCedula: %s\nFecha: %s\n", persona.nombre, persona.apellido, persona.cedula, fecha.Fecha);
    fprintf(archivo, "--------------------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        fprintf(archivo, "%s - Bs %.2f\n", items[i].nombre, items[i].precio);
    }
    fprintf(archivo, "--------------------------------------------\n");
    fprintf(archivo, "Total: Bs %.2f\n", total);
    fprintf(archivo, "Descuento: Bs %.2f\n", descuento);
    fprintf(archivo, "          Gracias por su Compra\n");
    fprintf(archivo, "--------------------------------------------\n");

    //cierro el archivo
    fclose(archivo);

    printf("Factura generada correctamente en el archivo factura.txt\n");

    return 0;
}
