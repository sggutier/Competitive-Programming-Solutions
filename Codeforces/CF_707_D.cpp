#include <bits/stdc++.h>
using namespace std;
const int LIM_Q = 1e5 + 5;
const int LIM_N = 1e3 + 5;

int C ;

struct Shelf {
    int cnt;
    bitset<LIM_N> dts;
    Shelf() {
        cnt = 0 ;
    }
    Shelf(const Shelf &x) {
        cnt = x.cnt;
        dts = x.dts;
    }
    Shelf* place(int pos) const {
        Shelf* ans = new Shelf(*this);
        if(ans->dts[pos]) {}
        else {
            ans->cnt ++;
            ans->dts[pos] = 1;
        }
        return ans;
    }
    Shelf* remove(int pos) const {
        Shelf* ans = new Shelf(*this);
        if(ans->dts[pos]) {
            ans->cnt --;
            ans->dts[pos] = 0;
        }
        return ans;
    }
    Shelf* invert() const {
        Shelf* ans = new Shelf(*this);
        ans->cnt = (C - cnt);
        ans->dts.flip();
        return ans;
    }
};

int QS[LIM_Q][3];
Shelf* ss[LIM_Q];
int truAns[LIM_Q] ;

int main() {
    int R, Q ;
    scanf("%d%d%d", &R, &C, &Q);
    for(int i=1, t, x, y; i <= Q; i++) {
        scanf("%d%d", &t, &x);
        if(t < 3)
            scanf("%d", &y);
        QS[i][0] = t;
        QS[i][1] = x;
        QS[i][2] = y;
        truAns[i] = 0 ;
    }
    for(int k=1; k <= R; k++) {
        ss[0] = new Shelf();
        for(int i=1, t, x, y; i <= Q; i++) {
            t = QS[i][0];
            x = QS[i][1];
            if(t < 4) {
                ss[i] = ss[i-1];
                if(t < 3)
                    y = QS[i][2];
                if(x == k) {
                    if(t == 1)
                        ss[i] = ss[i]->place(y);
                    else if(t == 2)
                        ss[i] = ss[i]->remove(y);
                    else
                        ss[i] = ss[i]->invert();
                }
            }
            else {
                ss[i] = ss[x];
            }
            truAns[i] += ss[i]->cnt;
        }
    }
    for(int i=1; i <= Q; i++)
        printf("%d\n", truAns[i]);
}
