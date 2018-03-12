#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, n;
    cin >> n >> x >> y ;
    for(int k=max(x, y); k>=0; k--) {
        if(k>x || k>y)
            continue;
        int a=x-k, b=y-k;
        bool works = true;
        for(int i=2; i<n; i++) {
            if(a>=k)
                a-=k;
            else if(b>=k)
                b-=k;
            else {
                works =false;
                break;
            }
        }
        if(works) {
            cout << k << endl;
            return 0;            
        }
    }
}
