#include <stdio.h>

#define n 100 


void insert(int val);
void delete();
void display();
int front = -1,rear = -1;
int queue[n];

int main()
{
    int option,val;
    do{
        printf("Enter an option: \n1.insert \n2.delete \n3.display \n4.exit \n---");
        scanf("%d",&option);
        printf("-----");
        switch(option){
            case 1:
                printf("\nEnter an element to insert into queue: ");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                 display();
                 break;
            case 4:
                 return 0;
            default: printf("Invalid option !");
        }
    }while(option != 4);
        return 0;
}


void insert(int val){
        if(front == 0 && rear ==(n-1) ){
            printf("Queue if full");
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
        }
        else{
            rear++;
        }
        printf("%d addded to queue\n",val);
        queue[rear] = val;
}

void delete(){
    if( (front == -1 && rear == -1) || front > rear){
        printf("Underflow \n");
    }
    else{
        int delval = queue[front];
        printf("Deleted element is %d \n",delval);
        front++;
    }
}

void display(){
    if(( front == -1 && rear == -1) || front > rear ){
        printf("Queue is Empty\n ");
        return;
    }
    printf("Element in queue are: \n");
    for(int i = front; i <= rear; i++){
        printf("%d",queue[i]);
        printf("\n");
    }
    printf("\n");
}

