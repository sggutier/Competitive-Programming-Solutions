#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 10;

ll pots[limN];

int main() {
    pots[0] = 1;
    for(int i=1; i<limN; i++)
        pots[i] = pots[i-1]*10;
    int n ;
    set<int> ans ;

    cin >> n ;
    for(int d=1; d<=limN; d++ ) {
        int ini = (1<<(d-1)), fin = 1<<d;
        for(int b=ini; b<fin; b++) {
            for(int x=1; x<10; x++) {
                for(int y=0; y<10; y++) {
                    // if(y<x && y) continue;
                    ll s = 0;
                    for(int i=0; i<d; i++)
                        s += pots[i]*( (1<<i) & b? x : y );
                    //cout << d << " "  << b << " " << s << endl;                    
                    if(s <= n) {
                        //cout << "este" << endl;
                        //cout << b << " " << s << endl;                    
                        ans.insert(s);
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
}
