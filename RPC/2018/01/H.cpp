#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N, P;
int maxDst, minDst[limN];
int dsts[limN];
vector <int> listas[limN];
int posL[limN], tams[limN];
int inis[limN];

bool funcaDst(int minDA, int pa, int minDB, int pb) {
    int d = abs(dsts[pa]-dsts[pb]);
    return d <= maxDst && minDA <= d && minDB <= d;
}

bool hazLista(int idA, int idB, vector <int> &ans) {
    int minDA = minDst[idA];
    int pa = inis[idA];
    int minDB = minDst[idB];
    int pb = inis[idB];
    while(pa+1 < P && pb+1 < P) {
        // printf("%d (%d),  %d (%d)\n", pa, dsts[pa], pb, dsts[pb]);
        if(funcaDst(minDA, pa+1, minDB, pb))
            pa++, ans.push_back(idA);
        else if(funcaDst(minDA, pa, minDB, pb+1))
            pb++, ans.push_back(idB);
        else
            return false;
    }
    while(pa++ < P-1)
        ans.push_back(idA);
    while(pb++ < P-1)
        ans.push_back(idB);
    return true;
}

bool fposo(int i) {
    if(posL[i] == tams[i])
        return false;
    if(i==0 && listas[i][posL[i]]==i) {
        return true;
    }
    if(i==N-2 && listas[i][posL[i]]==N-1) {
        return true;
    }
    if(i+1 >= N-1 || posL[i+1] == tams[i+1])
        return false;
    if(listas[i][posL[i]] == listas[i+1][posL[i+1]]) {
        return true;
    }
    return false;
}

int main() {
    set <int> Q;
    
    scanf("%d", &maxDst);
    scanf("%d", &P);
    for(int i=0; i<P; i++)
        scanf("%d", &dsts[i]);
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &minDst[i], &inis[i]);
        inis[i]--;
    }
    // printf("entrada leida\n");

    for(int i=0; i+1<N; i++) {
        if(!hazLista(i, i+1, listas[i]) ) {
            printf("impossible\n");
            return 0;
        }
        tams[i] = listas[i].size();
        // printf("=> ");
        // for(const int c : listas[i])
        //     printf("%d ", c+1);
        // printf("\n");
    }

    for(int i=0; i+1<N; i++) {
        if(fposo(i))
            Q.insert(i);
    }
    
    // for(int w=0; w+1<N; w++) {
    //     printf("\t=> ");
    //     for(int j=posL[w]; j<(int) listas[w].size(); j++) {
    //         printf("%d ", listas[w][j]+1);
    //     }
    //     printf("\n");
    // }
    int cnt = 0;
    while(!Q.empty()) {
        int i = *Q.begin(); Q.erase(Q.begin());
        int pa = N, pb = N;
        // printf("Considerando %d\n", i);
        if(posL[i] == tams[i]) continue;
        if(i==0 && listas[i][posL[i]]==i) {
            pa = i ;
        }
        else if(i==N-2 && listas[i][posL[i]]==N-1) {
            pa = i ;
        }
        else if(listas[i][posL[i]] == listas[i+1][posL[i+1]]) {
            pa = i;
            pb = i+1;
        }
        if(pa==N) break;
        if(cnt++)
            printf(" " );
        printf("%d", listas[pa][posL[pa]] + 1);
        // printf(">> %d | %d %d | %d\n", i, pa, pb, listas[pa][posL[pa]] + 1);
        Q.erase(pb);
        posL[pa]++;
        posL[pb]++;
        // for(int w=0; w+1<N; w++) {
        //     printf("\t=> ");
        //     for(int j=posL[w]; j<(int) listas[w].size(); j++) {
        //         printf("%d ", listas[w][j]+1);
        //     }
        //     printf("\n");
        // }
        if(fposo(pa)) {
            Q.insert(pa);
            // printf("Metiendo a %d\n", pa);
        }
        if(pb<N-1 && fposo(pb)) {
            Q.insert(pb);
            // printf("Metiendo a %d\n", pb);
        }
        if(pa-1>=0 && fposo(pa-1)) {
            Q.insert(pa-1);
            // printf("Metiendo a %d\n", pa-1);
        }
    }
    printf("\n");
}
