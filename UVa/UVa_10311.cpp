#include <bits/stdc++.h>
using namespace std;
const int limN = 100000000;

bitset <limN> comp;
vector <int> primos;

void criba(int n =limN) {
    comp[0] = comp[1] = true;
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            primos.push_back(i);
}

void testCase(int n) {
    if(n%2) {
        if(n>2 && !comp[n-2])
            printf("%d is the sum of 2 and %d.\n", n, n-2);
        else
            printf("%d is not the sum of two primes!\n", n);
        return;
    }

    int pos = lower_bound(primos.begin(), primos.end(), n/2) - primos.begin() - 1;

    for(; pos>=0; pos--) {
        if(!comp[n-primos[pos]]) {
            printf("%d is the sum of %d and %d.\n", n, primos[pos], n-primos[pos]);
            return;
        }
    }
    printf("%d is not the sum of two primes!\n", n);
}

int main() {
    criba();
    int n ;
    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
