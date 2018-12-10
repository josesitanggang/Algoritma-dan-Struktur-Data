#include <iostream>
#include "cpplib/bintree.h"

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
    delNode(&root,50);
    // cout<<"\n";
    // preorder(root);
    // inorder(root);
    // postorder(root);
    draw(root);
    return 0;
}

