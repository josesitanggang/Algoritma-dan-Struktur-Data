#ifndef _BINTREE_H
#define _BINTREE_H
#include <stdlib.h>
using namespace std;

typedef int info;
typedef struct tnode* Bintree;
typedef struct tnode{
    info key;
    Bintree left;
    Bintree right;
} Node;

#define left(node)  (node)->left
#define right(node) (node)->right
#define root(node)  (node)->key
#define empty(node) (node==NULL)

Bintree alloc(info x){
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
    cout<<root(t)<<" ";
    preorder(left(t));
    preorder(right(t));
}

void inorder(Bintree t){
    if(empty(t)) return;
    inorder(left(t));
    cout<<root(t)<<" ";
    inorder(right(t));
}

void postorder(Bintree t){
    if(empty(t)) return;
    postorder(left(t));
    postorder(right(t));
    cout<<root(t)<<" ";
}

void insert(Bintree *node,info x){
    if(empty(*node)) {
        *node=alloc(x);
        return;
    }
    if(root(*node)==x)
        return;

    if(x<root(*node)) insert(&left(*node),x);
    else insert(&right(*node),x);
}

Bintree search(Bintree T,info x){
    
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

void delNode(Bintree *T,info x){
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

string genchar(string x, int n){
    string y ="";
    for(int i=0;i<n;i++) y+=x;
    return y;
}

void draw(Bintree T,int i=1){
    if(!empty(T)){
        printf("%s %d   lev.(%d)\n",genchar("|_",i).c_str(),root(T),i-1);
        draw(left(T),i+1);
        draw(right(T),i+1);
    }
}
#endif