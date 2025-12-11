// ESTRUTURA DE AUTOREFERENCIA e uma estrutura no qual contem um ponteiro para
// outra estrutura do mesmo tipo.
//
// struct abc {
// 	   int a;
// 	   char b;
// 	   struct abc *self;
//  };
//
// Nos usaremos essa estrutura para criar a NODE de uma SINGLE LINKED LIST.
// NODES sao structs que possuem dois membros: DADOS e LINKS
// sendo LINKS os ponteiros para alguma outra NODE.
//
// struct node {
// 	   data_type member1;
// 	   data_type member2;
// 	   		.
// 	   		.
// 	   		.
// 	   struct node *next;
// }
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int          data;
    struct node* next;
};

int main()
{
    struct node* head = NULL;
    head              = malloc(sizeof(struct node));

    head->data = 45;
    head->next = NULL;

    printf("%d", head->data);
    return 0;
}
