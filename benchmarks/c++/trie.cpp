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
#include <cassert>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

char cad[10010];
struct trie{
    trie *nx[30];
    trie(){
        for(int i=0;i<30;i++)
            nx[i]=NULL;
    }

    void insert(char *s){
        if(*s=='\0') return;
        if(nx[*s-'a']==NULL){
            nx[*s-'a'] = new trie;
        }
        
        (*nx[*s-'a']).insert(s+1);
    }

};

void recorro(trie &a){
    for(int i=0;i<30;i++){
        if(a.nx[i]!=NULL){
            char t = 'a'+i;
            cout << t;
            cout << endl;
            recorro(*(a.nx[i]));
        }
    }
}

trie tmp;
int main(int argc, char* argv[]){
    //strcpy(cad,argv[1]);
    //int sz = strlen(cad);
    assert(argc==2);
    int sz = atoi(argv[1]);
    cad[sz]='\0';
    FOR(i,sz) cad[i]='a'+(rand()%26);
    FOR(i,sz) tmp.insert(cad+i);
    recorro(tmp);
    return 0;
}
