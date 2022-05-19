#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int max = 105;
vector<int> Graph[105]; //repesent a direct graph
int indegree[105]; //indegrees of nodes
int n; //n nodes

class TopoIterator{
    public:    
        void toposort(){ //topological sorting to get topological order
            queue<int> q;
            vector<int> v;
            for( int i = 1; i <= n; i++ ){
                if( indegree[i]==0 ) q.push(i);
            }
            while( q.size() != 0 ){
                int now = q.front();
                q.pop();
                v.push_back(now);
                for( int i = 1; i <= Graph[now].size() ; i++){
                    int next = Graph[now][i];
                    indegree[next]--;
                    if ( indegree[next] == 0 ){
                        q.push(next);
                    }
                }
            }
            for( int i = 0; i < v.size(); i++){
                cout << v[i]<< " " ;
            }
            cout << endl;
        }
};