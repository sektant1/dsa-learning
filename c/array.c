/*
Return Value:
malloc() returns a void* pointer to the beginning of the
allocated memory block. This pointer should be cast to the appropriate data type
for use in your program. If memory allocation fails (e.g., insufficient memory),
malloc() returns NULL.

Uninitialized Memory:
The memory allocated by malloc() is uninitialized, meaning it contains
"garbage" values from previous memory usage. You must explicitly initialize this
memory if you require specific values.

Heap Allocation:
malloc() allocates memory from the heap, a region of memory available for
dynamic allocation. This contrasts with stack memory, which is used for local
variables and function call information and has a more limited and fixed size.

Deallocation with free():
Memory allocated with malloc() must be explicitly deallocated using the free()
function when it is no longer needed. Failure to free() allocated memory leads
to memory leaks, where memory remains reserved but inaccessible, potentially
causing performance issues or program crashes over time.
*/

#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free

int main()
{
    // malloc() = A function in C that dynamically allocates a specified number
    // of bytes in memory

    // malloc() = uma funcao do C que aloca dinamicamente determinada quantia de
    // bytes na memoria

    // tamanho fixo
    // char notas[5] = {0};
    // mas e se nao sabemos o tamanho?

    int quantia = 0;
    printf("Insira a quantidade de notas: ");
    scanf("%d", &quantia);
    // %d indica que um valor sera tratado como inteiro decimal
    // %c indica que um valor sera tratado como caracter

    char* notas = malloc(quantia * sizeof(char));

    if (notas == NULL) {
        printf("Falha ao alocar memoria!\n");
        return 1;  // codigo de saida do programa
    }

    for (int i = 0; i < quantia; i++) {
        printf("Insira a nota: #%d: ", i + 1);
        scanf(" %c", &notas[i]);
    }

    for (int i = 0; i < quantia; i++) {
        printf("%c ", notas[i]);
    }

    free(notas);  // retornando o espaco 'alugado' na memoria pro OS
    notas =
        NULL;  // evita ponteiros pendentes, q sao ponteiros que apontam para um
               // local na memoria que nao eh mais utilizado ou ja foi liberado,
               // e tentar acessar uma memoria ja desalocada leva a undefined
               // behaviour(comp indefinido) que pode levar a falhas de
               // segmentacao, crashs, vulnerabilidades de seguranca etc

    return 0;
}
