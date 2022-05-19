#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class BinaryTree;
class TreeNode{
public :
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    string str;
    TreeNode() : leftchild(0), rightchild(0), parent(0), str(""){};
    TreeNode(string s) : leftchild(0), rightchild(0), parent(0), str(s){};
    friend class BinaryTree;
};
class BinaryTree{
public :
    TreeNode *root;         
    BinaryTree() : root(0){};
    BinaryTree(TreeNode *node) : root(node){};
    void Inorder(TreeNode *current);
    void Swaptree(TreeNode *current){
        if(current == NULL) return;
	    TreeNode *temp = current -> leftchild;
	    current -> leftchild = current -> rightchild;
	    current -> rightchild = temp;
	    Swaptree(current -> leftchild);
	    Swaptree(current -> rightchild);
    }
};
void BinaryTree::Inorder(TreeNode *current){  //use inorder traversal to check whether we swap successfully
    if (current) {                          
        Inorder(current -> leftchild);        
        cout << current -> str << " ";   
        Inorder(current -> rightchild);       
    }
}
int main(){
    TreeNode *nodeA = new TreeNode("A"); TreeNode *nodeB = new TreeNode("B"); 
    TreeNode *nodeC = new TreeNode("C"); TreeNode *nodeD = new TreeNode("D"); 
    TreeNode *nodeE = new TreeNode("E"); TreeNode *nodeF = new TreeNode("F"); 
    TreeNode *nodeG = new TreeNode("G"); TreeNode *nodeH = new TreeNode("H"); 
    nodeA -> leftchild = nodeB; nodeA -> rightchild = nodeC; 
    nodeB -> leftchild = nodeD; nodeB -> rightchild = nodeE; 
    nodeE -> leftchild = nodeG; nodeE -> rightchild = nodeH; 
    nodeC -> leftchild = nodeF; 
    BinaryTree T(nodeA);
    cout << "before swap: " << endl;
    T.Inorder(T.root);
    cout << endl;
    cout << "after swap: " << endl;
    T.Swaptree(T.root);
    T.Inorder(T.root);
    cout << endl;
}