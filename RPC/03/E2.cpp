#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int limN = 1e5 + 5;
const ull potNumA = 27ULL;
const ull potNumB = 27ULL;
const char lt= 'a' - 1;
// const char lt= 'a';
// const ull potNumB = 29;
const ull modA = 1e8 + 7;
const ull modB = 1e9 + 7;

ull hashea(char* s, ull pot, ull mod) {
    ull ans = 0ULL;

    for(int i=0; s[i]; i++) {
        ans = (ans*pot + (s[i] - lt))%mod ;
    }
    return ans;
}

void testCase(int wordCnt, int Q, int wordLen) {
    map <pair<ull, ull>, int> dict;
    char S[limN];

    for(int i=0; i<wordCnt; i++) {
        scanf("%s", S);
        dict[make_pair(hashea(S, potNumA, modA), hashea(S, potNumB, modB))]++;
        // cout << hashea(S, potNumA, modA) << "(" << hashea(S, potNumB, modB) << ")" << endl;
    }

    for(int q=0; q<Q; q++) {
        scanf("%s", S);
        long long ans = 0LL;
        ull hsA = hashea(S, potNumA, modA), hsB = hashea(S, potNumB, modB), potA=1ULL, potB = 1ULL;
        for(int i=wordLen-1; i>=0; i--, potA=(potA*potNumA)%modA, potB=(potB*potNumB)%modB) {
            ull hsA2 = (hsA + (modA - (((ull) (S[i] - lt))*potA)%modA))%modA;
            ull hsB2 = (hsB + (modB - (((ull) (S[i] - lt))*potB)%modB))%modB;
            // char ant = S[i];
            // cout << hsA2 << endl;
            for(int j=1; j<=26; j++) {
                // S[i] = j + 'a';
                map <pair<ull, ull>, int>::iterator fnd = dict.find(make_pair((hsA2 + j*potA)%modA, (hsB2 + j*potB)%modB)) ;
                // map <ull, int>::iterator fnd = dict.find(hashea(S));
                // cout << hashea(S) << " " << hsA2 + j*pot << endl;
                // printf("%llu (%llu) => %llu %llu\n", hsA, hsB, hsA2, hsB2);
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
