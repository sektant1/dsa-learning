// Ponteiro eh uma variavel que armazena o endereco na memoria de alguma outra
// variavel. Utilidade: eles ajudam a evitar o desperdicio de memoria,
// permitindo que voce passe apenas o endereco de uma estrutura de dados GRANDE
// ao inves de copiar ela com todos os seus dados.

// Pense nos ponteiros(*) como uma CHAVE no formato de estrela que destrava o
// acesso a um endereco de memoria, como uma CHAVE que abre um BAU.

#include <stdio.h>

// pass by value (get)
void birthdayBad(int age)
{
    // nao incrementa
    age++;
}

// pass by reference (set)
void birthday(int* age)
{
    // dereference
    (*age)++;
}

int main()
{
    int age = 25;
    // int* pAge = &age;

    // birthday(pAge);
    birthday(&age);

    printf("%d\n", age);

    return 0;
}
