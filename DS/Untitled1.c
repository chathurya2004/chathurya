#include <stdio.h>
#include <stdlib.h>

int main (){
    struct node{
        long data;
        struct node* next;
    };

    struct node *head,*newnode,*temp;

    head= NULL;
    int choice;
    while (choice){
        newnode= (struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d ",&newnode->data);
        newnode->next= 0;

        if (head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (0,1): ");
        scanf("%d",&choice);

    }

    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");

    struct node *prevnode,*currentnode,*nextnode;
    int Pos;
    printf("enter Pos: ");
    scanf("%d",&Pos);
    int i=1;
    prevnode=0;
    currentnode=nextnode=head;
    while(i<Pos){
        nextnode= nextnode->next;
        currentnode->next = prevnode;
        prevnode= currentnode;
        currentnode= nextnode;
        i++;

    }

    head= prevnode;

temp=head;
while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->next;
}

return 0;

}
