#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 1;

bitset<limN> comp;
vector <int> primos;

void criba(int N = limN) {
    comp[0] = comp[1] = true;
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++)
        if(!comp[i])
            primos.push_back(i);
}

void testCase(int n) {
    pair <int, int> ans(-1, 0);

    for(const int &p:primos) {
        if(2*p > n)
            break;
        if(!comp[n-p]) {
            ans = max(ans, {n-p-p, p});
        }
    }

    printf("%d:\n", n);
    if(ans.first==-1)
        printf("NO WAY!\n");
    else
        printf("%d+%d\n", ans.second, n-ans.second);
}

int main() {
    criba();
    int n ;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
