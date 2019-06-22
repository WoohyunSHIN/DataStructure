//
//  main.c
//  1_stack
//
//  Created by WoohyunSHIN on 18/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//
/*
#include <stdio.h>

int main(){
    
    int Stack[5]={0,0,0,0,0};
    int* Pstack[5];
    
    while(1){
        int select =0;
        
    printf("stack[4] : &d\n",*Pstack[4]);
    printf("stack[3] : %d\n",*Pstack[3]);
    printf("stack[2] : %d\n",*Pstack[2]);
    printf("stack[1] : %d\n",*Pstack[1]);
    printf("stack[0] : %d\n",*Pstack[0]);
    printf("=================================\n");
    printf("1.push\n");
    printf("2.pop\n");
    scanf("%d",&select);
    
    switch(select){
        case 1:
            for(int i=0;i<5;i++){
            printf("숫자를 입력해주세요 : ");
            scanf("%d",&Stack[i]);
            Pstack[i]=&Stack[i];
//            printf("입력하신 숫자는 %d",*Pstack[i]);
//            scanf("%d",&Stack[1]);
            break;
            }
        case 2: printf("입력하신숫자");
        
        
        
        }
    
    }
}
*/


#include <stdio.h>
#include <stdlib.h>
typedef struct _stack {
    int *stack;
    int size;
    int top;
}STACK, *PSTACK;

void push(PSTACK, int);
int pop(PSTACK);
PSTACK init_stack(int);

int main() {
    PSTACK stack = init_stack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d\n", pop(stack));
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    
    free(stack);
}

void push(PSTACK stack, int data) {
    if (stack->size == stack->top) {
        return;
    }
    stack->stack[stack->top] = data;
    stack->top++;
}

int pop(PSTACK stack) {
    if (stack->top == NULL) {
        return -1;
    }
    stack->top--;
    int data = stack->stack[stack->top];
    return data;
}

PSTACK init_stack(int size) {
    PSTACK stack = (PSTACK)malloc(sizeof(STACK));
    stack->size = size;
    stack->top = 0;
    stack->stack = (int*)malloc(sizeof(int)*size);
    return stack;
}
