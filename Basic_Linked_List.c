#include<stdio.h>
#include<stdlib.h>
/*This program is just to show off the basic properties of 
 * linked list.All the functions are self explainatory.
 * */

struct node{
    int data;
    struct node *link;
}node;
struct node *head=NULL,*ptr=NULL,*new=NULL,*last=NULL,*temp=NULL;
int ch,key,g=0,i=0;

void insertfront();
void insertback();
void insertAtKey();
void deletefront();
void deleteback();
void deleteAtKey();
void traverse();

void createnode()
{
    printf("Enter the data to be entered");
    scanf("%d",&g);
    struct node* new =(struct node*)(malloc(sizeof(struct node)));
    new->data=g;
    new->link=NULL;
    last=head=new;
}

void main(){
    struct node* head =(struct node*)(malloc(sizeof(struct node)));
        while(1){
            printf("\nChoose any of the options:\n");
            printf("1.Insert at front\n");
            printf("2.Insert at back\n");
            printf("3.Insert after an element\n");
            printf("4.Delete at front\n");
            printf("5.Delete at back\n");
            printf("6.Delete specific element\n");
            printf("7.Traverse\n");
            printf("8.Exit\n");
            scanf("%d",&ch);
            switch(ch){
                case 1:     insertfront();
                            break;
                case 2:     insertback();
                            break;
                case 3:     insertAtKey();
                            break;
                case 4:     deletefront();
                            break;
                case 5:     deleteback();
                            break;
                case 6:     deleteAtKey();
                            break;
                case 7:     traverse();
                            break;
                case 8:     exit(0);
                default:    printf("Please enter a valid choice");
                            break;
            }
        }
}

void insertfront(){
    if(head==NULL){createnode();}
    else{
        struct node* new =(struct node*)(malloc(sizeof(struct node)));
    printf("Enter the data to be entered");
    scanf("%d",&g);
        new->data=g;
        new->link=head;
        head=new;
    }
}
void insertback(){
    if(head==NULL){createnode();}
    else{
    struct node* new =(struct node*)(malloc(sizeof(struct node)));
    printf("Enter the data to be entered");
    scanf("%d",&g);
        new->data=g;
        new->link=NULL;
        last->link=new;
        last=new;
    }
        
}

void insertAtKey(){
    int flag=0;
    if(head==NULL){
        printf("Sorry,Element is not found\n");
        printf("A new list has been created \n");
        createnode();
    }
    else{
        printf("Enter the element after which the data is to be entered");
        scanf("%d",&key);
        ptr=head;
        while(ptr->link!=NULL){
            if(ptr->data==key){
                flag=1;
                temp=ptr;
            }
            ptr=ptr->link;
        }
        if(flag==1){
            struct node* new =(struct node*)(malloc(sizeof(struct node)));
            printf("Enter the data to be entered");
            scanf("%d",&g);
            new->data=g;
            new->link=temp->link;
            temp->link=new;
        }
        else if(last->data==key){
            insertback();
        }
        else{
            printf("%d is not found",key);
        }
    }
}
    
void deletefront(){
    if(head==NULL){
        printf("The list is empty, please enter elements!");
    }
    else if(head->link==NULL){
        printf("%d is deleted",head->data);
        head->data=0;
        head=NULL;
    }
    else{
        printf("%d is deleted",head->data);
        head->data=0;
        head=head->link;
    }
}
void deleteback(){
    if(head==NULL){
        printf("The list is empty, please enter elements!");
    }
    else if(head->link==NULL){
        printf("%d is deleted",head->data);
        head->data=0;
        head=NULL;
    }
    else{
    ptr=head;
    while(ptr->link->link!=NULL){
        ptr=ptr->link;
    }
    printf("%d is deleted",ptr->link->data);
    ptr->link->data=0;
    last=ptr;
    ptr->link=NULL;
    }
}

void deleteAtKey(){
    int flag=0;
    if(head==NULL){
        printf("The list is empty, please enter elements!");
    }
    else{
        printf("Enter the element which is to be deleted");
        scanf("%d",&key);
        ptr=head;
        while(ptr->link!=NULL && ptr->data!=key){
                flag=1;
                temp=ptr;
                ptr=ptr->link;
        }
        if(flag==1){
            printf("%d is deleted",ptr->data);
            temp->link=ptr->link;
            ptr->data=0;
            ptr->link=NULL;
            if(ptr==last){
                last=temp;
            }
        }
        else if(flag==0 && head->data==key){
            deletefront();
        }
        
        else{
            printf("There is no such element, please try again");
        }
    }
}
void traverse(){
    i=1;
    ptr=head;
    while(ptr->link!=NULL){
        printf("Element %d :%d\n",i,ptr->data);
        ptr=ptr->link;
        i++;
    }
    printf("Element %d :%d\n",i,last->data);
}
    
