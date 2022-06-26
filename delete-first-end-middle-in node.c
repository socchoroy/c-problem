#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
//deleting the first elements 
struct Node *deletefirst(struct Node *head){
    struct Node  *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//ptinting The value
void printvalue(struct Node *p)
{
    while (p != NULL)
    {
        printf("Elements : %d\n", p->value);
        p = p->next;
    }
}
int main()
{
    struct Node *head, *one, *two, *three, *four;
    head = (struct Node *)malloc(sizeof(struct Node));
    one = (struct Node *)malloc(sizeof(struct Node));
    two = (struct Node *)malloc(sizeof(struct Node));
    three = (struct Node *)malloc(sizeof(struct Node));
    four = (struct Node *)malloc(sizeof(struct Node));
    // intialize head value and address.
    head->value = 9;
    head->next = one;
    // intialize one value
    one->value = 11;
    one->next = two;
    // intialize two value
    two->value = 12;
    two->next = three;
    // intialize three value
    three->value = 13;
    three->next = four;
    // intialize fourth value
    four->value = 14;
    four->next = NULL;
      printvalue(head);
      printf("After deleting the value \n");
    head=deletefirst(head);
      printvalue(head);
}