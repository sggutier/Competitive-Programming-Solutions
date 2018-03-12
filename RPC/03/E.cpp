#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int limN = 1e5 + 5;
const ull potNumA = 27ULL;
const ull potNumB = 91ULL;
const ull potNumC = 255ULL;
const ull potNumD = 1023ULL;
const char lt= 'a' - 1;
// const char lt= 'a';
// const ull potNumB = 29;

ull hashea(char* s, ull pot) {
    ull ans = 0ULL;

    for(int i=0; s[i]; i++) {
        ans = ans*pot + (s[i] - lt) ;
    }
    return ans;
}

void testCase(int wordCnt, int Q, int wordLen) {
    map <pair<ull, pair<ull, pair<ull, ull>>>, int> dict;
    char S[limN];

    for(int i=0; i<wordCnt; i++) {
        scanf("%s", S);
        dict[make_pair(hashea(S, potNumD), make_pair(hashea(S, potNumC), make_pair(hashea(S, potNumA), hashea(S, potNumB))))]++;
        // cout << hashea(S) << endl;
    }

    for(int q=0; q<Q; q++) {
        scanf("%s", S);
        long long ans = 0LL;
        ull hsA = hashea(S, potNumA), hsB = hashea(S, potNumB), potA=1ULL, potB = 1ULL;
        ull hsC = hashea(S, potNumC), potC=1ULL;
        ull hsD = hashea(S, potNumD), potD=1ULL;
        for(int i=wordLen-1; i>=0; i--, potA*=potNumA, potB*=potNumB, potC*=potNumC, potD*=potNumD) {
            ull hsA2 = hsA - ((ull) (S[i] - lt))*potA;
            ull hsB2 = hsB - ((ull) (S[i] - lt))*potB;
            ull hsC2 = hsC - ((ull) (S[i] - lt))*potC;
            ull hsD2 = hsD - ((ull) (S[i] - lt))*potD;
            // char ant = S[i];
            // cout << hsA2 << endl;
            for(int j=1; j<=26; j++) {
                // S[i] = j + 'a';
                map <pair<ull, pair<ull, pair<ull, ull>>>, int>::iterator fnd = dict.find(make_pair(hsD2 + j*potD, make_pair(hsC2 + j*potC, make_pair(hsA2 + j*potA, hsB2 + j*potB)))) ;
                // map <ull, int>::iterator fnd = dict.find(hashea(S));
                // cout << hashea(S) << " " << hsA2 + j*pot << endl;
                if(fnd!=dict.end()) {
                    ans += fnd->second;
                }
            }
            // S[i] = ant;
        }
        printf("%lld\n", ans);
    }
}

int main() {
    int a, b, c ;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF) {
        testCase(a, b, c);
    }
    
    return 0;
}
