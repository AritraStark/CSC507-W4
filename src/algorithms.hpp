#pragma once
#include "graph.hpp"
#include <sys/resource.h>

double getMemoryUsageMB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss / 1024.0; 
}

void BFS(const Graph& g,int start=0){
    int n = g.size();
    vector<bool> vis(n,false);
    queue<int>q;
    vis[start]=true;
    q.push(start);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto node : g.neighbors(curr)) {
            int v = node.first;
            int w = node.second;
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void DFS_ITER(const Graph& g,int start=0){
    int n = g.size();
    vector<bool>vis(n,false);
    stack<int>st;
    st.push(start);
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto node:g.neighbors(u)){
            if(!vis[node.first])    st.push(node.first);
        }
    }
}

void DFS_rec_util(const Graph& g,int u,vector<bool>&vis){
    vis[u]=true;
    for(auto node : g.neighbors(u)) {
        int v = node.first;
        if(!vis[v]) DFS_rec_util(g,v,vis);
    }
}
void DFS_REC(const Graph& g,int start=0){
    int n = g.size();
    vector<bool> vis(n,false);
    DFS_rec_util(g,start,vis);
}

void DIJKSTRA(const Graph& g,int start=0){
    int n = g.size();
    vector<int> dist(n,INT_MAX); 
    dist[start]=0;
    typedef pair<int,int> P; priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int> curr = pq.top(); 
        pq.pop();
        int d = curr.first;
        int u = curr.second;
        if(d != dist[u]) continue;
        for(auto node : g.neighbors(u)) {
            int v = node.first;
            int w = node.second;
            if(dist[v] > d + w) {
            dist[v] = d + w;
            pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void SCC1(const Graph& g) {
    int n = g.size();
    Graph gR = g.reverseGraph();
    vector<int> comp(n, -1);
    int cid = 0; 

    for(int i = 0; i < n; i++) {
        if(comp[i] == -1) {
            cid++;  // New component
            vector<bool> visG(n, false);
            vector<bool> visGR(n, false);

            stack<int> st;
            st.push(i);
            while(!st.empty()) {
                int u = st.top();
                st.pop();
                if(!visG[u]) {
                    visG[u] = true;
                    for(auto node : g.neighbors(u)) {
                        if(!visG[node.first]) {
                            st.push(node.first);
                        }
                    }
                }
            }

            st.push(i);
            while(!st.empty()) {
                int u = st.top();
                st.pop();
                if(!visGR[u]) {
                    visGR[u] = true;
                    for(auto node : gR.neighbors(u)) {
                        if(!visGR[node.first]) {
                            st.push(node.first);
                        }
                    }
                }
            }

            for(int v = 0; v < n; v++) {
                if(visG[v] && visGR[v]) {
                    comp[v] = cid;
                }
            }
        }
    }
}

void SCC2(const Graph& g){
    int n = g.size();
    Graph gR = g.reverseGraph();
    vector<int> comp(n, -1);
    int cid = 0;

    for(int i=0; i<n; i++){
        if(comp[i] == -1){
            cid++;
            vector<bool> visG(n,false), visGR(n,false);

            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u=q.front(); q.pop();
                if(visG[u]) continue;
                visG[u]=true;
                for(auto node : g.neighbors(u)) {
                    int v = node.first;
                    if(!visG[v]) q.push(v);
                }
            }

            q.push(i);
            while(!q.empty()){
                int u=q.front(); q.pop();
                if(visGR[u]) continue;
                visGR[u]=true;
                for(auto node : gR.neighbors(u)) {
                    int v = node.first;
                    if(!visGR[v]) q.push(v);
                }
            }

            for(int v=0; v<n; v++)
                if(visG[v] && visGR[v])
                    comp[v] = cid;
        }
    }
}

void fillOrder(const Graph& g,int u,vector<bool>&vis,stack<int>&st){
    vis[u]=true;
    for(auto node : g.neighbors(u)) {
        int v = node.first;
        if(!vis[v]) fillOrder(g,v,vis,st);
    }
    st.push(u);
}
void dfsAssign(const Graph& g,int u,vector<bool>&vis,int cid,vector<int>&comp){
    vis[u]=true; comp[u]=cid;
    for(auto node : g.neighbors(u)) {
        int v = node.first;
        if(!vis[v]) dfsAssign(g,v,vis,cid,comp);
    }
}
void SCC3(const Graph& g){
    int n=g.size(); 
    vector<bool>vis(n,false);
    stack<int>st;
    for(int i=0;i<n;i++) 
        if(!vis[i]) fillOrder(g,i,vis,st);
    Graph gR=g.reverseGraph(); 
    fill(vis.begin(),vis.end(),false);
    vector<int> comp(n,-1);
    int cid=0;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(!vis[u]){
            cid++; 
            dfsAssign(gR,u,vis,cid,comp);
        }
    }
}
