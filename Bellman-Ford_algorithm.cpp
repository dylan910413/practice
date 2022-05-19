#include <iostream>
#include <vector>
#include <list>
#include <utility>      
#include <iomanip>          
using namespace std;
class Graph{
private :
    int vertex;
    vector<list<pair<int,int>>> AdjList;
    vector<int> predecessor, distance;
public :
    Graph():vertex(0){};
    Graph(int n):vertex(n){
        AdjList.resize(vertex);
    }
    void AddEdge(int start, int end, int length);
    void PrintDataArray(vector<int> array);
    void InitializeSource(int root);
    void Relax(int start, int end, int length);
    bool BellmanFord(int root = 0);
};
bool Graph::BellmanFord(int root){
    InitializeSource(root);
    for (int i = 0; i < vertex-1; i++) {                
        for (int j = 0 ; j < vertex; j++) {             // 把AdjList最外層的vector走一遍
            for (list<pair<int,int> >::iterator itr = AdjList[j].begin();itr != AdjList[j].end(); itr++) {          // 各個vector中, 所有edge走一遍
                Relax(j, (*itr).first, (*itr).second);
            }
        }
    }
    for (int i = 0; i < vertex; i++) {
        for (list<pair<int,int> >::iterator itr = AdjList[i].begin();itr != AdjList[i].end(); itr++) {
            if (distance[(*itr).first] > distance[i]+(*itr).second) {   // i是from, *itr是to
                return false;
            }
        }
    }
    cout << "predecessor[]:"<<endl;
    PrintDataArray(predecessor);
    cout << "distance[]:"<<endl;
    PrintDataArray(distance);
    return true;
}
void Graph::AddEdge(int start, int end, int length){
    AdjList[start].push_back(make_pair(end,length));
}
void Graph::Relax(int start, int end, int length){
    if(distance[end] > distance[start] + length){
        distance[end] = distance[start] + length;
        predecessor[end] = start;
    }
}
void Graph::InitializeSource(int root){
    distance.resize(vertex);
    predecessor.resize(vertex);
    for(int i = 0; i < vertex; i++){
        distance[i] = 100000;
        predecessor[i] = -1;
    }
    distance[root] = 0;
}
void Graph::PrintDataArray(vector<int> array){
    for (int i = 0; i < vertex; i++) cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < vertex; i++) cout << setw(4) << array[i];
    cout << endl << endl;
}
int main(){
    Graph graph(6);
    graph.AddEdge(0, 1, 5); graph.AddEdge(1, 4, -4); graph.AddEdge(1, 2, 6);
    graph.AddEdge(2, 4, -3); graph.AddEdge(2, 5, -2); graph.AddEdge(3, 2, 4);
    graph.AddEdge(4, 3, 1); graph.AddEdge(4, 5, 6); graph.AddEdge(5, 0, 3); graph.AddEdge(5, 1, 7);
    if (graph.BellmanFord(0)) cout << "There is no negative cycle."<<endl;
    else cout << "There is a negative cycle."<<endl;
    return 0;
}