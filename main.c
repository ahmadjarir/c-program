#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data, prior;
    Node *next;
};
void insert_awal();
void insert_akhir();
void insert_before();
void alokasi();
void enqueue();
void dequeue();
void free_node(Node *);
void tampil();
Node *head = NULL , *p, *cari, *pbef, *hapus, *ph;

int main()
{
    printf("Queue With Priority\n");
    printf("1. Input a Queue Value (Enqueue)\n");
    printf("2. Output a Queue Value (Dequeue)\n");
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
    alokasi();
    cari = head;
    if(head == NULL)
        head = p;
    else
    {
        while(cari->prior <= p->prior)
        {
            if(cari->next == NULL)
                break;
            else{
                pbef = cari;
                cari = cari->next;
            }
        }
        if(cari->next==NULL && cari->prior <= p->prior)
            insert_akhir();
        else
            insert_before();
    }
}

void alokasi()
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
    puts("");
}
void insert_awal()
{
    p->next = head;
    head = p;
}
void insert_akhir()
{
    cari->next = p ;
    cari = p;
}

void insert_before()
{
    if(cari == head)
        insert_awal();
    else{
        p->next = cari;
        pbef->next = p;
    }
}
void dequeue()
{
    if(head==NULL)
        printf("Queue is empty!\n");
    else
    {
        printf("%d\n", head->data);
        cari=head;
        if(cari->next==NULL)
            head=NULL;
        else
            head=cari->next;
        free_node(cari);
    }
    printf("\n");
}
void free_node(Node *x)
{
    free(x);
    x = NULL;
}
