#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<pair<int,int>> adj[100];

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void primMST() {
        priority_queue< pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>> > pq;

        vector<bool> inMST(V, false);

        pq.push({0, 0});  

        int totalWeight = 0;

        cout << "Prim MST edges:";

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int u = p.second;

            if (inMST[u]) continue; 
            inMST[u] = true;
            totalWeight += wt;

            cout << u << " (added with wt = " << wt << ")\n";

            for (auto &nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;

                if (!inMST[v])
                    pq.push({w, v});
            }
        }

        cout << "Total MST weight = " << totalWeight << endl;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);

    g.primMST();
}
