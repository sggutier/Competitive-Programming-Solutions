#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define par pair<ll, int>
const int rounds = 20;
const int limN = (1<<22);
const int limP = 295947 + 1;

int primCnt = 0;
int primos[limP];
bool comp[limN];

void criba() ;

// Computes (a * b) % mod

ll mod_mul( ull a, ull b, ull mod ) {

    ull x = 0, y = a%mod;

    while( b > 0 ) {

        if( b&1 ) {

            x = x+y;

            x = ( x > mod ? x-mod : x );

        }

        y = y*2LL;

        y = ( y > mod ? y-mod : y );

        b >>= 1;

    }

    return x;

}



// Computes ( a ^ exp ) % mod.

long long modular_pow(long long a, long long exp, long long mod) {

    long long ans = 1;

    while (exp > 0) {

        if (exp & 1)

            ans = mod_mul(ans, a, mod);

        a = mod_mul(a, a, mod);

        exp >>= 1;

    }

    return ans;

}

// /* method to return prime divisor for n */
// long long int PollardRho(long long int n)
// {
//     /* initialize random seed */
//     srand (time(NULL));
 
//     /* no prime divisor for 1 */
//     if (n==1) return n;
 
//     /* even number means one of the divisors is 2 */
//     if (n % 2 == 0) return 2;
 
//     /* we will pick from the range [2, N) */
//     long long int x = (rand()%(n-2))+2;
//     long long int y = x;
//     long long int c = (rand()%(n-1))+1;
//     long long int d = 1;  
 
//     /* until the prime factor isn't obtained.
//        If n is prime, return n */
//     while (d==1) {
//         /* Tortoise Move: x(i+1) = f(x(i)) */
//         x = (modular_pow(x, 2, n) + c + n)%n;
 
//         /* Hare Move: y(i+1) = f(f(y(i))) */
//         y = (modular_pow(y, 2, n) + c + n)%n;
//         y = (modular_pow(y, 2, n) + c + n)%n;
 
//         /* check gcd of |x-y| and n */
//         d = __gcd(abs(x-y), n);
 
//         /* retry if the algorithm fails to find prime factor
//          * with chosen x and c */
//         if (d==n) return PollardRho(n);
//     }
 
//     return d;
// }

long long PollardRho(long long n) {

  long long x, y, i = 1, k = 2, d;

  x = y = rand() % n;

  while (1) {

    ++i;

    x = mod_mul(x, x, n);

    x += 2;

    if (x >= n) x -= n;

    if (x == y) return 1;

    d = __gcd(abs(x - y), n);

    if (d != 1) return d;

    if (i == k) {

      y = x;

      k *= 2;

    }

  }

  return 1;

}

// checks whether a is a witness that n is not prime, 1 < a < n

bool witness(long long a, long long n) {

    // check as in Miller Rabin Primality Test described

    long long u = n - 1;

    int t = 0;

    while (u % 2 == 0) {

        t++;

        u >>= 1;

    }

    long long next = modular_pow(a, u, n);

    if (next == 1) return false;

    long long last;

    for (int i = 0; i < t; ++i) {

        last = next;

        next = mod_mul(last, last, n);

        if (next == 1) {

            return last != n - 1;

        }

    }

    return next != 1;

}

// Checks if a number is prime with prob 1 - 1 / (2 ^ it)

//  D(miller_rabin(99999999999999997LL) == 1);

//  D(miller_rabin(9999999999971LL) == 1);

//  D(miller_rabin(7907) == 1);
bool miller_rabin(long long n, int it = rounds) {
    // cout << "milarin' " << n << endl;

    if (n <= 1) return false;

    if (n == 2) return true;

    if (n % 2 == 0) return false;

    for (int i = 0; i < it; ++i) {

        long long a = rand() % (n - 1) + 1;

        if (witness(a, n)) {

            // cout << "^ is NOT prime" << endl;
            return false;

        }

    }
    // cout << "^ is prime" << endl;

    return true;

}

vector<par> tryToBreak(ll n) {
    if(miller_rabin(n))
        return vector<par>(1,par(n, 1));
    // roto = sqrt(n);
    // cout << "staruting" << endl;
    ll f = PollardRho(n);
    // cout << "finiched" << endl;

    // if(f==n)        

    f = min(f, n/f);
    vector <par> ans ;
    ans.push_back(par(f, 1));
    ans.push_back(par(n/f, 1));
    return ans;
}

vector <par> testCase(ll n) {
    vector <par> ans;
    // cout << primCnt << endl;
    for(int i=0; i<primCnt; i++) {
        if(n%primos[i])
            continue;
        int cnt = 0;
        while(n%primos[i]==0) {
            cnt ++;
            n /= primos[i];
        }
        ans.push_back(par(primos[i], cnt));
        if(n==1)
            break;
    }
    // cout << "hiar" << endl;
    if(n!=1) {
        ll k = sqrt(n);
        if(k*k==n) {
            ans.push_back(par(k, 2));
        }
        else if(k>limN) {
            vector <par> tmp = tryToBreak(n);
            for(auto &t: tmp)
                ans.push_back(t);
        }
        else {
            // cout << "moo" << endl;
            ans.push_back(par(n, 1));
        }
    }
    return ans;
}

int main() {
    criba();
    int tc;

    for(scanf("%d", &tc); tc; tc--) {
        ll n ;
        vector<par> ans;
        bool fst = true;
        scanf("%lld", &n);
        ans = testCase(n);
        for(auto &a: ans) {
            for(int i=a.second; i; i--) {
                if(!fst)
                    printf(" ");
                fst = false;
                printf("%lld", a.first);
            }
        }
        printf("\n");
    }
   
    return 0;    
}

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!comp[i])
            for(int j=i*i; j<limN; j+=i)
                comp[j] = true;
    for(int i=2; i<limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}
