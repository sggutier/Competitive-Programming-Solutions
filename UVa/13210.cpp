#include <bits/stdc++.h>
using namespace std;
const int limN = 2e3 + 5;

int N;
bool usd[limN][limN];
int spec[limN], rem[limN];
bool print[limN];

void testCase() {
    memset(usd, 0, sizeof(usd));
    memset(print, 0, sizeof(print));
    memset(rem, 0, sizeof(rem));
    map <string,int> noms;
    queue <int> Q;
    char tmp[200];
    int M;
    bool works = true;
    int ans = 0;

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        noms[tmp] = i;
    }
    for(int i=0; i<M; i++) {
        int F;
        scanf("%d", &F);
        spec[i] = -1;
        for(int j=0; j<F; j++) {
            int w;
            scanf("%d%s", &w, tmp);
            auto n = noms.find(tmp);
            if(n==noms.end())
                continue;
            int pos = n->second;
            rem[i]++;
            if(w==1) {
                spec[i] = pos;
            }
            else
                usd[i][pos] = 1;
        }
        if(!rem[i])
            works = false;
        if(rem[i]==1 && spec[i]!=-1 && !print[spec[i]]) {
            print[spec[i]] = true;
            Q.push(spec[i]);
        }
    }

    while(!Q.empty() && works) {
        ans ++;
        int pos = Q.front(); Q.pop();
//        printf("%d => ", pos);
//        for(const auto &p:noms) {
//            if(p.second==pos)
//                printf("%s\n", p.first.c_str());
//        }
        for(int i=0; i<M; i++) {
            if(usd[i][pos]) {
                usd[i][pos] = 0;
                rem[i] --;
                if(rem[i]==0) {
                    works = false;
                    break;
                }
                if(rem[i]==1 && spec[i]!=-1 && !print[spec[i]]) {
                    print[spec[i]] = 1;
                    Q.push(spec[i]);
                }
            }
        }
    }

    if(!works) {
        printf("Impossible\n");
        return;
    }
    printf("%d\n", ans);
    for(const auto &p:noms) {
        if(print[p.second])
            printf("%s\n", p.first.c_str());
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
