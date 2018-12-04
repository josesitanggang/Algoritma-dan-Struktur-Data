class Node:
    def __init__(self,key):
        self.root = key
        self.left = None
        self.right = None

    def __str__(self):
        return "\nroot : {root} \nleft : {left}  \nright: {right}".format(
            root=self.root,left=self.left,right=self.right
        )

def add(node,key):
    if node is None:
        return Node(key)
    else:
        if(key<node.root):
            node.left = add(node.left,key)
        elif (key>node.root):
            node.right = add(node.right,key)
    return node

def preorder(node):
    if node:
        print(node.root,end=" ")
        preorder(node.left)
        preorder(node.right)

def draw(node,i=1):
    if node:
        print("|_"*i,"{}   lev.{}".format(node.root,i-1))
        draw(node.left,i+1)
        draw(node.right,i+1)

def search(node,key):
    if node:
        if node.root == key:
            return node
        elif key<node.root :
            return search(node.left,key)
        elif key>node.root :
            return search(node.right,key)
    else:
        return False

if __name__ == "__main__":
    root = Node(50)
    add(root,50)
    add(root, 30) 
    add(root, 20) 
    add(root,50)
    add(root, 40) 
    add(root, 70) 
    add(root, 60) 
    add(root, 80)
    # preorder(root)
    # draw(root)
    # a = search(root,40)
    # draw(a)
    # print("\n",root)