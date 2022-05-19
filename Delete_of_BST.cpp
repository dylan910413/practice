#include <iostream>
#include <vector>
#include <list>
#include <utility>      
#include <iomanip>
using namespace std;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b){};
    int GetKey(){return key;}             
    string GetElement(){return element;}  
    friend class BST;  
};
class BST{
private:
    TreeNode *root;
public:
    BST():root(0){};    
    TreeNode* Search(int key);
    TreeNode* Successor(TreeNode *current);
    void Insert(int key, string element);
    void InorderPrint();  
    void DeleteBST(int KEY); 
    TreeNode* Leftmost(TreeNode *current);
};
TreeNode* BST::Successor(TreeNode *current){
    if (current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }
    TreeNode *successor = current->parent;   
    while (successor != NULL && current == successor->rightchild) {
        current = successor;
        successor = successor->parent;
    }
    return successor;
};
void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}
void BST::Insert(int key, string element){
    TreeNode *y = 0;        
    TreeNode *x = 0;        
    TreeNode *insert_node = new TreeNode(key, element);   
    x = root;
    while (x != NULL) {                     
        y = x;                          
        if (insert_node -> key < x -> key) x = x->leftchild;
        else x = x -> rightchild;
    }                                   
    insert_node -> parent = y;            
    if ( y == NULL ) this -> root = insert_node;
    else if (insert_node -> key < y -> key) y -> leftchild = insert_node;
    else y -> rightchild = insert_node;
}
TreeNode* BST::Search(int KEY){
    TreeNode *current = root;               
    while (current != NULL && KEY != current->key) {  
        if (KEY < current->key) current = current->leftchild;   // 向左走
        else current = current->rightchild;  // 向右走
    }
    return current;
}
TreeNode* BST::Leftmost(TreeNode *current){
    while (current && current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
void BST::DeleteBST(int KEY){ 
    TreeNode *delete_node = Search(KEY); 
    TreeNode *y = 0;      
    TreeNode *x = 0;
    if (delete_node->leftchild == NULL || delete_node->rightchild == NULL) y = delete_node;
    else y = Leftmost( delete_node -> rightchild );  //Case3   

    if (y->leftchild != NULL) x = y -> leftchild;    
    else x = y->rightchild;

    if (x != NULL) x->parent = y->parent;

    if (y->parent == NULL) this->root = x;
    else if (y == y->parent->leftchild) y->parent->leftchild = x;       
    else y->parent->rightchild = x;   
                                          
    if (y != delete_node) {                                 //case3
        delete_node->key = y->key;          
        delete_node->element = y->element;
    }

    delete y;                               
    y = 0;  
};
int main(){
    BST T;
    T.Insert(8,"A"); T.Insert(100,"B"); T.Insert(2,"C");
    T.Insert(13,"D"); T.Insert(25,"E"); T.Insert(7,"F");
    T.Insert(48,"G"); T.Insert(77,"H"); T.Insert(28,"I");
    cout << "Inorder Traversal:" << endl;
    T.InorderPrint();
    cout<<endl;
    T.DeleteBST(100);
    cout << "Inorder Traversal:" << endl;
    T.InorderPrint();
    cout<<endl;
    T.DeleteBST(8);
    cout << "Inorder Traversal:" << endl;
    T.InorderPrint();
}