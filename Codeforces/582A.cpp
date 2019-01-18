#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

map <int, int> reps;
vector <int> nms;

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0, a; i<N*N; i++) {
        scanf("%d", &a);
        reps[a] ++;
    }

    auto it = reps.end();
    it --;
    while(N) {
        if(it->second == 0) {
            it --;
            continue;
        }
        N --;
        int w = it->first;
        it->second --;
        for(const int k : nms) {
            reps[__gcd(k, w)] -= 2 ;
        }
        nms.push_back(w);
    }

    for(const int w : nms)
        printf("%d ", w);    
    printf("\n");
}
