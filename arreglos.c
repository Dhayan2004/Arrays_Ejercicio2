#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

#define CANTIDAD_ALIMENTOS 4
#define MAX_NOMBRE_ALIMENTO 50  

int main() {
    char *alimentos[CANTIDAD_ALIMENTOS];
    
    float precios[CANTIDAD_ALIMENTOS] = {50.00, 80.00, 25.00, 20.00};
    int cantidad[CANTIDAD_ALIMENTOS] = {0};  
    
    printf("Ingresa los nombres de %d alimentos:\n", CANTIDAD_ALIMENTOS);
    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        alimentos[i] = (char *)malloc(MAX_NOMBRE_ALIMENTO * sizeof(char)); 
        if (alimentos[i] == NULL) {  
            printf("Error al asignar memoria.\n");
            return 1;  
        }
        
        printf("Alimento %d: ", i + 1);
        scanf(" %[^\n]s", alimentos[i]);  
    }

    char continuar;
    int opcion;
    int cantidadIngresada;
    
    // Mostrar el menú
    printf("\nBienvenido al restaurante SM41:\n");
    printf("Menu\n");
    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        printf("%d - %s - $%.2f\n", i + 1, alimentos[i], precios[i]);
    }
    printf("5 - Salir\n");

    do {
        printf("Ingresa una opcion: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= CANTIDAD_ALIMENTOS) {
            printf("Ingresa la cantidad de %s: ", alimentos[opcion - 1]);
            scanf("%d", &cantidadIngresada);
            
            cantidad[opcion - 1] += cantidadIngresada;
        } else if (opcion != 5) {
            printf("Opcion invalida. Intenta de nuevo.\n");
        }

        if (opcion != 5) {
            printf("¿Deseas hacer otro pedido? (s/n): ");
            scanf(" %c", &continuar);  
        } else {
            continuar = 'n';  
        }
        
    } while (continuar == 's');
    
    // Resumen de la cuenta
    printf("\nResumen de cuenta:\n");
    float totalGeneral = 0.0;
    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        if (cantidad[i] > 0) {
            float totalPorAlimento = precios[i] * cantidad[i];
            printf("%s - $%.2f x %d = $%.2f\n", alimentos[i], precios[i], cantidad[i], totalPorAlimento);
            totalGeneral += totalPorAlimento;
        }
    }

    printf("\nTotal general a pagar: $%.2f\n", totalGeneral);

    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        free(alimentos[i]);
    }

    return 0;
}
