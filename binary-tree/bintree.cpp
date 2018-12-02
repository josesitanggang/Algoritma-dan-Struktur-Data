#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct tnode* Bintree;
typedef struct tnode{
    int key;
    Bintree left;
    Bintree right;
} Node;


Bintree alloc(int x){
    Bintree new_node = (Bintree)malloc(sizeof(Node));
    if(new_node==NULL) return NULL;
    new_node->key = x;
    new_node->left = NULL;
    new_node->right = NULL;
} 

void makeBintree(Bintree *T){
    *T = NULL;
}


void preorder(Bintree t){
    if(t==NULL) return;
    preorder(t->left);
    cout<<t->key<<" ";
    preorder(t->right);
}

void insert(Bintree *node,int x){
    if((*node)==NULL) {
        (*node)=alloc(x);
        return;
    }
    if((*node)->key==x) {
        return;
    }
    
    if(x<((*node)->key)) insert(&((*node)->left),x);
    else insert(&((*node)->right),x);

}


int main(){
    Bintree root;
    makeBintree(&root);
    insert(&root,50);
    insert(&root, 30); 
    insert(&root, 20); 
    insert(&root,50);
    insert(&root, 40); 
    insert(&root, 70); 
    insert(&root, 60); 
    insert(&root, 80);
    preorder(root);
    return 0;
}

