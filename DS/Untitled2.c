#include <stdio.h>
#include<stdlib.h>


int main(){
    struct node{
        char name[50];
        int rollno;
        long Phno;
        struct node *next;
    };

    struct node *head,*newnode,*temp;
    head= NULL;
    int choice;

    while (choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter name: ");
        scanf("%s",newnode->name);
        printf("Enter rollno: ");
        scanf("%d",&newnode->rollno);
        printf("Enter Phno: ");
        scanf("%ld",&newnode->Phno);

        newnode->next=NULL;

        if (head==NULL){
            head = temp =newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("Do you want to continue(0,1): ");
        scanf("%d",&choice);

    }
    temp=head;
    while(temp!=NULL){
        printf("\nName: %s\n",temp->name);
        printf("Rollno: %d\n",temp->rollno);
        printf("Phno: %ld\n", temp->Phno);
        temp=temp->next;
    }

    printf("\n");

    struct node *current= head;
    int i=1;
    int rollno;
    char name[50];
    long Phno;
    printf("Enter rollno to search: ");
    scanf("%d",&rollno);

    while(current!=NULL){
        if (i==rollno){
            printf("name is: %s\n",current->name);
            printf("Phone no is: %ld\n",current->Phno);
            break;
        }
        i++;
        current=current->next;

    }
    if(current==NULL){
        printf("index out of bounds \n");
    }

    printf("\n");
    int j=1;
    printf("Enter Phno to search: ");
    scanf("%ld",&Phno);

    struct node *currentt= head;
    while(currentt!=NULL){
        if (j==Phno){
            printf("name is: %s\n",currentt->name);
            printf("Phone no is: %d",currentt->rollno);
            break;
        }
        j++;
        currentt=currentt->next;

    }
    if(currentt==NULL){
        printf("index out of bounds \n");
    }
return 0;
}
