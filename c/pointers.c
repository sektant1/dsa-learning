// Pense nos '*' como uma CHAVE no formato de estrela que destrava o acesso a um
// endereco de memoria, como uma CHAVE que abre um BAU.

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
