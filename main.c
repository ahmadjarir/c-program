#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data, prior;
    Node *next;
};
void insert_first();
void insert_last();
void insert_before();
void allocation();
void enqueue();
void dequeue();
void free_node(Node *);
void tampil();
Node *head = NULL , *p, *search, *pbef;

int main()
{
    printf("Queue With Priority\n");
    printf("1. Push a Value (Enqueue)\n");
    printf("2. Pull a Value (Dequeue)\n");
    printf("3. Read Whole Queue (LIFO)\n");

    int menu;
    do
    {
        printf("\nInsert menu    : ");
        scanf(" %d", &menu);
        fflush(stdin);
        switch(menu)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: tampil(); break;
            case 4: printf("Bye!!\n"); exit(0); break;
            default: printf("Wrong Menu!\n");
        }
    } while(menu != 4);
    return 0;
}
void enqueue()
{
    allocation();
    search = head;
    if(head == NULL)
        head = p;
    else
    {
        while(search->prior <= p->prior)
        {
            if(search->next == NULL)
                break;
            else{
                pbef = search;
                search = search->next;
            }
        }
        if(search->next==NULL && search->prior <= p->prior)
            insert_akhir();
        else
            insert_before();
    }
}

void allocation()
{
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL)
        exit(0);
    printf("Insert value   : ");
    scanf("%d", &p->data);
    fflush(stdin);
    printf("Insert priority: ");
    scanf("%d", &p->prior);
    fflush(stdin);
    p->next = NULL;
}

void tampil()
{
    if(head==NULL)
        printf("Queue is empty!\n");
    else
    {
        Node *baca;
        baca = head;
        puts("\nData\tPriority");
        while(baca != NULL)
        {
            printf("%d\t%d\n", baca->data, baca->prior);
            baca = baca->next;
        }
    }
}
void insert_first()
{
    p->next = head;
    head = p;
}
void insert_last()
{
    search->next = p ;
    search = p;
}

void insert_before()
{
    if(search == head)
        insert_awal();
    else{
        p->next = search;
        pbef->next = p;
    }
}
void dequeue()
{
    if(head==NULL)
        printf("Queue is empty!\n");
    else
    {
        printf("Dequeue -> %d\n", head->data);
        search=head;
        if(search->next==NULL)
            head=NULL;
        else
            head=search->next;
        free_node(search);
    }
}
void free_node(Node *x)
{
    free(x);
    x = NULL;
}
