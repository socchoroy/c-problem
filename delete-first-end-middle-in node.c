#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
// deleting the first elements
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// delete at any node you want
struct Node *deleteatany(struct Node *head, int index)
{
    struct Node *ptr;
    ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *q;
    q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

// delete value index
struct Node *delatevalue(struct Node *head, int value)
{
    struct Node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL && q->value != value)
    {
        q = q->next;
        p = p->next;
    }
    if (q->value == value)
    {

        p->next = q->next;
        free(q);
    }
    else
    {
        printf("sorry we didn't found it!\n");
    }
    return head;
}

// deleting at the end
struct Node *deletatend(struct Node *head)
{
    struct Node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// ptinting The value
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
    head = deletefirst(head);
    printvalue(head);
    int pos;
    printf("Pleas Enter which position : ");
    scanf("%d", &pos);
    head = deleteatany(head, pos);
    printvalue(head);
    printf("After deleting end elements\n");
    head = deleteatany(head, pos);
    printvalue(head);
    int lol;
    printf("Please Enter which value you want to delate : ");
    scanf("%d", &lol);
    head = delatevalue(head, lol);
    printvalue(head);
}