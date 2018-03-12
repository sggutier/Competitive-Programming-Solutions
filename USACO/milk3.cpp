/*
ID: me60
LANG: C++11
TASK: milk3
*/
#include <bits/stdc++.h>
using namespace std;

bool usd[21][21][21];

int pourAmount(int ini, int fin, int finCap) {
    return min(ini, finCap-fin);
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    
    int cubCap[3];
    set<int> ans;
    queue <int> Q[3];

    for(int i=0; i<3; i++)
        scanf("%d", &cubCap[i]);
    
    usd[ 0 ][ 0 ][ cubCap[2] ] = true;
    Q[0].push(0);
    Q[1].push(0);
    Q[2].push(cubCap[2]);
    while(!Q[0].empty()) {
        int curCub[3] ;
        int ord[] = {0, 1, 2};
        for(int i=0; i<3; i++) {
            curCub[i] = Q[i].front();
            Q[i].pop();
        }
        if(curCub[0]==0)
            ans.insert(curCub[2]);
        do {
            int x ;
            x = pourAmount( curCub[ord[0]] ,  curCub[ord[1]],  cubCap[ord[1]]);
            int cubCpy[3] = {curCub[0], curCub[1], curCub[2]};
            cubCpy[ord[0]] -= x;
            cubCpy[ord[1]] += x;
            if(!usd[ cubCpy[0] ][ cubCpy[1] ][ cubCpy[2] ]) {
                usd[ cubCpy[0] ][ cubCpy[1] ][ cubCpy[2] ] = true;
                for(int i=0; i<3; i++)
                    Q[i].push(cubCpy[i]);
            }
        } while(next_permutation(ord, ord+3)) ;
    }

    bool fst = true;
    for(int c: ans) {
        if(!fst)
            printf(" ");
        fst = false;
        printf("%d", c);
    }
    printf("\n");
    
    return 0;
}
