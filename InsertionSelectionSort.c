#include <stdio.h>
#include <stdlib.h>
#define MAKS 255

void ins_array(int []);
void insertion_sort(int []);
void selection_sort(int []);
void swap(int *, int *);
void show(int []);
int n, m, c, s;

int main()
{
    int bil[MAKS], menu;
    printf("Menu\n1. Insertion sort\n2. Selection Sort\n3. Exit\n\n");
    do
    {
        printf("Masukkan menu: ");
        scanf("%d", &menu);
        fflush(stdin);
        if(menu<3)
        {
            ins_array(bil);
            printf("\nSebelum diurutkan: \n");
            show(bil);
        }
        switch(menu)
        {
            case 1: insertion_sort(bil); break;
            case 2: selection_sort(bil); break;
            case 3: printf("Bye!!\n"); exit(0); break;
            default: printf("Menu salah!\n\n"); break;
        }
        if(menu<3)
        {
            printf("Setelah diurutkan: \n");
            show(bil);
            printf("\nMovement: %d\n", m);
            printf("Count   : %d\n", c);
            if(menu==2)
                printf("Swap    : %d\n", s);
            printf("\n");
        }
    } while(menu!=3);
    return 0;
}
void ins_array(int bil[])
{
    int i;
    m=0;
    c=0;
    s=0;
    printf("\nMasukkan jumlah bilangan: ");
    scanf(" %d", &n);
    fflush(stdin);
    for(i=0; i<n; i++)
    {
        printf("Masukkan bilangan %d: ", i+1);
        scanf(" %d", &bil[i]);
        fflush(stdin);
    }
}
void insertion_sort(int x[])
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key=x[i];
        m++;
        for(j=i-1; x[j]>key && j>=0; j--)
        {
            x[j+1]=x[j];
            m++;
            c++;
        }
        if(x[i-1]<key)
            c++;
        x[j+1]=key;
        m++;
    }
}
void selection_sort(int x[])
{
    int i, j, min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(x[min]>x[j])
                min=j;
            c++;
        }
        swap(&x[i], &x[min]);
        s++;
        m+=3;
    }
}
void swap(int *x, int *y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}
void show(int x[])
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", x[i]);
    printf("\n");
}
