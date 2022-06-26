#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

void printvalue(struct Node *p)
{
    while (p != NULL)
    {
        printf("Elements : %d\n", p->value);
        p = p->next;
    }
}
struct Node *addfirst(struct Node *head, int value)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->value = value;
    ptr->next = head;
    return ptr;
}

struct Node *addinmiddle(struct Node *head, int value, int index)
{
    struct Node *mid;
    mid = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p;
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    mid->value = value;
    mid->next = p->next;
    p->next = mid;

    return head;
}

struct Node *insetatend(struct Node *head, int value)
{
    struct Node *end;
    end = (struct Node *)malloc(sizeof(struct Node));
    end->value = value;
    struct Node *p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = end;
    end->next = NULL;

    return head;
}

struct Node *atnode(struct Node *head,struct Node *prevnode,int value)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=value;
    ptr->next=prevnode->next;
    prevnode->nex=ptr;
    return head;


}
//deleting the first elements 
struct Node *deletefirst(struct Node *head){
    struct Node  *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
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
    int number;
    printvalue(head);
    printf("Please Enter a number : ");
    scanf("%d", &number);
    head = addfirst(head, number);
    printvalue(head);
    int third;
    printf("Please Enter a number which you want to enter : ");
    scanf("%d",&third);
    int pos;
    printf("Please Enter whichc position you want to Enter : ");
    scanf("%d", &pos);
    head = addinmiddle(head, third, pos);
    printvalue(head);
    int last;
    printf("Please Enter whichc value you want to end enter the node : ");
    scanf("%d", &last);
    head = insetatend(head, last);
    printvalue(head);
    int node;
    printf("Please Enter the value : ");
    scanf("%d",&node);
    head=atnode(head,three,node);
    printvalue(head);
    deletefirst(head);
      printvalue(head);
}