#include <stdio.h>

int calcularPotencia(int base, int expoente)
{
    int resultado = 1;

    if (expoente < 0)
        return 0; // não suportado

    for (int i = 0; i < expoente; i++)
    {
        resultado = resultado * base;
    }

    return resultado;
}

int main()
{
    int resultado;

    resultado = calcularPotencia(2, 3); // 2 elevado a 3 é igual a 8
    printf("Base = 2, Expoente = 3, Resultado = %d => %i\n",resultado, resultado == 8);

    resultado = calcularPotencia(5, 2); // 5 elevado a 2 é igual a 25
    printf("Base = 5, Expoente = 2, Resultado = %d => %i\n",resultado, resultado == 25);

    resultado = calcularPotencia(10, 0); // 10 elevado a 0 é igual a 1
    printf("Base = 10, Expoente = 0, Resultado = %d => %i\n",resultado, resultado == 1);

    resultado = calcularPotencia(3, 4); // 3 elevado a 4 é igual a 81
    printf("Base = 3, Expoente = 4, Resultado = %d => %i\n",resultado, resultado == 81);

    resultado = calcularPotencia(2, -3); // 2 elevado a -3 não é suportado, deve retornar 0
    printf("Base = 2, Expoente = -3, Resultado = %d => %i\n",resultado, resultado == 0);

    return 0;
}