#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node* alloc(int x){
    struct  node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL) return NULL;
    new_node->key = x;
    new_node->left = NULL;
    new_node->right = NULL;
} 

void preorder(struct node* t){
    if(t==NULL) return;
    preorder(t->left);
    cout<<t->key<<" ";
    preorder(t->right);
}

struct node* insert(struct node* node,int x){
    if(node==NULL) return alloc(x);
    
    if(x<node->key) node->left = insert(node->left,x);
    else node->right = insert(node->right,x);

    return node;
}

int main(){
    struct node* root;
    root = alloc(50);
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    preorder(root);
}

