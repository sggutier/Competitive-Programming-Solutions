#include <bits/stdc++.h>
using namespace std;
const int limN = 1e7 + 5;
const int limP = 7e6 ;

int P = 0;
int prims[limP];
vector <int> pps;
bitset <limN> isComp;

bool isPald(int n) {
    char tmp[11];
    int k;
    sprintf(tmp, "%d", n);
    k = strlen(tmp);
    for(int i=0; 2*i<k; i++)
        if(tmp[i] != tmp[k-1-i])
            return false;
    return true;
}

void precarga() {
    for(int i=2; i*i<limN; i++)
        if(!isComp[i])
            for(int j=i*i; j<limN; j+=i)
                isComp[j] = true;
    for(int i=2; i<limN; i++)
        if(!isComp[i])
            prims[P++] = i;
    for(int i=0; i<P; i++) {
        if(!isPald(prims[i])) continue;
        //printf("%3d => %d\n", (int) pps.size()+1, prims[i]);
        pps.push_back(prims[i]);
    }
}

int prodM(int n) {
    int ans = 1;
    while(n) {
        if(n%10)
            ans *= n%10;
        n /= 10;
    }
    return ans;
}

int main() {
    precarga();
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int n ;
        scanf("%d", &n);
        printf("%d %d\n", pps[n-1], prims[prodM(pps[n-1])-1]);
    }
}
