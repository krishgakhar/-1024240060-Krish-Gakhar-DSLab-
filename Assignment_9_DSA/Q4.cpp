#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<climits>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; 


public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    void dijkstra(int src){
        vector<int> dist(V, INT_MAX);

        // Min-heap: stores (distance , node)
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]) continue; 

            for(auto &edge : adj[u]){
                int v = edge.first;
                int w = edge.second;

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from " << src << ": ";
        for(int i = 0; i < V; i++)
            cout << dist[i] << " ";
        cout << endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,4,1);

    g.dijkstra(0);
    return 0;
}
