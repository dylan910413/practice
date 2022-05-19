#include <iostream>
#include <vector>
#include <list>
#include <utility>      
#include <iomanip>
using namespace std;
class Node{
public:
    int key;
    Node *leftchild;
    Node *rightchild;
    int height;
    string month;
};
int height(Node *N){
    if (N == NULL) return 0;
    return N->height;
}
Node* newNode(int key, string month){
    Node* node = new Node();
    node->key = key;
    node->leftchild = NULL;
    node->rightchild = NULL;
    node->month = month;
    node->height = 1;
    return(node);
}
Node *rightRotate(Node *cur){
    Node *x = cur->leftchild;
    Node *x2 = cur->rightchild;
    x->rightchild = cur;
    cur->leftchild = x2;
    cur->height = max(height(cur->leftchild),height(cur->rightchild)) + 1;
    x->height = max(height(x->leftchild),height(x->rightchild)) + 1;
    return x;
}
Node *leftRotate(Node *cur){
    Node *y = cur->rightchild;
    Node *y2 = y->leftchild;
    y->leftchild = cur;
    cur->rightchild = y2;
    cur->height = max(height(cur->leftchild), height(cur->rightchild)) + 1;
    y->height = max(height(y->leftchild), height(y->rightchild)) + 1;
    return y;
}
int getBalance(Node *N){
    if (N == NULL)
        return 0;
    return height(N->leftchild) - height(N->rightchild);
}
Node* insert(Node* node, int key, string month){
    if (node == NULL) return(newNode(key,month));
    if (key < node->key) node->leftchild = insert(node->leftchild, key, month);
    else if (key > node->key) node->rightchild = insert(node->rightchild, key, month);
    else return node;
    node->height = 1 + max(height(node->leftchild), height(node->rightchild));
    int balance = getBalance(node);
    if (balance > 1 && key < node->leftchild->key) return rightRotate(node);
    if (balance < -1 && key > node->rightchild->key) return leftRotate(node);
    if (balance > 1 && key > node->leftchild->key){
        node->leftchild = leftRotate(node->leftchild);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->rightchild->key){
        node->rightchild = rightRotate(node->rightchild);
        return leftRotate(node);
    }
    return node;
}
void InOrder(Node *root){
    if(root != NULL){
        InOrder(root->leftchild);
        cout << root->key << " "<< root-> month<<endl;
        InOrder(root->rightchild);
    }
}
int main(){
    Node *root = NULL;
    root = insert(root, 12, "DECEMBER"); root = insert(root, 1, "JANUARY");
    root = insert(root, 4, "APRIL"); root = insert(root, 3, "MARCH");
    root = insert(root, 7, "JULY"); root = insert(root, 8, "AUGUST");
    root = insert(root, 10, "OCTOBER"); root = insert(root, 2, "FEBRUARY");
    root = insert(root, 11, "NOVEMBER"); root = insert(root, 5, "MARCH");
    root = insert(root, 6, "JUNE");
    cout << "Inorder traversal of the constructed AVL tree is " << endl;
    InOrder(root);     
    return 0;
}