//
//  main.c
//  6_queue
//
//  Created by WoohyunSHIN on 31/01/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* link;
}QUEUE;

// Queue 는 First Input First Output 사용
// Front, Rear 사용
void enqueue(QUEUE** front, QUEUE** rear, int data){
    QUEUE* p=NULL;
    // Queue에 값을 삽입.
    if((*front) == NULL){
        p=(QUEUE*)malloc(sizeof(QUEUE));
        p->data=data;
        p->link=NULL;
        (*front)=p;
        (*rear)=p;
    }
    
    else if((*front) != NULL){
        p=(QUEUE*)malloc(sizeof(QUEUE));
        p->data=data;
        p->link=NULL;
        (*rear)->link=p;
        (*rear)=p;
    }
}

int dequeue(QUEUE** front){
    int result =0;
    QUEUE* tmp;
    // Queue에 값을 반환

    if((*front)->link == NULL){
        result=(*front)->data;
        free(*front);
    }
    
    else if((*front)->link != NULL){
        result=(*front)->data;
        tmp=(*front)->link;
        free(*front);
        *front=tmp;
    }
    
    return result;
}

/*
QUEUE* get_node(){
    QUEUE* p=NULL;
    p=(QUEUE*)malloc(sizeof(QUEUE));
}
*/

int main(){
    QUEUE* front = NULL;
    QUEUE* rear = NULL;
    
    enqueue(&front,&rear,10);
    enqueue(&front,&rear,20);
    enqueue(&front,&rear,30);
    printf("%d\n",dequeue(&front));
    printf("%d\n",dequeue(&front));
    printf("%d\n",dequeue(&front));
}
