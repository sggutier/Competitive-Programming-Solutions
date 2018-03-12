#include <bits/stdc++.h>
using namespace std;

int k1, k2;
bool usd[100][100][2];
bool ganaMemo[100][100][2];

bool gana(int X, int Y, int t) {
    if(X==0 && t==0)
        return false;
    if(Y==0 && t==1)
        return false;
    if(usd[X][Y][t])
        return ganaMemo[X][Y][t];
    usd[X][Y][t] = true;
    if(t==0) {
        for(int i=min(X, k1); i>0; i--)
            if(!gana(X-i, Y, 1))
                return ganaMemo[X][Y][t] = true;
    }
    else {
        for(int i=min(Y, k2); i>0; i--)
            if(!gana(X, Y-i, 0))
                return ganaMemo[X][Y][t] = true;
    }
    return ganaMemo[X][Y][t] = false;
}

int main() {
    int x, y;
    scanf("%d%d%d%d", &x, &y, &k1, &k2);
    printf("%s\n", gana(x, y, 0)? "First" : "Second");
}
