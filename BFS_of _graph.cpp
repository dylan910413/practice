#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;
class Graph{
    private :
        int vertex;
        vector< list<int> > AdjList;
        int *visited,             
            *distance,         
            *lastnode;          
    public :
        Graph() : vertex(0){};           
        Graph(int N) : vertex(N){        // constructor with input: number of vertex
            AdjList.resize(vertex);
        };
        void AddEdgeList(int begin, int end);
        void BFS(int Start);
};
void Graph::AddEdgeList(int begin, int end){
    AdjList[begin].push_back(end);
}
void Graph::BFS(int Start){
    cout<< "BFS result: " << endl;
    visited = new int[vertex];
    lastnode = new int[vertex];
    distance = new int[vertex];
    for (int i = 0; i < vertex; i++) {  // initialization
        visited[i] = 0;                       
        lastnode[i] = -1;                
        distance[i] = vertex + 1;         
    }
    queue <int> q;
    int i = Start;
    for (int j = 0; j < vertex; j++) {  
        if (visited[i] == 0) {                
            visited[i] = 1;                   
            distance[i] = 0;                
            lastnode[i] = -1;            
            q.push(i);
            while ( !q.empty() ) {
                int now = q.front();    
                cout << now << " ";              
                for (list<int>::iterator itr = AdjList[now].begin() ;itr != AdjList[now].end(); itr++ ) {                         
                    if (visited[*itr] == 0) {                
                        visited[*itr] = 1;                   
                        distance[*itr] = distance[now] + 1;  
                        lastnode[*itr] = now;
                        cout << " -> " << *itr << " distance: " << distance[*itr] << endl;             
                        q.push(*itr);                      
                    }
                }
                cout << endl;
                q.pop();           
            }
        }
        i = j;
    }
}
int main(){
    Graph g1(9);
    g1.AddEdgeList(0, 1);g1.AddEdgeList(0, 2);g1.AddEdgeList(0, 3);
    g1.AddEdgeList(1, 0);g1.AddEdgeList(1, 4);
    g1.AddEdgeList(2, 0);g1.AddEdgeList(2, 4);g1.AddEdgeList(2, 5);g1.AddEdgeList(2, 6);g1.AddEdgeList(2, 7);
    g1.AddEdgeList(3, 0);g1.AddEdgeList(3, 7);
    g1.AddEdgeList(4, 1);g1.AddEdgeList(4, 2);g1.AddEdgeList(4, 5);
    g1.AddEdgeList(5, 2);g1.AddEdgeList(5, 4);g1.AddEdgeList(5, 8);
    g1.AddEdgeList(6, 2);g1.AddEdgeList(6, 7);g1.AddEdgeList(6, 8);
    g1.AddEdgeList(7, 2);g1.AddEdgeList(7, 3);g1.AddEdgeList(7, 6);
    g1.AddEdgeList(8, 5);g1.AddEdgeList(8, 6);
    g1.BFS(0);    
}

