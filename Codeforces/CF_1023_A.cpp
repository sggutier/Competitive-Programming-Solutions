#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

int main() {
    int N, M ;
    string A, B ;

    cin >> N >> M ;
    cin >> A >> B ;

    if(A == B) {
        printf("YES\n");
        return 0 ;
    }

    if(N-1 > M) {
        printf("NO\n");
        return 0 ;
    }

    for(int p=0; p<N; p++) {
        if(A[p] != '*') continue ;
        int k = N-p-1 ;
        if(A.substr(0, p) == B.substr(0, p)
           && A.substr(p+1, k) == B.substr(M - k, k) ) {
            printf("YES\n");
            return 0 ;
        }
    }
    

    printf("NO\n");
}
