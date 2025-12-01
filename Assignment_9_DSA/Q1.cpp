#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }

    void addEdge(int v,int u){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis1(V,false);
        q.push(0);
        vis1[0]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<< u << " ";
            for(int v:l[u]){
                if(vis1[v]!=true){
                    vis1[v]=true;
                    q.push(v);
                }
            }

        }
    }

};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);

    g.addEdge(2,4);

    g.bfs();
   
}