#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int sumo[limN];
int wos[limN];

int main() {
    int N, K, P, Q, w = 0, u = 0;
    vector <int> nums[limN];

    scanf("%d%d%d", &N, &K, &P);
    for(int i=0; i<N; i++)
        scanf("%d", &wos[i]);

    sort(wos, wos+N, [](int a, int b) {return 1 - a%2 < 1 - b%2;});

    w = P;
    Q = P==0? K : P;
    int pr = P==0? 1 : 0;
    for(int i=0; i<N; i++) {
        int a = wos[i];
        if(w < K && a%2) {
            // printf("metida impar de %d en %d\n", a, P+w);
            nums[w].push_back(a);
            sumo[w] = 1;
            w++;
            continue;
        }
        // printf("metida par de %d en %d\n", a, u);
        nums[u].push_back(a);
        sumo[u] = (sumo[u] + a)%2;
        if(sumo[u]%2==pr)
            u = (u+1)%Q;
    }

    for(int i=0; i<K; i++) {
        if(sumo[i] != (i>=P) || nums[i].empty()) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    for(int i=0; i<K; i++) {
        // printf("%d => ", sumo[i]);
        printf("%d", (int) nums[i].size());
        for(const int &c:nums[i])
            printf(" %d", c);
        printf("\n");
    }
                            
}
