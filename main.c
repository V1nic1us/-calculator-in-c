#include <stdio.h>

void hex(int numero)
{
    if (numero == 0)
    {
        printf("0");
        return;
    }

    char hexadecimal[32];
    int indice = 0;

    while (numero > 0)
    {
        int resto = numero % 16; // Resto da divisão por 16
        if (resto < 10)
        {
            hexadecimal[indice++] = '0' + resto; // Converte números
        }
        else
        {
            hexadecimal[indice++] = 'A' + (resto - 10); // Converte letras
        }
        numero /= 16; // Atualiza o número
    }

    // Imprime os dígitos em ordem reversa
    printf("Hexadecimal: ");
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

void bin(int numero)
{
    if (numero == 0)
    {
        printf("0");
        return;
    }

    int binario[32];
    int indice = 0;

    while (numero > 0)
    {
        binario[indice++] = numero % 2; // Resto da divisão por 2
        numero /= 2;                    // Atualiza o número
    }

    // Imprime os bits em ordem reversa
    printf("Binário: ");
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", binario[i]);
    }
    printf("\n");
}

void oct(int numero)
{
    if (numero == 0)
    {
        printf("0");
        return;
    }

    int octal[32];
    int indice = 0;

    while (numero > 0)
    {
        octal[indice++] = numero % 8; // Resto da divisão por 8
        numero /= 8;                  // Atualiza o número
    }

    // Imprime os dígitos em ordem reversa
    printf("Octal: ");
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", octal[i]);
    }
    printf("\n");
}

void printCalc(int numero){
    bin(numero);
    oct(numero);
    hex(numero);
}

int main(int argc, char const *argv[])
{
    float num1, num2;
    char op;
    printf("Calculadora do Curso de C\n\n");
    printf("Operadores disponíveis: \n+ Soma \n- Subtração \n* Multiplixação \n/ Divisão\n\n");
    printf("Digite a expressão na forma: numero1 operador numero2\n");
    scanf("%f %c %f", &num1, &op, &num2);

    switch (op)
    {
    case '+':
        printf("Resultado: %.2f\n", num1 + num2);
        printCalc(num1 + num2);
        break;
    case '-':
        printf("Resultado: %.2f\n", num1 - num2);
        printCalc(num1 - num2);
        break;
    case '*':
        printf("Resultado: %.2f\n", num1 * num2);
        printCalc(num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Não é possível dividir por zero\n");
        }
        else
        {
            printf("Resultado: %.2f\n", num1 / num2);
            printCalc(num1 / num2);
        }
        break;
    default:
        printf("Operador inválido\n");
        break;
    }
    return 0;
}
