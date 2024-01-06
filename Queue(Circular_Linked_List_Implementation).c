#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

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

int IsEmpty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}


void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> val = value;
    newnode -> next = NULL;

//insertion is done from rear only
    if(rear == NULL)
    {
        front = newnode;
        rear = newnode;
        rear -> next = front;//circular implementation
    }

    else
    {
        rear -> next = newnode;
        rear = newnode;
        rear -> next = front;//circular implementation
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if(IsEmpty())
    {
        printf("Queue is empty\n\n");
        main();
    }
    else if(front == rear)
    {
        front = NULL;
        rear = NULL ;
        printf("The deleted element is %d\n", temp -> val);
        free(temp);
    }

    else
    {
        front = front -> next;
        rear -> next = front;//circular implementation

        printf("The deleted element is %d\n", temp -> val);
        free(temp);
        temp = NULL;

    }
}

void print()
{
    struct node *curr;
    curr = front;
    if(IsEmpty())
    {
        printf("Queue is empty\n\n");
        main();
    }
    else
    {
        printf("The elements are: ");
        while(curr -> next != front)
        {
            printf("%d ",curr-> val);
            curr = curr -> next;
        }
        printf("%d",curr-> val);//to print the final data
    }
    printf("\n");
}

