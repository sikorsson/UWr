#include <stdio.h>
#include <stdlib.h>

typedef int Tkey;
typedef char Tval;

typedef struct Tnode {
    Tval val;
    Tkey key;
    struct Tnode *next;
} node;

void printList(node *start);
int listSize(node *start);
Tval search(node *start, Tkey key);
void insert(node **start, Tkey key, Tval val);
void delete_(node **start, Tkey key);


int main()
{
    node *start;
    start = (node *)malloc(sizeof(node));
    start = NULL;

    insert(&start, 20, 'a');
    insert(&start, 30, 'b');
    insert(&start, 40, 'c');
    insert(&start, 10, 'd');
    insert(&start, 25, 'e');
    insert(&start, 1, 'f');
    insert(&start, 15, 'g');
    Tval szukana = search(start, 20);
    printf("Szukana wartosc: %c\n", szukana);
    printList(start);
    delete_(&start, 25);
    printList(start);
    delete_(&start, 1);
    printList(start);
    return 0;
}

Tval search(node *start, Tkey key)
{
    if(start==NULL) printf("EMPTY\n");
    else
    {
        node *p=start;
        do {
            if(p->key==key)
            {
                return p->val;
            }
            p=p->next;
        }while (p!=NULL);
    }
}

void printList(node *start)
{
    if(start==NULL) printf("EMPTY\n");
    else
    {
        node *p = start;
        do {
            printf("%c %d\n", p->val, p->key);
            p = p->next;
        }while (p != NULL);
    }
    printf("\n");
}

int listSize(node *start)
{
    int temp = 0;
    if(start==NULL) return temp;
    else
    {
        node *p = start;
        do {
            temp++;
            p = p->next;
        }while (p != NULL);
    }
    return temp;
}

void insert(node **start, Tkey key, Tval val)
{
    if(listSize(*start)==0)
    {
        node *p;
        p = (node *)malloc(sizeof(node));
        p->key = key;
        p->val = val;
        p->next = (*start);
        *start=p;
    }
    else
    {
        int i = 0;
        node *p = *start;
        node *temp;
        while (p->next != NULL && p->next->key < key)
        {
            p = p->next;
            i++;
        }
        if(p->key == key)
        {
            p->val = val;
            return;
        }
        if(p->key > key && i == 0)
        {
            temp = (node *)malloc(sizeof(node));
            temp->key = key;
            temp->val = val;
            temp->next = (*start);
            *start=temp;
            return;
        }
        temp=p->next;
        p->next=(node *)malloc(sizeof(node));
        p->next->key = key;
        p->next->val = val;
        p->next->next = temp;
    }
}

void delete_(node **start, Tkey key)
{
    if(start==NULL) printf("EMPTY\n");
    else
    {
        node *p = *start;
        node *temp;
        if(p->key == key)
        {
            temp=NULL;
            temp=(*start)->next;
            free(*start);
            *start=temp;
            return;
        }
        while(p->next != NULL && p->next->key != key)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}



