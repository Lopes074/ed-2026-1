#include <stdio.h>

typedef struct {
    int nota200;
    int nota100;
    int nota50;
    int nota20;
    int nota10;
    int nota5;
    int nota2;
    int valido;
} Saque;

Saque caixa(int valor){

    Saque s = {0,0,0,0,0,0,0,1};

    if (valor <= 0 || valor > 1000){
        s.valido = 0;
        return s;
    }

    s.nota200 = valor / 200;
    valor %= 200;

    s.nota100 = valor / 100;
    valor %= 100;

    s.nota50 = valor / 50;
    valor %= 50;

    s.nota20 = valor / 20;
    valor %= 20;

    s.nota10 = valor / 10;
    valor %= 10;

    s.nota5 = valor / 5;
    valor %= 5;

    s.nota2 = valor / 2;
    valor %= 2;

    if (valor != 0)
        s.valido = 0;

    return s;
}

int main(){

    Saque s = caixa(370);

    printf("Valido: %i\n", s.valido);
    printf("200: %i\n", s.nota200);
    printf("100: %i\n", s.nota100);
    printf("50: %i\n", s.nota50);
    printf("20: %i\n", s.nota20);
    printf("10: %i\n", s.nota10);
    printf("5: %i\n", s.nota5);
    printf("2: %i\n", s.nota2);

    return 0;
}