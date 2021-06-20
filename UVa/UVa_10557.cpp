#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int inf = 1e9;

int N;
vector<int> adj[limN];
int sumo[limN];
bool richo[limN];

void bfs(const vector <int> &maxE) {
    queue <int> Q;
    for(int i=0; i<N; i++) {
        if(maxE[i] > 0) {
            richo[i] = true;
            Q.push(i);
        }
        else
            richo[i] = false;
    }
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for(const int &sig:adj[pos]) {
            if(richo[sig])
                continue;
            richo[sig] = true;
            Q.push(sig);
        }
    }
}

void testCase() {
    for(int i=0; i<N; i++) {
        scanf("%d", &sumo[i]);
        int K ;
        adj[i].clear();
        scanf("%d", &K);
        adj[i].resize(K);
        for(int j=0; j<K; j++) {
            scanf("%d", &adj[i][j]);
            adj[i][j]--;
        }
    }

    vector <int> *curArr, *sigArr;
    curArr = new vector<int>(N,-inf);
    sigArr = new vector<int>(N,-inf);
    (*curArr)[0] = 100;
    //printf("hiro\n");
    
    for(int W=1; W<N; W++) {
        for(int i=0; i<N; i++)
            (*sigArr)[i] = (*curArr)[i];
        for(int pos=0; pos<N; pos++) {
            int s = (*curArr)[pos];
            for(const int &sig:adj[pos]) {
                if(s + sumo[sig] > 0)
                    (*sigArr)[sig] = max((*sigArr)[sig], s + sumo[sig]);
            }
        }
        // for(int i=0; i<N; i++) {
        //     printf("%d ", (*sigArr)[i]==-inf? 0 : (*sigArr)[i]);
        // }
        // printf("\n");
        swap(curArr, sigArr);
    }

    bool works = true;
    if(works) {
        for(int i=0; i<N; i++)
            (*sigArr)[i] = 0;
        for(int pos=0; pos<N; pos++) {
            int s = (*curArr)[pos];
            for(const int &sig:adj[pos]) {
                if(s + sumo[sig] > 0 && (*curArr)[sig] > 0 &&  s + sumo[sig] > (*curArr)[sig]) {
                    (*sigArr)[sig] = s + sumo[sig];
                    works = true;
                }
            }
        }
        // printf("=> ");
        // for(int i=0; i<N; i++) {
        //     printf("%d ", (*sigArr)[i]==-inf? 0 : (*sigArr)[i]);
        // }
        // printf("\n");
        swap(curArr, sigArr);
    }

    if(works)
        bfs(*curArr);
    if( (*sigArr)[N-1] > 0) {
        richo[N-1] = works = true;        
    }

    printf("%s\n", works && richo[N-1]? "winnable" : "hopeless");

    delete curArr;
    delete sigArr;
}

int main() {
    while(scanf("%d", &N)!=EOF && N!=-1)
        testCase();
}
