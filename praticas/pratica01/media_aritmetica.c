#include <stdio.h>

float calcularMedia(float numeros[], int n)
{
    float soma = 0;

    if (n <= 0 || n > 100)
        return 0;

    for (int i = 0; i < n; i++)
    {
        soma += numeros[i];
    }

    return soma / n;
}

void imprimirValores(float numeros[], int n){
    printf("Valores: ");
    for(int i = 0; i < n; i++){
        printf("%.0f ; ", numeros[i]);
    }
    printf("\n");
}

int main()
{
    float numeros1[] = {10, 20, 30};
    float numeros2[] = {5, 5, 5, 5};
    float numeros3[] = {7, 8};
    float numeros4[] = {100};

    float media;

    imprimirValores(numeros1,3);
    media = calcularMedia(numeros1, 3);
    printf("=> Media = %.2f => %i\n\n", media, media == 20.0f);

    imprimirValores(numeros2,4);
    media = calcularMedia(numeros2, 4);
    printf("=> Media = %.2f => %i\n\n", media, media == 5.0f);

    imprimirValores(numeros3,2);
    media = calcularMedia(numeros3, 2);
    printf("=> Media = %.2f => %i\n\n", media, media == 7.5f);

    imprimirValores(numeros4,1);
    media = calcularMedia(numeros4, 1);
    printf("=> Media = %.2f => %i\n\n", media, media == 100.0f);

    return 0;
}