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



    void dfs(int u,vector<bool> &vis){
        cout << u<< " ";
        vis[u]=true;
        for(int v: l[u]){
            if(!vis[v]){
                dfs(v,vis);}
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);

    g.addEdge(2,4);

    vector<bool> vis(5,false);
    g.dfs(0,vis);
    return 0;
}