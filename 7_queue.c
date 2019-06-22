//
//  main.c
//  7_queue
//
//  Created by WoohyunSHIN on 31/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct D_link{
    struct D_link* prev;
    int data;
    struct D_link* next;
}DB;

void Insert(DB** head, int data){
    DB* p = NULL;
    
    if((*head)==NULL){
        p=(DB*)malloc(sizeof(DB));
        p->data=data;
        p->prev=NULL;
        p->next=NULL;
        *head=p;
    }

    else if((*head)->next==NULL){
        p=(DB*)malloc(sizeof(DB));
        p->next=NULL;
        p->data=data;
        p->prev=(*head);
        (*head)->next=p;
    }
    
    else if((*head)->next!=NULL){
        Insert(&(*head)->next,data);
    }
}

void Show_front(DB** head){
    DB* first = (*head);
    while(first){
        printf("%d->", first->data);
        first = first->next;
    }
    
}

void Show_tail(DB** head){
    DB* last = NULL;
    
    if((*head)->next != NULL){
        (*head)=(*head)->next;
        Show_tail(&(*head));
    }
    else if((*head)->next == NULL){
        last=(*head);
    }
    printf("\n");
    
    while(last){
        printf("<-%d", last->data);
        last = last->prev;
    }
}

void Delete_Part(DB** head,int target){
    DB* tmp_prev=NULL;
    DB* tmp_next=NULL;
    
    if((*head)->prev == NULL && (*head)->data==target){
        tmp_next=(*head)->next;
        free(*head);
        *head=tmp_next;
    }
       /*
    else if((*head)->next==NULL){
           
       }
    
    else{
        if((*head)->data == target){
            tmp_prev=(*head)->prev;
            tmp_next=(*head)->next;
            
        }
        else{
            Delete_Part(&(*head)->next, target);
        }
    }
*/
}


int main(){
    DB* head = NULL;
    
    Insert(&head,10);
    Insert(&head,20);
    Insert(&head,30);
    Insert(&head,40);
    Delete_Part(&head, 10);
    
    
    Show_front(&head);
    Show_tail(&head);

    
    
}
