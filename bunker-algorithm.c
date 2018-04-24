#include <stdio.h>
#include <stdlib.h>
#define MAKS 50

int resource();
int process();
void input_res();
void allocation();
void available_res();
void count_process();
int num_res, num_proc;
int res[MAKS], proc[MAKS][MAKS], max_proc[MAKS][MAKS], need_proc[MAKS][MAKS];
int main()
{
    num_res=resource();
    num_proc=process();
    input_res();
    allocation();
    available_res();
    return 0;
}

int resource()
{
    int res;
    printf("Input number of resource: ");
    scanf(" %d", &res);
    fflush(stdin);
    return res;
}
int process()
{
    int proc;
    printf("Input number of process : ");
    scanf(" %d", &proc);
    fflush(stdin);
    return proc;
}
void input_res()
{
    int i;
    printf("\n");
    for(i=0; i<num_res; i++)
    {
        printf("Input resource %d   : ", i+1);
        scanf(" %d", &res[i]);
        fflush(stdin);
    }
}
void allocation()
{
    int i, j;
    printf("%d %d\n\n", num_res, num_proc);
    for(i=0; i<num_res; i++)
    {
        for(j=0; j<num_proc; j++)
        {
            printf("Input alloc of process     [%d][%d]: ", i+1, j+1);
            scanf(" %d", &proc[i][j]);
            fflush(stdin);
            printf("Input max alloc of process [%d][%d]: ", i+1, j+1);
            scanf(" %d", &max_proc[i][j]);
            fflush(stdin);
            if(max_proc[i][j]<proc[i][j])
            {
                printf("Process alloc is bigger than max! Input again.\n");
                j--;
            }
            else
            {
                need_proc[i][j]=max_proc[i][j]-proc[i][j];
            }
        }
        need_proc[i][j]=0;
        printf("\n");
    }
}
void available_res()
{
    int i, j;
    for(i=0; i<num_res; i++)
    {
        for(j=0; j<num_proc; j++)
        {
            res[j]-=proc[i][j];
        }
    }
    printf("\nAvailable Resource:\n");
    for(i=0; i<num_res; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
}
void count_process()
{
    int i, j;
    for(i=0; i<num_res; i++)
    {
        for(j=0; j<num_proc; j++)
        {

        }
    }
}
