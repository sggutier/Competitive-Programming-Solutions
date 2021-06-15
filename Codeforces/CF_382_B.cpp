#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
typedef long long ll;

int tims[limN];
int as[limN];
bool usd[limN];

void ciclTim(int b, int w, int x, int &pcic, int &t, int &a) {
    t = 0;
    a = 0;
    //printf("X es %d\n", x);
    while(!usd[b]) {
        //printf("%d => %d %d\n", b, t, a);
        usd[b] = true;
        tims[b] = t++;
        as[b] = a;
        if(b >= x) {
            b = b-x;
            a++;
        }
        else {
            b = w-(x-b);
        }
    }
    t = t-tims[b];
    a = a-as[b];
    pcic = b;
}

int main() {
    int a, b, w, x, c;
    int dif, t, pcic;
    ll ans = 0;
    cin >> a >> b >> w >> x >> c ;
    dif = max(0, c-a);
    ciclTim(b, w, x, pcic, t, a);
    // a = 1e9 + 7;
    // pcic = -1;
    // t = 0;
    //printf("Ciclado en %d con %d %d\n", pcic, t, a);

    while(dif>0 && b != pcic) {
        ans ++;
        if(b >= x) {
            b = b-x;
            dif--;
        }
        else {
            b = w-(x-b);
        }
    }

    int k = max(0, dif/a-1);
    ans += k* ((ll) t);
    dif -= k*a;
    while(dif > 0) {
        ans ++;
        if(b >= x) {
            b = b-x;
            dif--;
        }
        else {
            b = w-(x-b);
        }
    }

    cout << ans << endl;
}
