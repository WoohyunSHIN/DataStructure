//
//  main.c
//  4_list
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
    InsertNode(&(*head)->link,data);        // bounus 재귀로 만들지 말고 반복문으로 해서 만들어라
}

void InsertNode2(Linklist** head,int check_data, int data){
    Linklist* tmp;

    // 10과 20 사이에 넣을려면 가능하나 그게 아니면 불가능 하다.
    if((*head)->data==check_data){
        tmp=(*head)->link;
        (*head)->link=get_node();
        (*head)->link->data=data;
        (*head)->link->link=tmp;
        return;
    }
    // 아래의 문장을 넣음으로 써 위의 문제를 해결시킨다.
    InsertNode2(&(*head)->link,check_data,data);
}

void Printlist(Linklist* head){
    while(head){
        printf("%d->",head->data);
        head = head->link;
    }
}

//첫 번째 삽입
void FirstInsert(Linklist** head,int data){
    Linklist* tmp = (*head);
    (*head)=get_node();
    (*head)->data=data;
    (*head)->link=tmp;
}

//검색기능
void Search(Linklist** head,int target){
    // 기능에서 첫번쨰 해야 할 것은
    /*
     if(*head==NULL){
     printf("It has not data in the head!!\n");
     }
     */

    if (*head==NULL){
        printf("\n찾으시는 데이터가 없습니다!! \n");
        return;
    }
    
    else if((*head)->data==target){
        printf("\n찾으시는데이터 %d 가 존재합니다\n",(*head)->data);
        return;
    }
    
    Search(&(*head)->link,target);

}

void Part_delete(Linklist** head, int delete){
    Linklist* tmp;
    
    if(*head==NULL){
        printf("찾으시는 숫자가 없습니다.\n");
        return;
    }
    
    else if((*head)->data==delete){
        tmp=(*head)->link;
        *head=tmp;
        return;
    }
    
    Part_delete(&(*head)->link,delete);
}


void All_delete(Linklist** head){
    Linklist* tmp;
    Linklist* tmp1;
    
    if(*head==NULL){
        return;
    }
    
    tmp = (*head)->link;
    
    for(;tmp!=NULL;){
        tmp1=(*head)->link;
        free(tmp);      // tmp 가 가리키는 지역(=주소)로 가서 heap 에 있는 공간을 밀어버려라(=해제) 라는 뜻임.
        tmp=tmp1;
        }
}


int main(){
    Linklist* head=NULL;
    
    InsertNode(&head,10);
    InsertNode(&head,20);
    InsertNode(&head,30);
    InsertNode2(&head,20,15);
    FirstInsert(&head,5);
    Part_delete(&head,20);
//    All_delete(&head);
    Printlist(head);
//    Search(&head,4);
    
    
}



//삭제기능
//전체삭제
/*옵션
1. 길이
2. 리스트의 중복 값 제어
*/
