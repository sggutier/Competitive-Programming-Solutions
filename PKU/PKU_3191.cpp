/*
- I solved this becasue of a gut feeling.  I thought that for writing a number in
  base -2, it would need to have a power of -2 of its own sign either as big or a little
  bigger than it.
- The reason for picking the power of 2 of the same sign that was just bigger is that it
  could be the one that was able to be "swayed around".  Even with powers of 2 of the same
  sign, 1 + \ldots + 2^n < 2^{n+1}, so a bigger one is not neccessary.  For this same reason,
  picking something whose absolute value is bigger than the current number but of opposite
  sign does not make a lot of sense.
- If the bigger-absolute-value-than-the-current-number-but-with-same-sign number was not
  going to be used, that would mean that either the current number matches perfectly a power
  of -2, or that it can be summed with some of the powers of 2 with absolute value
  lesser or equal than the abs of the current number.
- I'm aware that this is not a proof, but it looked good enough to me and I was pretty sure
  it would work.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define abs(x) ( x > 0? x : -x )
const int limP = 34;
typedef long long ll;

ll pots[limP];
bool ans[limP];
ll sumaSgns[limP][2];

int sgno(ll n) {
    return n/abs(n)>0? 1 : 0;
}

void llena(ll n) {
    if(n==0) return;
    for(int i=0; i<limP; i++) {
        if(pots[i]==n) {
            ans[i] = true;
            return;
        }
        if(abs(sumaSgns[i][sgno(pots[i])]) >= abs(n) && sgno(pots[i])==sgno(n)) {
            ans[i] = true;
            llena(n-pots[i]);
            break;
        }
    }
}

int main() {
    pots[0] = 1;
    sumaSgns[0][sgno(1)] = 1;
    for(int i=1; i<limP; i++) {
        pots[i] = -pots[i-1]*2;
        sumaSgns[i][0] = sumaSgns[i-1][0];
        sumaSgns[i][1] = sumaSgns[i-1][1];
        sumaSgns[i][sgno(pots[i])] += pots[i];
    }
    ll n ;
    cin >> n ;
    for(; true; n++) {
        memset(ans, 0, sizeof(ans));
        // printf("%lld = \n", n);
        llena(n);
        int maxP = 0;
        for(int i=limP-1; i>=0; i--) {
            if(!ans[i])  continue;
            maxP = i;
            break;
        }
        for(int i=maxP; i>=0; i--)
            printf("%c", ans[i]? '1' : '0');
        printf("\n");
        break;
    }
}
