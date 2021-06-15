#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int LIM_N = 1e6 + 5;

int N ;
pii pts[LIM_N];
vector <int> ptsAtX[LIM_N];
vector <int> ptsAtY[LIM_N];
bool usd[LIM_N];

void removeL() {
    static int pos = 0 ;
    for(int remCnt=0; !remCnt && pos < LIM_N; pos++) {
        for(auto y = ptsAtX[pos].begin(); y != ptsAtX[pos].end(); y++) {
            if(usd[*y]) continue;
            N -- ;
            printf("%d ", *y);
            usd[*y] = true;
            remCnt ++;
        }
    }
}

void removeU() {
    static int pos = LIM_N-1 ;
    for(int remCnt=0; !remCnt && pos >= 0; pos--) {
        for(auto x = ptsAtY[pos].begin(); x != ptsAtY[pos].end(); x++) {
            if(usd[*x]) continue;
            N -- ;
            printf("%d ", *x);
            usd[*x] = true;
            remCnt ++;
        }
    }
}

void removeR() {
    static int pos = LIM_N-1 ;
    for(int remCnt=0; !remCnt && pos >= 0; pos--) {
        for(auto y = ptsAtX[pos].rbegin(); y != ptsAtX[pos].rend(); y++) {
            if(usd[*y]) continue;
            N -- ;
            printf("%d ", *y);
            usd[*y] = true;
            remCnt ++;
        }
    }
}

void removeD() {
    static int pos = 0 ;
    for(int remCnt=0; !remCnt && pos < LIM_N; pos++) {
        for(auto x = ptsAtY[pos].rbegin(); x != ptsAtY[pos].rend(); x++) {
            if(usd[*x]) continue;
            N -- ;
            printf("%d ", *x);
            usd[*x] = true;
            remCnt ++;
        }
    }
}

int main() {
    function<void()> remFncs[] = {removeL, removeU, removeR, removeD};

    scanf("%d", &N);
    for(int i=1; i <= N; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        ptsAtX[pts[i].x].push_back(i);
        ptsAtY[pts[i].y].push_back(i);
    }

    for(int i=0; i < N; i++) {
        sort(ptsAtX[i].begin(), ptsAtX[i].end(), [](const int a, const int b) {return pts[a] < pts[b];});
        sort(ptsAtY[i].begin(), ptsAtY[i].end(), [](const int a, const int b) {return pts[a] < pts[b];});
    }

    for(int d=0; N > 0; d = (d+1) % 4) {
        remFncs[d]();
    }
    printf("\n");
}
