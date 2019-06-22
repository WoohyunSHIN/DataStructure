//
//  main.c
//  2_stack
//
//  Created by WoohyunSHIN on 23/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
    char data;
    struct node * link;
}stack;

stack* get_node()
{
    stack* tmp;
    tmp = (stack *)malloc(sizeof(stack));
    tmp->link = EMPTY;
    return tmp;
}

void push(stack **top, char data)
{
    stack* tmp;
    tmp = *top;
    *top = get_node();
    (*top)->data = data;
    (*top)->link = tmp;
}

char pop(stack **top)
{
    stack *tmp;
    char ch;
    tmp = *top;
    if (*top == EMPTY) {
        return 0;
    }
    ch = tmp->data;
    *top = (*top)->link;
    free(tmp);
    return ch;
}

int main()
{
    char check_passeword[8]="abcdefg";
    char string[8];
    int a;
    
    while(1){
        printf("암호를 입력하시오 : ");
        scanf("%s",string);
        
        stack * top = EMPTY;
        for(int i=0;i<8;i++){
            push(&top, string[i]);
        }
        
        for(int i=0;i<8;i++){
            string[i]=pop(&top);
        
            if(string[8]==check_passeword[8]){
                printf("암호가 맞습니다.");
                scanf("%d",&a);
            }
            
            else{
                printf("암호가 틀렸습니다. 다시 입력하세요.");
                scanf("%d",&a);
            }
            
        }
        
    }
    // 사용자로부터 문자열을 입력받는다.
    // 입력받은 문자열이 회문인지 판별하도록 코딩
    // 동적할당 스택을 활용
}


