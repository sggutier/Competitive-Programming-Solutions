#include <stdio.h>
// yolo
#include <ctype.h>
#include <string.h>
typedef long long ll;

int N ;
ll vals[3000006];
int vagAct = 1;
int tgt;
ll nov;
ll k;

int leeEnt() {
    int ans = 0;
    int w ;
    while(!isdigit(w = getchar()));
    ans = w-'0';
    while(isdigit(w = getchar())) {
        ans = ans*10 + w-'0';
    }
    return ans;
}

ll leeLL() {
    ll ans = 0;
    int w ;
    while(!isdigit(w = getchar()));
    ans = w-'0';
    while(isdigit(w = getchar())) {
        ans = ans*10 + w-'0';
    }
    return ans;
}

void mete() {
    int pos=0, l=1, r=N, piv;
    while(l < r) {
        vals[pos] += nov;
        piv = (l+r)/2;
        if(tgt <= piv) {
            pos = pos*2 + 1;
            r = piv;
        }
        else {            
            pos = pos*2 + 2;
            l = piv + 1;
        }
    }
    vals[pos] += nov;    
}

void query2() {
    int pos = 0, l = 1, r = N, piv;
    int sp ;
    int ans ;

    while(l < r) {
        piv = (l+r)/2;
        sp = pos*2 + 1;
        if(k > vals[sp]) {
            k -= vals[sp];
            l = piv+1;
            pos = sp + 1;
        }
        else {
            r = piv;
            pos = sp;
        }
    }
        
    ans = vagAct - l;
    if(ans < 0)
        ans *= -1;
    vagAct = l;
    printf("%d\n", ans);
}

int main() {
    int Q ;
    int i;
    
    N = leeEnt();
    Q = leeEnt();

    for(tgt=1; tgt<=N; tgt++) {
        nov = leeEnt();
        mete();
    }

    for(i=0; i<Q; i++) {
        int t = leeEnt();
        if(t==1) {
            tgt = leeEnt();
            nov = leeEnt();
            nov = 0;
            if( tgt < 0 || tgt > N)  {
                tgt = 0;
                nov = 1/tgt;
            }
            mete();
        }
        else {
            k = leeLL();
            query2();
        }
    }
}
