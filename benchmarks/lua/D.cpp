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
int T;
int N,K;
vector<string> v;
const int mn = 310;
int memo[mn][mn];
int d[mn][mn];
const int oo = 1000000;

int get_dif(int x, int y){
    return d[x][y];
}

void calc(){
    FOR(i,v.size())
        for(int j=i+1;j<v.size();j++){
            int sz = v[i].size();
            sz = min(sz,(int)v[j].size());
            int dd = 0;
            while(dd<sz && v[i][dd]==v[j][dd]) dd++;
            int sz2 = v[j].size();
            sz2-=dd;
            sz2 += v[i].size()-dd;
            d[i][j] = sz2;
//            printf("%d %d %d\n",i,j,d[i][j]);
        }
    
}

int dp(int ind, int k){
    if(!k) return (int)v[ind].size();
    if(ind>=v.size()) return oo;
    int &ref = memo[ind][k];
    if(ref!=-1) return ref;
    ref = oo;
    for(int i=ind+1;i<v.size();i++)
        ref = min(ref,dp(i,k-1)+get_dif(ind,i)+1);

    return ref;
}

int main(){
    cin >> T;
    FOR(t,T){
        printf("Case #%d: ",t+1);
        v.clear();
        cin >> N >> K;
        FOR(i,N){
            string s;
            cin >> s;
            v.push_back(s);
        }
        v.push_back("");
        sort(v.begin(),v.end());
        calc();
        memset(memo,-1,sizeof memo);
        cout << dp(0,K) << endl;
    }

	return 0;
}
