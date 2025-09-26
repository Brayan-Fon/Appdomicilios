#define _CRT_SECURE_NO_WARNINGS  // Para evitar advertencias con scanf en Visual Studio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 6
#define MAX_CARRITO 50

// ---------------- Estructuras ----------------

// Producto del catálogo
typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

// Item dentro del carrito
typedef struct {
    Producto producto;
    int cantidad;
} ItemCarrito;

// ---------------- Variables globales ----------------

// Catálogo de productos fijos
Producto catalogo[MAX_PRODUCTOS] = {
    {1, "Hamburguesa", 15000},
    {2, "Pizza personal", 20000},
    {3, "Perro caliente", 12000},
    {4, "Soda", 5000},
    {5, "Jugo natural", 7000},
    {6, "Papas fritas", 8000}
};

// Carrito de compras
ItemCarrito carrito[MAX_CARRITO];
int totalItems = 0; // Cantidad de productos en el carrito

// ---------------- Funciones ----------------

// Mostrar catálogo de productos
void verCatalogo() {
    printf("\n===== MENU DE PRODUCTOS =====\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %s - $%.2f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
    }
}

// Agregar producto al carrito
void agregarProducto() {
    int id, cantidad;
    verCatalogo();
    printf("\nIngrese ID del producto: ");
    scanf("%d", &id);
    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("❌ Cantidad inválida.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (catalogo[i].id == id) {
            carrito[totalItems].producto = catalogo[i];
            carrito[totalItems].cantidad = cantidad;
            totalItems++;
            printf("✅ Producto agregado al carrito.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("❌ Producto no encontrado.\n");
    }
}

// Ver contenido del carrito
void verCarrito() {
    printf("\n===== CARRITO =====\n");
    float total = 0;
    if (totalItems == 0) {
        printf("Carrito vacío.\n");
    } else {
        for (int i = 0; i < totalItems; i++) {
            printf("%d x %s - $%.2f\n",
                   carrito[i].cantidad,
                   carrito[i].producto.nombre,
                   carrito[i].producto.precio * carrito[i].cantidad);
            total += carrito[i].producto.precio * carrito[i].cantidad;
        }
        printf("----------------------\n");
        printf("Subtotal: $%.2f\n", total);
        printf("Domicilio: $5000\n");
        printf("TOTAL: $%.2f\n", total + 5000);
    }
}

// Confirmar pedido
void confirmarPedido() {
    if (totalItems == 0) {
        printf("❌ No hay productos en el carrito.\n");
        return;
    }
    verCarrito();
    printf("\n✅ Pedido confirmado. ¡Gracias por su compra!\n");
    totalItems = 0; // Vaciar carrito después de confirmar
}

// ---------------- Main ----------------
int main() {
    int opcion;
    do {
        printf("\n===== APP DOMICILIOS =====\n");
        printf("1. Ver menú de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: verCatalogo(); break;
            case 2: agregarProducto(); break;
            case 3: verCarrito(); break;
            case 4: confirmarPedido(); break;
            case 5: printf("👋 Saliendo...\n"); break;
            default: printf("❌ Opción inválida.\n"); break;
        }
    } while (opcion != 5);

    return 0;
}
