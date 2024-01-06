#include <stdio.h>
#define MAX 5

int q[MAX], f =-1, r =-1;
int enqueue(int data)
{
    if(r+1 == MAX)
        printf("Queue is full.");
    else if(f == -1 && r == -1)
        {
        f = r = 0;
        q[r] = data;
        return q[r];
        }
        else
        {
            r++;
            q[r] = data;
            return q[r];
        }
}

int dequeue()
{
    int data;
    if(f == -1 && r == -1)
        printf("Queue is empty.");
    else if(f == r)
    {
        data = q[f];
        f = r = -1;
        return data;
    }
    else
    {
        data = q[f];
        f++;
        return data;
    }
}

void print()
{
   if(f == -1 && r == -1)
        printf("Queue is empty.");
    else
    {
        for(int i=f; i<r+1; i++)
            printf("%d ",q[i]);
        printf("\n");
    }
}

int main()
{
   int choice,value;
    printf("1. Create Queue (Enqueue)\n");
    printf("2. Delete node from Queue (Dequeue)\n");
    printf("3. Print Queue\n");
    printf("4. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element: ");
            scanf("%d",&value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            printf("%d has been deleted: ",value);
            break;

        case 3:
            print();
            break;

        case 4:
            exit(1);

        default:
            printf("Error!! The option is not found!!\n\n");
        }
    }
    return 0;
}



