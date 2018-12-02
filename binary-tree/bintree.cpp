#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct tnode* Bintree;
typedef struct tnode{
    int key;
    Bintree left;
    Bintree right;
} Node;

#define left(node)  (node)->left
#define right(node) (node)->right
#define root(node)  (node)->key
#define empty(node) (node==NULL)

Bintree alloc(int x){
    Bintree new_node = (Bintree)malloc(sizeof(Node));
    if(empty(new_node)) return NULL;
    root(new_node) = x;
    left(new_node) = NULL;
    right(new_node) = NULL;
    return new_node;
} 

void makeBintree(Bintree *T){
    *T = NULL;
}


void preorder(Bintree t){
    if(empty(t)) return;
    preorder(left(t));
    cout<<root(t)<<" ";
    preorder(right(t));
}

void insert(Bintree *node,int x){
    if(empty(*node)) {
        *node=alloc(x);
        return;
    }
    if(root(*node)==x) {
        return;
    }
    
    if(x<root(*node)) insert(&left(*node),x);
    else insert(&right(*node),x);

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

