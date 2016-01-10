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

#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
const int max_dim = 1010;

int matriz[max_dim][max_dim],matriz3[max_dim][max_dim];

int main(int argc, char* argv[]){
    int dim = atoi(argv[1]);
    FOR(i,dim) FOR(j,dim) matriz[i][j] = 2;
    FOR(i,dim) 
        FOR(k,dim) 
            FOR(j,dim) 
                matriz3[i][j] += matriz[i][k]*matriz[k][j];

    FOR(i,dim) {
        FOR(j,dim) printf("%d ",matriz3[i][j]);
        printf("\n");
    }

	return 0;
}
