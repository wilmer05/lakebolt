#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<cassert>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

const int mn = 1000000;
vector<int> graph[mn];
queue<int> q;
bool visit[mn];
int main(int argc, char* argv[]){
    int m = atoi(argv[2]); //edges
    int n = atoi(argv[1]); //nodes

    FOR(i,n) graph[i].clear();
    FOR(i,m){
        int u,v; //edge creation
        
        u = rand() % n;
        v = rand() % n;
        //cout << u <<" " << v << endl;
        graph[u].push_back(v);        
        graph[v].push_back(u);
    } 

    FOR(i,n) visit[i]=false;

    FOR(i,n){
        if(!visit[i]){
            visit[i]=true;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                FOR(next,graph[top].size()){
                    int nx = graph[top][next];
                    if(!visit[nx]){
                        visit[nx]=true;
                        q.push(nx);
                    }
                }
            }
        }
    }
    FOR(i,n) assert(visit[i]);

	return 0;
}
