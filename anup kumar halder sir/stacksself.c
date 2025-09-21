#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack * next;
};
int top=-1;
int size=0;
struct stack* head;
void createStack(int sie){
    size=sie;
}
struct stack* createpart(int value){
    struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
      if (!newStack) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newStack->data=value;
    newStack->next=NULL;
    return newStack;
}
int isEmpty(){
    return top==-1;
}
int isfull(){
    return top==size-1;
}

void push(int value){
    if(!(isfull())){
        struct stack* newStack=createpart(value);
        if(head==NULL){
            head=newStack;
            top++;
            return;
        }
        struct stack* temp =head;
        head = newStack;
        newStack->next=temp;
        free(temp);
        top++;
        return;

    }
}
void pop(){
    if(!(isEmpty)){
        struct stack* temp =head;
        head=head->next;
        free(temp);
    }
}
int peek(){
    if(!(isEmpty)){
        return head->data;
    }
}