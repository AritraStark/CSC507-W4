#pragma once
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int N;
    vector<vector<pair<int,int>>> adj;
    bool directed;

public:
    Graph(int n, bool dir=false): N(n), directed(dir) {
        adj.resize(N);
    }
    void addEdge(int u,int v,int w=1){
        adj[u].push_back({v,w});
        if(!directed) adj[v].push_back({u,w});
    }
    const vector<pair<int,int>>& neighbors(int u) const { return adj[u]; }
    int size() const { return N; }
    Graph reverseGraph() const {
        Graph gR(N,directed);
        for(int u=0; u<N; u++)
            for(auto e: adj[u]) gR.addEdge(e.first,u,e.second);
        return gR;
    }
};

// Random graph generator
Graph generateGraph(int N,int M,bool directed=false,bool weighted=false){
    Graph g(N,directed);
    set<pair<int,int>> used;
    srand(time(NULL));
    while((int)used.size()<M){
        int u=rand()%N;
        int v=rand()%N;
        if(u==v) continue;
        if(used.count({u,v})) continue;
        used.insert({u,v});
        int w = weighted ? (rand()%10+1) : 1;
        g.addEdge(u,v,w);
    }
    return g;
}
