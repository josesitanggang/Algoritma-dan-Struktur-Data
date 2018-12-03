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

Bintree search(Bintree T,int x){
    
    if(!empty(T)){
        if(x==root(T)) return T;
        else if(x<root(T)) return search(left(T),x);
        else return search(right(T),x);
    }
     return NULL;
    
}

int height(Bintree T){
    if(empty(T)) return 0;
    else return max((1+height(left(T))),(1+height(right(T))));
}

int totalNode(Bintree T){
    if(empty(T)) return 0;
    else return 1+totalNode(left(T)) + totalNode(right(T));
}

void addLeafMost(Bintree *T, Bintree *L){
    if(empty(left(*T))) left(*T) = *L;
    else addLeafMost(&left(*T),L);
}

void delNode(Bintree *T,int x){
    if(empty(*T)) return;
    
    if(x==root(*T)){
        if(empty(left(*T)) && empty(right(*T))) {
            *T = NULL;
            return;
        }

        Bintree temp = *T;
        *T = right(*T);
        addLeafMost(T,&left(temp));
        temp = NULL;
    
    }
    else if(x>root(*T)) delNode(&right(*T),x);
    else delNode(&left(*T),x);
    
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
    // cout<<totalNode(root);
    // cout<<height(root);
    // cout<<search(root,60);
    // preorder(root);
    // delNode(&root,30);
    // cout<<"\n";
    preorder(root);
    return 0;
}

