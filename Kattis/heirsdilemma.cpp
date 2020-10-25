#include <bits/stdc++.h>
using namespace std;

bool works(int n) {
        int usd = 0;
        int org = n;
        for(int i=0; i<6; i++, n/=10) {
                int k = n%10;
                if((1<<k) & usd) {
                        return false;
                }
                        usd |= 1<<k;
                        if(k==0 || org % k) {
                                return false;
                        }
        }
        return true;
}

int main() {
        int a, b ;
        int ans = 0;
        cin >> a >> b ;
        for(int i=a; i<=b; i++) {
                if(works(i))
                        ans ++;
        }
        printf("%d\n", ans);

}
