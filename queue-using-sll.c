#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

typedef struct Queue queue;
typedef char dataType;

struct Queue
{
    dataType data;
    queue *next;
};

void tampil();
void alokasi();
void insert_akhir();
void delete_awal();
void free_node(queue *);

queue *p=NULL, *datax=NULL, *rear=NULL, *front=NULL;
int main()
{
    printf("Menu Queue\n");
    printf("1. Isi Queue (Enqueue)\n");
    printf("2. Baca Queue (Dequeue)\n");
    printf("3. Tampilkan Queue (LIFO)\n\n");

    int menu;
    do
    {
        printf("Masukkan menu: ");
        scanf(" %d", &menu);
        fflush(stdin);
        switch(menu)
        {
            case 1: insert_akhir(); break;
            case 2: delete_awal(); break;
            case 3: tampil(); break;
            case 4: printf("Bye!!\n"); exit(0); break;
            default: printf("Menu salah!\n");
        }
    } while(menu != 4);
    return 0;
}

void alokasi()
{
    p=(queue *)malloc(sizeof(queue));
    if(p==NULL)
        printf("Malloc error\n");
    else
    {
        printf("Masukkan data: ");
        scanf(" %c", &p->data);
        p->next=NULL;
    }
}

void insert_akhir()
{
    alokasi();
    if(datax==NULL)
    {
        datax=p;
        rear=datax;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}

void delete_awal()
{
    if(datax==NULL)
        printf("Queue kosong!\n");
    else
    {
        printf("%c\n", datax->data);
        front=datax;
        if(datax->next==NULL)
            datax=NULL;
        else
            datax=datax->next;
        free_node(front);
    }
}

void free_node(queue *q)
{
    free(q);
    q=NULL;
}

void tampil()
{
    queue *baca;
    baca=datax;
    if(datax==NULL)
        printf("Queue kosong!\n");
    else
    {
        while(baca!=NULL)
        {
            printf("%c->", baca->data);
            baca=baca->next;
        }
        printf("\b\b\n");
    }
}
