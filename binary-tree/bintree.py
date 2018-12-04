class Tree:
    def __init__(self,key):
        self.root = key
        self.left = None
        self.right = None
    
    def add(self,key):
        if self is None:
            return Tree(key)
        else:
            if(key<self.root):
                self.left = Tree.add(self.left,key)
            elif (key>self.root):
                self.right = Tree.add(self.right,key)
        return self

    def preorder(self):
        if self:
            print(self.root,end=" ")
            Tree.preorder(self.left)
            Tree.preorder(self.right)

    def draw(self,i=1):
        if self:
            print("|_"*i,"{}   lev.{}".format(self.root,i-1))
            Tree.draw(self.left,i+1)
            Tree.draw(self.right,i+1)

    def search(self,key):
        if self:
            if self.root == key:
                return self
            elif key<self.root :
                return Tree.search(self.left,key)
            elif key>self.root :
                return Tree.search(self.right,key)
        else:
            return False

    def __str__(self):
        return "\nroot : {root} \nleft : {left}  \nright: {right}".format(
            root=self.root,left=self.left,right=self.right
        )

if __name__ == "__main__":
    root = Tree(50)
    root.add(50)
    root.add(30) 
    root.add(20) 
    root.add(50)
    root.add(40) 
    root.add(70) 
    root.add(60) 
    root.add(80)
    # root.draw()
    print(root)