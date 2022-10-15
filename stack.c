#include <stdio.h>
#include <stdlib.h>
struct node{
       int data;
       struct node* next;
}; 

struct stack{
      struct node* top;  
      int size;    
} ;

struct stack* initialize_stack(){
       struct stack* S=(struct stack*)malloc(sizeof(struct stack)); 
       S->top=NULL;
       return S;
} 

struct node* allocate_node(int val){
       struct node* new=(struct node*)malloc(sizeof(struct node)); 
       new->data=val; 
       new->next=NULL;
       return new;
}

void insert_front(struct node** head,int val){ 

     struct node *new=allocate_node(val), *temp=*head;
     new->next=temp; 
     *head=new;
}

int isEmpty(struct stack*S){
    if (S->top==NULL){
       return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack*S){
    int curr_size=0;
    struct node* temp=S->top;
    while (temp!=NULL){
        curr_size++;
        temp=temp->next;
    } 
    if (curr_size==S->size){
        return 1;
    } 
    else{
        return 0;
    }
}

void push(struct stack* S,int val){ 
     if (isFull(S)){ 
         printf("STACK FULL !!!");

     } 
     else{
          insert_front(&(S->top),val);
     }
     
     
}

void peek(struct stack* S){  
    if (isEmpty){
        printf("STACK EMPTY\n");
    } 
    else{
         printf("%d\n",S->top->data); 
    }
}


void free_stack(struct stack* S){ 
     struct node* temp=S->top; 
     while(temp!=NULL){ 
          temp=temp->next; 
          free(S->top);
          S->top=temp;
     } 
     free(S);

}

int pop(struct stack* S){  
    if (isEmpty(S)){
       printf("STACK EMPTY\n");  


    } 
    else{ 
        struct node* temp= S->top;
        int popped_ele=S->top->data;
        S->top=S->top->next;   
        free(temp);
        return popped_ele;
    }


}

void print_stack(struct stack* S){ 
     struct node* temp= S->top; 
     while (temp!=NULL){ 
            printf("%d ",temp->data);
            temp=temp->next;
     } 
    printf("\n");

}

int main(){  
    
    struct stack* S=initialize_stack(); 
    int size;
    printf("enter size of stack: ");
    scanf("%d",&size);
    S->size=size;  
    push(S,0); 
    // push(S,1);  
    // push(S,2);
   // print_stack(S);
    int x=pop(S); 
    x=pop(S);
    //printf("%d\n",x); 
    // x=pop(S);
    // x=pop(S) ;
    //printf("%d\n", x); 
    // x=pop(S) ;
    printf("%d\n", x); 
    // push(S,5); 
    // push(S,6); 
    // peek(S); 
    // print_stack(S);
    free_stack(S);

    return 0;
    
}
