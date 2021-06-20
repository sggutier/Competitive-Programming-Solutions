#include <bits/stdc++.h>
using namespace std;
const int limN = 10000000;
const int limP = 11;

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

int ht[2*limP+1][4];

void testCase(int n) {
    if(n <= 2*limP) {
        if(ht[n][0]) {
            printf("%d", ht[n][0]);
            for(int j=1; j<4; j++)
                printf(" %d", ht[n][j]);
            printf("\n");
        }
        else
            printf("Impossible.\n");
        return;
    }
    if(n%2) {
        printf("2 7 ");
        n -= 9;
    }
    else {
        printf("3 7 ");
        n -= 10;
    }    
    for(const int &p:primos) {
        if(p > n) break;            
        if(!comp[n-p]) {
            printf("%d %d\n", p, n-p);
            return;
        }
    }
}

int main() {
    criba();
    for(const int &a:primos) {
        if(a>2*limP) break;
        for(const int &b:primos) {
            if(b>2*limP) break;
            for(const int &c:primos) {
                if(c>2*limP) break;
                for(const int &d:primos) {
                    int s = a+b+c+d;
                    if(s <= 2*limP) {
                        ht[s][0] = a;
                        ht[s][1] = b;
                        ht[s][2] = c;
                        ht[s][3] = d;
                    }
                }
            }
        }
    }

    int n ;

    while(scanf("%d", &n)!=EOF) {
        testCase(n);
    }
}
