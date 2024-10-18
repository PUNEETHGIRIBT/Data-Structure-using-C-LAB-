#include <stdio.h>

int arr[100], n, value, top = -1, choice;
void push();
void pop();
void display();

int main()
{
    printf("Enter a size of a array(Less than 100): ");
    scanf("%d", &n);
    
    do
    {
        printf("\nChoose a choice \n1.Push \n2.Pop \n3.Display \n4.Exit\n-- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting-----");
            return 0;
        default:
            printf("Invalid Option");
        }
    } while (choice != 4);

    return 0;
}

void push()
{
    if (top >= (n - 1))
    {
        printf("Stack is full ");
    }
    else
    {
        printf("Enter a element to push into stack :\n");
        scanf("%d", &value);
        arr[++top] = value;
        printf("%d pushed to stack",value);
    }
    return;
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Popped Element is %d \n", arr[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Elements in a array are : \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d \n", arr[i]);
        }
    }
}