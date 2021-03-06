#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

vector <int> divs[limN];
int ans[limN];

int main() {
    for(int i=2; i<limN; i++)
        if(divs[i].empty())
            for(int j=i; j<limN; j+=i)
                divs[j].push_back(i);
    int N ;

    scanf("%d", &N);
    for(int i=0, a, w; i<N; i++) {
        scanf("%d", &a);
        w = 0;
        for(const int d : divs[a])
            w = max(w, ans[d]);
        w++;
        for(const int d : divs[a])
            ans[d] = w;
    }

    int w = 1;
    for(int i=0; i<limN; i++)
        w = max(w, ans[i]);

    printf("%d\n", w);
}
