#include <bits/stdc++.h>
using namespace std;
const int limN = 10005;

vector <int> primos;
bool comp[limN];

void criba(int n = limN) {
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            primos.push_back(i);
}

int testCase(int n) {
    pair<int,int> ans(-1,0);
    for(const int &p:primos) {
        if(p>n) break;
        ans = max(ans, {n%p, p});
    }
    return ans.second;
}

int main() {
    criba();
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a ;
        scanf("%d", &a);
        printf("%d\n", testCase(a));
    }
}
