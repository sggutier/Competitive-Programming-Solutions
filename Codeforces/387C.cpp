#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef pair<int, char> par;
#define f first
#define s second

char str[limN];

int main() {
    int N ;
    int ans = 0;
    vector <par> req;
    
    scanf("%s", str);
    N = strlen(str);

    for(int i=N-1, cer=0; i>=0; i--) {
        if(str[i]=='0') {
            cer ++;
            continue;
        }
        req.emplace_back(cer+1, str[i]);
        cer = 0;
    }
    reverse(req.begin(), req.end());

    par ult(0, str[0]);
    for(const par &p : req) {
        if(ult < p)
            ans = 0;
        ult.f += p.f;
        ans ++;
    }
    
    printf("%d\n", ans);
}
