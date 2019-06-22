//
//  main.c
//  8_tree
//
//  Created by WoohyunSHIN on 07/02/2019.
//  Copyright © 2019 Woo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    struct _node* llink;
    int data;
    struct _node* rlink;
}BSTREE;

BSTREE* get_node(){
    BSTREE * tmp = (BSTREE*)malloc(sizeof(BSTREE));
    tmp->data = 0;
    tmp->llink = NULL;
    tmp->rlink = NULL;
    return tmp;}

void insert_node(BSTREE** root, int data){
    if((*root) == NULL){
        *root = get_node();
        (*root)->data = data;
        return;
    }
    
    else{
        if((*root)->llink == NULL && (*root)->rlink == NULL){
            if((*root)->data > data){               // root 보다 작으면 왼쪽
                (*root)->llink = get_node();
                (*root)->llink->data = data;
            }
            
            else if((*root)->data < data){          // root 보다 크면 오른쪽
                (*root)->rlink = get_node();
                (*root)->rlink->data = data;
            }
        }
        
        else if((*root)->llink != NULL && (*root)->rlink == NULL){
            if((*root)->data > data){               // root 보다 작으면 왼쪽
                insert_node(&(*root)->llink, data);
            }
            
            else if((*root)->data < data){          // root 보다 크면 오른쪽
                (*root)->rlink = get_node();
                (*root)->rlink->data = data;
            }
        }
        
        else if((*root)->llink == NULL && (*root)->rlink != NULL){
            if((*root)->data > data){               // root 보다 작으면 왼쪽
                (*root)->llink = get_node();
                (*root)->llink->data = data;
            }
            
            else if((*root)->data < data){          // root 보다 크면 오른쪽
                insert_node(&(*root)->rlink, data);
            }
        }
        
        else{
            if((*root)->data > data){               // root 보다 작으면 왼쪽
                 insert_node(&(*root)->llink, data);
            }
            
            else if((*root)->data < data){          // root 보다 크면 오른쪽
                insert_node(&(*root)->rlink, data);
            }
        }
        
        /*[Prof]
        if((*root)->data > data){               // root 보다 작으면 왼쪽
         insert_node(&(*root)->llink,data);
        }
        else {                                  // root 보다 크면 오른쪽
            insert_node(&(*root)->llink,data);
         }
         }
        */
    }
}

void search(BSTREE** root,int target){

    if(*root == NULL){
        printf("찾으시는 숫자가 없습니다.\n");
        return;
    }
    
    if((*root)->data > target){
        search(&(*root)->llink, target);
    }
    else if((*root)->data < target){
        search(&(*root)->rlink, target);
    }
    else if((*root)->data == target){
        printf("찾는 숫자 : %d 가 있습니다.\n",(*root)->data);
        return;
    }
    else{
        printf("찾으시는 숫자가 없습니다.\n");
        return;
    }
  
}

// 전위순회
void pre_order(BSTREE* root){
    if(root){
        printf("%d->",root->data);
        pre_order(root->llink);
        pre_order(root->rlink);
    }
}

// 중위순회
void in_order(BSTREE* root){
    if(root){
        in_order(root->llink);
        printf("%d->",root->data);
        in_order(root->rlink);
    }
}

// 후위순회
void post_order(BSTREE* root){
    if(root){
        post_order(root->llink);
        post_order(root->rlink);
        printf("%d->",root->data);
    }
}

void delete(BSTREE** root,int target){
    BSTREE* tmp=NULL;
    BSTREE* tmp_right=NULL;
//    BSTREE* tmp=(*root);
    
    if((*root) == NULL){
        return;
    }
    
    if((*root)->data > target){
        delete(&(*root)->llink, target);
    }
    else if((*root)->data < target){
        delete(&(*root)->rlink, target);
    }
    else if((*root)->data == target){
        // CHILD 가 없을 때 (작동 X)
        if((*root)->llink == NULL && (*root)->rlink == NULL){
            free(*root);
            return;
        }
        
        // CHILD 가 1개 일 때 (작동 O)
        else if((*root)->llink == NULL && (*root)->rlink != NULL){
            *root = (*root)->rlink;
        }
        else if((*root)->llink != NULL && (*root)->rlink == NULL){
            *root = (*root)->llink;
        }
        
        // CHILD 가 2개 일 때 (작동 X)
        /*else{
            tmp_right = (*root)->rlink;
            
            if(tmp_right->llink != NULL){
                while(tmp_right->llink!=NULL){
                    tmp_right = tmp_right->llink;
                }
                (*root)->data = tmp_right->data;
                tmp_right = tmp_right->rlink;
            }
        }*/
    }
    else{
        printf("찾는 대상이 없습니다.");
        return;
    }
}


int main(){
    BSTREE* root = NULL;
    int data[20] = { 45, 27, 17, 62, 57, 73, 52, 65, 76, 69, 63, 64, 71 };
    
    // 모든 숫자 기입
    for (int i = 0; data[i] > 0; i++) {
        insert_node(&root, data[i]);
    }
    
    // Preorder
    // 45-27-17-62-57-52-73-65-63-64-69-71-76
//    pre_order(root);
//    printf("\n");
    
    // Inorder (오름차순)
    // 17-27-45-52-57-62-63-64-65-69-71-73-76
    delete(&root, 62);
    in_order(root);
    printf("\n");
    
    // Postorder
    // 17-27-52-57-64-63
//    post_order(root);
//    printf("\n");
   
    for (int i=0;data[i]>0;i++){
        search(&root, data[i]);
    }

    

}
