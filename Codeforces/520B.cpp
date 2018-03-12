#include <bits/stdc++.h>
using namespace std;
const int limN = 2e4 + 5;

int minP[limN];

int main() {
    int a ,b ;
    queue <int> Q;
    
    cin >> a >> b ;

    minP[a] = 1;
    Q.push(a);
    while(!Q.empty()) {
        a = Q.front(); Q.pop();
        if(a-1 > 0 && !minP[a-1]) {
            Q.push(a-1);
            minP[a-1] = minP[a]+1;
        }
        if(a*2 < limN && !minP[a*2]) {
            Q.push(a*2);
            minP[a*2] = minP[a]+1;
        }
    }

    cout << minP[b]-1 << endl;
}
