#include <iostream>
#include <algorithm>
using namespace std;
template<typename T> struct Node{
    T val;
    Node<T> *nxt;
    Node(){
        nxt=NULL;
    }
};
template<typename T> class LinkedQueue{
    public:
        Node<T> *head, *tail;
        int s = 0;       //size
        LinkedQueue(){
            head = new Node<T>;
            head -> nxt = NULL;
            tail = head;
        }
        void push(T val){
            s++;
            Node<T> *y;  //insertedNode
            y = new Node<T>;
            y -> val = val;
            y -> nxt = NULL;
            tail -> nxt = y;
            tail = tail -> nxt;
        }
        void pop(){
            s--;
            head = head -> nxt;
        } 
        void front(){
            if ( s == 0 ) cout << "The queue is empty." << endl;
            else cout << "The first element is: " << (head -> nxt) -> val << endl;
        } 
        void size(){
            cout << "The size of queue is: "<< s << endl;
        }
        void printLinkedQueue(){
            Node<T> *cur = head;
			cout << "Queue: ";
			while (cur != tail) {
				cout << (cur -> nxt) -> val << " ";
				cur = cur -> nxt;
			}
			cout << endl;
        }
};
int main(){
    LinkedQueue<int> q;
    int n = 5;
    for(int i = 0; i < 5; i++ ){
        q.push(i);
        q.front();
        q.size();
        q.printLinkedQueue();
    }
    for(int i = 0; i < 5; i++ ){
        q.pop();
        q.front();
		q.size();
		q.printLinkedQueue();
    }
}