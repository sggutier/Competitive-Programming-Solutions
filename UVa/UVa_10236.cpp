// - There is a pattern: Every 3rd Fibonacci number is a multiple of 2, every 4th Fibo is a
//   multiple of 3, every 5th is a multiple of 5, every 6th is a multiple of 8 and so on.
//   Every kn-th Fibonacci number is multiple of the n-th Fibonacci number (where k is some
//   positive integer).  I have no proof for this, but it probably has something to do with
//   how Fibonacci is made.
// - This allows for something similar to a erathostenes sieve to be done, making it possible
//   to compute which numbers are Fibonacci primes.  
// - Once which positions are good are  the ones of Fibonacci primes, the actual numbers can
//   be computed.  For keeping the first 9 digits all the numbers are required for addition,
//   but Fibonacci numbers can get very big very fast, so this is too slow.  Fortunately the
//   nth fibonacci number is close to (phi^n)/sqrt(5), making it possible to compute with
//   the math in the links below.

#include <bits/stdc++.h>
using namespace std;
const int limN = 250000;
const long long d9 = 1e9;

bool esComp[limN];
vector <long long> ans;

// I wouldn't call the function calcaPot below completely mine.  I got ideas from here:
// https://en.wikipedia.org/wiki/Fibonacci_number#Computation_by_rounding
// https://math.stackexchange.com/questions/1726777/computing-first-k-digits-and-last-k-digits-of-a-large-number-using-logarithm
// https://www.geeksforgeeks.org/given-number-n-find-first-k-digits-nn/
long long calcaPot(long double product) {
    long double decimal_part = product - floorl(product);
    decimal_part = powl(10, decimal_part);
    long long digits = powl(10, 9 - 1);
    return decimal_part * digits;
}

void precalca() {
    for(int i=3; i<limN; i++)
        if(!esComp[i])
            for(int j=2*i; j<limN; j+=i)
                esComp[j] = true;
    long double phi = (1 + sqrtl(5))/2;
    long double lp = log10l(phi);
    long double lr = log10l(sqrtl(5));
    long long a=1, b=1, c=0;
    for(int i=3; i<limN; i++) {
        if(c < d9)
            c = a+b; 
        if(esComp[i]) {
            if(c < d9) {
                a = b ;
                b = c;
            }
            continue;
        }
        if(c >= d9) {
            ans.push_back(calcaPot(i*lp-lr));
        }
        else {
            a = b ;
            b = c;
            ans.push_back(c);
        }
        if((int) ans.size()  > 22001)
            break;
    }
}

int main() {
    precalca();
    int N ;
    while(scanf("%d", &N)!=EOF && N)
        printf("%lld\n", ans[N-1]);
}
