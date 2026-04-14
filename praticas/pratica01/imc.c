#include <stdio.h>

float IMC(float altura, float peso) {

    if (peso <= 0 || altura <= 0)
        return 0;

    return peso / (altura * altura);
}

int main() {

    float imc = 0.0f;
    float peso, altura;

    imc = IMC(-1.75f, 50.0f); // Teste de validação
    printf("Altura = -1.75, Peso = 50, IMC = %.1f => %i\n", imc, imc == 0.0f);

    imc = IMC(1.75f, -50.0f); // Teste de validação
    printf("Altura = 1.75, Peso = -50, IMC = %.1f => %i\n", imc, imc == 0.0f);

    imc = IMC(0.0f, 50.0f); // Teste de validação
    printf("Altura = 0, Peso = 50, IMC = %.1f => %i\n", imc, imc == 0.0f);

    imc = IMC(1.75f, 0.0f); // Teste de validação
    printf("Altura = 1.75, Peso = 0, IMC = %.1f => %i\n", imc, imc == 0.0f);

    imc = IMC(1.75f, 50.0f); // abaixo do peso
    printf("Altura = 1.75, Peso = 50, IMC = %.1f => %i\n", imc, imc < 18.5f);

    imc = IMC(1.8f, 75.0f); // Peso normal
    printf("Altura = 1.8, Peso = 75, IMC = %.1f => %i\n", imc, imc >= 18.5f && imc < 25.0f);

    imc = IMC(1.55f, 65.0f); // Acima do Peso
    printf("Altura = 1.55, Peso = 65, IMC = %.1f => %i\n", imc, imc >= 25.0f && imc < 30.0f);

    imc = IMC(1.5f, 100.0f); // obesidade
printf("Altura = 1.5, Peso = 100, IMC = %.1f => %i\n", imc, imc >= 30.0f);
    return 0;
}