#include <stdio.h>  
#include <stdlib.h> 
#include <assert.h>
struct node{
       int data;
       struct node* next;
};

struct node* allocate_node(int val){
       struct node* n=(struct node *)malloc(sizeof(struct node)); 
       n->data=val; 
       n->next=NULL;
       return n;
} 

void print_list(struct node* head){ 
    struct node* temp= head; 
    while (temp !=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
    }
    printf("\n");

}

void insert_front(struct node **head ,int val){ 
       struct node*tmp = allocate_node(val);
       tmp->next=*head ;
       *head=tmp;

} 

void insert_rear(struct node* head,int val){
     struct node* tmp=head;
     while (tmp->next!=NULL){
           tmp=tmp->next;
     } 
     tmp->next=allocate_node(val);
}
 
void insert_pos(struct node*head , int val, int pos){ 
     struct node* tmp=head;
     int it=0; 
     while (it!=pos-1){ 
         tmp=tmp->next; 
         it++;
     }  
     if (tmp->next!=NULL){
        struct node *n=allocate_node(val);
        n->next=tmp->next; 
        tmp->next=n; 
     }

}
 

void delete(struct node* head,int val){
     struct node * tmp=head; 
     assert (tmp->next!=NULL);
     while (tmp->next->data !=val){
         tmp=tmp->next;
     } 
     tmp->next=tmp->next->next;
}
 
void reverse_list(struct node** head){  
     struct node* tmp=*head;
     struct node* prev=*head;
     struct node* curr=*head;
     struct node* nxt=tmp->next ;
     while (curr !=NULL){
           curr=nxt; 
           if (curr!=NULL){
                nxt=curr->next; 
                curr->next=prev;
                prev=curr; 
           }

     } 
     tmp->next=NULL;
     *head=prev;
}

int main(){ 
    int x; 
    struct node* temp;
    printf("Print value for head element: ");
    scanf("%d",&x);
    struct node* head; 
    head= allocate_node(x); 
    temp =head; 

    for (int i=0;i<5;i++){ 
        scanf("%d",&x); 
        insert_front(&head,x); 
    }   
    print_list(head);
    insert_pos(head,69,4); 
    print_list(head); 
    delete(head,2);  
    print_list(head);
    reverse_list(&head);
    print_list(head);
}
