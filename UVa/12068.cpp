#include <bits/stdc++.h>
using namespace std;

struct Fraco {
    long long num, den;
    Fraco operator+(Fraco otr) {
        Fraco ans;
        long long mcm = (otr.den / __gcd(this->den, otr.den))*this->den;
        // printf("%lld/%lld -> %lld/%lld => %lld\n", this->num, this->den, otr.num, otr.den, mcm);
        ans.num = this->num*(mcm/this->den) + otr.num*(mcm/otr.den) ;
        ans.den = mcm;
        return ans;
    }
    Fraco() {
    }
    Fraco(long long _num, long long _den): num(_num), den(_den) {
        long long geco = __gcd(num, den);
        num /= geco;
        den /= geco;
    }
};

void testCase() {
    int N;
    Fraco ans = Fraco(0,1);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {

        int a;
        scanf("%d", &a);
        ans = ans + Fraco(1, a);
        // printf("%lld/%lld\n", ans.num, ans.den);
    }
    ans = Fraco(ans.den*N, ans.num);

    printf("%lld/%lld\n", ans.num, ans.den);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
