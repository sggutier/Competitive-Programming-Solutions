#include <bits/stdc++.h>
using namespace std;
const int limS = 43545600;

int N ;
bitset <limS> usdSt;
list <int> A, B;
int facts[] = {1, 1, 2, 6, 24, 120, 720, 5760, 362880, 3628800};

int toSt() {
    int p = N;
    int w = A.size();
    w *= facts[p--];
    bool usd[] = {false, false, false, false, false, false, false, false, false, false, false};
    for(int c:A) {
        // printf("%d ", c);
        for(int i=0; i<=c; i++)
            if(usd[i]) c--;
        // printf("[%d %d] ", c, p);
        w += c*facts[p--];        
    }
    // printf("\n");
    for(int c:B) {
        // printf("%d ", c);
        for(int i=0; i<=c; i++)
            if(usd[i]) c--;
        // printf("[%d %d] ", c, p);
        w += c*facts[p--];
    }
    // printf("\n^  %d\n", w);
    return w;
}

int main() {
    int x, y;
    
    scanf("%d", &N);
    scanf("%d", &x);
    for(int i=0, a; i<x; i++) {
        scanf("%d", &a); a--;
        A.push_back(a);
    }
    scanf("%d", &y);
    for(int i=0, a; i<y; i++) {
        scanf("%d", &a); a--;
        B.push_back(a);
    }

    int t = 0;
    while(true) {
        int w = toSt();
        if(usdSt[w]) {
            printf("-1\n");
            return 0;
        }
        usdSt[w] = true;
        if(A.empty() || B.empty())
            break;
        t ++;
        int x = A.front(); A.pop_front();
        int y = B.front(); B.pop_front();
        if(x > y) {
            A.push_back(y);
            A.push_back(x);
        }
        else {            
            B.push_back(x);
            B.push_back(y);
        }
    }
    printf("%d %d\n", t, A.empty()? 2 : 1);
}
