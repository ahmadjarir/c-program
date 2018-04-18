#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

typedef char dataType;
typedef struct
{
    dataType data[MAKS];
    int count, rear, front;
} queue;

void inisialisasi(queue *);
void enqueue(dataType, queue *);
dataType dequeue(queue *);
int full(queue *);
int empty(queue *);
dataType isi();

void isiq(queue *);
void baca(queue *);
void tampil(queue *);

int main()
{
    printf("Menu Queue\n");
    printf("1. Isi Queue (Enqueue)\n");
    printf("2. Baca Queue (Dequeue)\n");
    printf("3. Tampilkan Queue (LIFO)\n\n");
    queue datax;
    int menu;
    inisialisasi(&datax);
    do
    {
        printf("Masukkan menu: ");
        scanf(" %d", &menu);
        fflush(stdin);
        switch(menu)
        {
            case 1: enqueue(isi(), &datax); break;
            case 2: baca(&datax); break;
            case 3: tampil(&datax); break;
            case 4: printf("Bye!!\n"); exit(0); break;
            default: printf("Menu salah!\n"); break;
        }
    } while(menu != 4);
    return 0;
}

void isiq(queue *q)
{
    if(full(q))
        printf("Queue penuh!\n");
    else
        enqueue(isi(), q);
}
void baca(queue *q)
{
    if(empty(q))
        printf("Queue kosong!\n");
    else
        printf("%c\n", dequeue(q));
}
void tampil(queue *q)
{
    int c, i;
    c=q->count;
    if(c==0)
        printf("Queue kosong!\n");
    else
    {
        while(c!=0)
        {
            if(q->front < q->rear)
            {
                for(i=q->front; i<q->rear; i++)
                {
                    printf("%c\n", q->data[i]);
                    c--;
                }
            }
            else
            {
                for(i=q->front; i<MAKS; i++)
                {
                    printf("%c\n", q->data[i]);
                    c--;
                }
                for(i=0; i<q->rear; i++)
                {
                    printf("%c\n", q->data[i]);
                    c--;
                }
            }
        }
    }
}

void inisialisasi(queue *q)
{
    q->count=0;
    q->front=0;
    q->rear=0;
}

dataType isi()
{
    dataType x;
    printf("Masukkan data: ");
    scanf(" %c", &x);
    fflush(stdin);
    return x;
}

void enqueue(dataType x, queue *q)
{
    if(full(q))
        printf("Queue penuh!\n");
    else
    {
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%MAKS;
        ++(q->count);
    }
}

dataType dequeue(queue *q)
{
    if(empty(q))
    {
        printf("Queue kosong!\n");
        return 99;
    }
    else
    {
        int data=q->data[q->front];
        q->front=(q->front+1)%MAKS;
        --(q->count);
        return data;
    }
}
int full(queue *q)
{
    return (q->count==MAKS);
}
int empty(queue *q)
{
    return (q->count==0);
}
