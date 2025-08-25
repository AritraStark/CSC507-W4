#include "algorithms.hpp"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#ifndef ALGO
#define ALGO BFS
#endif

void runAlgorithm(const Graph& g){
#if ALGO == BFS
    BFS(g);
#elif ALGO == DFS_ITER
    DFS_ITER(g);
#elif ALGO == DFS_REC
    DFS_REC(g);
#elif ALGO == DIJKSTRA
    DIJKSTRA(g);
#elif ALGO == SCC1
    SCC1(g);
#elif ALGO == SCC2
    SCC2(g);
#elif ALGO == SCC3
    SCC3(g);
#endif
}

void runVARM(int N){
    int maxM = N*(N-1)/2;
    for(int M=2*N; M<=maxM; M+=N*10){
        Graph g=generateGraph(N,M,true,true);

        clock_t s=clock(); 
        runAlgorithm(g); 
        clock_t e=clock();

        double t=double(e-s)/CLOCKS_PER_SEC;
        double mem = getMemoryUsageMB();

        cout << "VARM " << N << " " << M << " " << t << " " << mem 
             << " " << TOSTRING(ALGO) << endl;
    }
}

void runVARN(string sparsity){
    for(int N=100;N<=1000;N+=100){
        int M=0;
        if(sparsity=="2n") M=2*N;
        else if(sparsity=="nlogn") M=N*(int)(log(N));
        else if(sparsity=="nsqrtn") M=N*(int)(sqrt(N));
        else if(sparsity=="nc2") M=N*(N-1)/2;

        Graph g=generateGraph(N,M,true,true);

        clock_t s=clock(); 
        runAlgorithm(g); 
        clock_t e=clock();

        double t=double(e-s)/CLOCKS_PER_SEC;
        double mem = getMemoryUsageMB();

        cout << "VARN " << N << " " << M << " " << t << " " << mem 
             << " " << TOSTRING(ALGO) << endl;
    }
}

int main(int argc,char*argv[]){
    if(argc<2){
        cerr<<"Usage:\n ./prog --varm N\n ./prog --varn sparsity(2n|nlogn|nsqrtn|nc2)\n";
        return 1;
    }
    string mode=argv[1];
    if (mode == "--varm")
    {
        if (argc < 3)
        {
            cerr << "Need N\n";
            return 1;
        }
        int N = stoi(argv[2]);
        runVARM(N);
    }
    else if (mode == "--varn")
    {
        if (argc < 3)
        {
            cerr << "Need sparsity\n";
            return 1;
        }
        runVARN(argv[2]);
    }
    else
    {
        cerr << "Unknown mode\n";
    }
}
