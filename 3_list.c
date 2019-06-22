//
//  main.c
//  3_list
//
//  Created by WoohyunSHIN on 24/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

/*
int main(){                     // 재귀 - 직접재귀 함수이다.
    printf("main호출\n");
    main();
}
*/
/*
#include <stdio.h>

int factorial(int n){
    if(n==0)            return 1;
    else if(n ==1)      return n;
    else                return factorial(n-1)*n;
}


int main(){
    for(int i=0;i<=7;i++){
        printf("%d! = %d\n",i,factorial(i));
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}Linklist;

Linklist* get_node(){
    Linklist* p;
    p=(Linklist*)malloc(sizeof(Linklist));
    p->link=NULL;
    return p;
};

void InsertNode(Linklist **head, int data){
    if(*head==NULL){
        *head=get_node();   //*head==head;
        (*head)->data=data;
        return;
    }
    InsertNode(&(*head)->link,data);
}

int main(){
    Linklist* head=NULL;
    
    InsertNode(&head,10);
    InsertNode(&head,20);
    InsertNode(&head,30);
}

