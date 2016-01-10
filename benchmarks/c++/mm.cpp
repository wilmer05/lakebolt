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

struct mm{
    vector< vector<int> > m;
    mm operator*(const mm &ot) const{
        mm ans;
        int sz1 = m.size();
        int sz2 = ot.m.size();
        ans.m = vector< vector<int> >(sz1,vector<int>(ot.m[0].size(),0));
        FOR(i,sz1)
            FOR(j,ot.m[0].size())
                FOR(k,sz2) ans.m[i][j]+=m[i][k]*ot.m[k][j]; 
        return ans;
    }
};
mm matriz,matriz2;
vector<int> fila;
int main(int argc, char* argv[]){
    int dim = atoi(argv[1]);
    FOR(i,dim) fila.push_back(2);
    FOR(i,dim) matriz.m.push_back(fila);
    FOR(i,dim) matriz2.m.push_back(fila);
    matriz = matriz*matriz2;
    FOR(i,dim) {
        FOR(j,dim) cout << matriz.m[i][j] <<" ";
        cout << endl;
    }

	return 0;
}
