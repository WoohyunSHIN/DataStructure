//
//  main.c
//  5_list
//
//  Created by WoohyunSHIN on 24/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

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

void Printlist(Linklist* head){
    while(head){
        printf("%d->",head->data);
        head = head->link;
    }
}

int toArray(Linklist** head){
    for(int cnt=0;(*head)->link == NULL;cnt++){
        toArray(&(*head)->link);
        printf("%d",cnt);
    }
    /*
    Pointer = (int*)malloc(sizeof(int)*cnt);
     
     for(int i=0;i<cnt;i++){
         Pointer[i] = (*head)->data;
     }
     */
    return; 
}



int main(){
    Linklist* head=NULL;
    
    InsertNode(&head,2);
    InsertNode(&head,4);
    InsertNode(&head,6);
    InsertNode(&head,3);
    InsertNode(&head,5);
    Printlist(head);
    


    
}



//삭제기능
//전체삭제
/*옵션
 1. 길이
 2. 리스트의 중복 값 제어
 */

