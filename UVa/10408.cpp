#include <bits/stdc++.h>
using namespace std;
const int limN = 1000;

struct Frac {
    int num, den;
    Frac() {
        num = 0, den = 1;
    }
    Frac(int _num, int _den): num(_num), den(_den) {}
    bool operator<(Frac B) {
        int a=this->num * B.den, b = this->den * B.num;
        return a<b;
    }
};

int fracCnt = 0;
Frac fracs[limN*limN];

void precarga() {
    fracs[fracCnt++] = Frac(1, 1);
    for(int den=1; den<=limN; den++) {
        for(int num=1; num<den; num++) {
            if(__gcd(num, den)==1)
                fracs[fracCnt++] = Frac(num, den);
        }
    }
    sort(fracs, fracs+fracCnt);
}

void testCase(int n, int k) {
    for(int i=0; i<fracCnt; i++) {
        if(fracs[i].den<=n) {
            k --;
            if(k==0) {
                printf("%d/%d\n", fracs[i].num, fracs[i].den);
                return;
            }
        }
    }
}

int main() {
    precarga();
    int n, k;
    while(scanf("%d%d", &n, &k)!=EOF) {
        testCase(n, k);
    }
}
