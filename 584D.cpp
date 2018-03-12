#include <bits/stdc++.h>
using namespace std;
const int limN = 32000;

bool isComp[limN];
vector <int> prims;

void criba(int n = limN) {
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i<n; i++)
        if(!isComp[i])
            prims.push_back(i);
}

bool isPrim(int n) {
    for(const int &p:prims) {
        if(p >= n)
            break;
        if(n%p==0)
            return false;
    }
    return true;
}

int main() {
    criba();
    int n ;
    scanf("%d", &n);
    if(isPrim(n)) {
        printf("1\n%d\n", n);
        return 0;
    }
    for(const int &p:prims) {
        if(isPrim(n-p)) {
            printf("2\n%d %d\n", n-p, p);
            return 0;
        }
        if(isPrim(n-2*p)) {
            printf("3\n%d %d %d\n", n-2*p, p, p);
            return 0;
        }
    }
}
