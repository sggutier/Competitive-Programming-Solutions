#include <bits/stdc++.h>
using namespace std;
const int limN = 32000 + 5;
//const int limN = 1e6 + 5;

int primCnt = 0;
int primos[limN];
bool comp[limN];
vector <int> smiths;

void precarga(int N = limN) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

int sumDigs(int n) {
    int ans = 0;
    while(n) {
        ans += n%10;
        n /= 10;
    }
    return ans;
}

bool isSmith(int N) {
    int A = sumDigs(N), B = 0;
    int k=0;
    int facCnt = -1;

    while(k<primCnt && N>=primos[k]) {
        int w = primos[k++];
        if(N%w)
            continue;
        int r = sumDigs(w);
        while(N%w==0) {
            B += r;
            N /= w;
            facCnt ++;
        }
    }
    if(N>1) {
        int w = sqrt(N);
        if(w*w==N) {
            B += 2*sumDigs(w);
            facCnt +=2 ;
        }
        else {
            B += sumDigs(N);
            facCnt ++;
        }
    }
    //printf("%d\n", facCnt);

    return facCnt!=0 && A == B;
}

void testCase() {
    int n;
    scanf("%d", &n);
    while(!isSmith(++n));
    printf("%d\n", n);
}

int main() {
    precarga();
    
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
