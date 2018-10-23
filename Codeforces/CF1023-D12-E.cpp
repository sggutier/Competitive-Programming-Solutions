#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 1005 ;

int N ;
char ans[limN] ;

bool query(int a, int b, int c, int d) {
    // if((c-a) + (d-b) < N-1) {
    //     printf("bq\n");
    // }
    char tmp[15] ;
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout) ;
    scanf("%s", tmp);
    if(tmp[0] == 'B') {
        exit(0);
    }
    return tmp[0] == 'Y';
}

int main() {
    scanf("%d", &N);
    int r = 1, c = 1 ;

    for(int i=0; r+c-1 < N; i++) {
        if(c + 1 <= N && query(r, c+1, N, N)) {
            ans[i] = 'R';
            c ++;
        }
        else {
            ans[i] = 'D';
            r ++;
        }
    }

    r = N, c = N;
    for(int i=2*(N-1) - 1; r+c-2 >= N; i--) {
        if(r - 1 > 0 && query(1, 1, r-1, c)) {
            ans[i] = 'D';
            r --;
        }
        else {
            ans[i] = 'R';
            c --;
        }
    }

    printf("! %s\n", ans);
}
