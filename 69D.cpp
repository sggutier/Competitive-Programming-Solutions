#include <bits/stdc++.h>
using namespace std;
const int dsp = 200;
const int limN = 4*dsp + 5;

int N, D ;
bool usd[limN][limN][2][2];
bool ganaMemo[limN][limN][2][2];
int vecs[limN][2];

bool gana(int x, int y, int a, int b) {
    if(x*x + y*y > D)
        return true;
    if(usd[x+dsp][y+dsp][a][b])
        return ganaMemo[x+dsp][y+dsp][a][b];
    usd[x+dsp][y+dsp][a][b] = true;
    if(a==0 && !gana(y, x, b, 1)) {        
        // printf("%d %d (%d %d) gana al hacer reflo \n", x, y, a, b);
        return ganaMemo[x+dsp][y+dsp][a][b] = true;
    }
    else {
        for(int i=0; i<N; i++) {
            if(!gana(x+vecs[i][0], y+vecs[i][1], b, a)) {
                // printf("%d %d (%d %d) gana al hacer + %d %d\n", x, y, a, b, x+vecs[i][0], y + vecs[i][1]);
                return ganaMemo[x+dsp][y+dsp][a][b] = true;
            }
        }
        // printf("%d %d (%d %d) pierde\n", x, y, a, b);
        return ganaMemo[x+dsp][y+dsp][a][b] = false;
    }
}

int main() {
    int x, y;
    scanf("%d%d%d%d", &x, &y, &N, &D);
    D *= D;
    for(int i=0; i<N; i++)
        scanf("%d%d", &vecs[i][0], &vecs[i][1]);
    printf("%s\n", gana(x, y, 0, 0)? "Anton" : "Dasha");
}
