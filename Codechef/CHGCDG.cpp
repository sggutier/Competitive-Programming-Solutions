#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

bool isComp[limN];
int P ;
vector <int> primos;
vector <int> dvs[limN];
vector <int> cnts[limN];

void criba(int N = limN) {
    for(int i=2; i<limN; i++)
        if(!isComp[i]) {
            int w = (int) primos.size();
            for(int j=i; j<limN; j+=i) {
                isComp[j] = true;
                dvs[j].push_back(w);
            }
            primos.push_back(i);
        }
    P = (int) primos.size();
}

int calca(vector<int> &cnt, int pv) {
    int ans = 0;
    int N = (int) cnt.size();
    for(int i=0, k=1, sms=0; i<N; k++) {
        while(i<N && cnt[i] < k) {
            sms += cnt[i];
            i++, pv++;
        }
        if(i==N) break;
        int w = 0;
        for(int j=i; j<N; j++)
            w += (cnt[j]-k) / 2;
        if(w < k*pv - sms)
            break;
        ans = k;
    }
    cnt.clear();
    return ans;
}

void testCase() {
    int N ;
    scanf("%d", &N);

    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        // printf("%d => ", a);
        for(const int d : dvs[a]) {
            int p = primos[d], w = 0;
            while(a % p == 0) {
                a /= p;
                w ++;
                // printf("%d ", p);
            }
            cnts[d].push_back(w);
        }
        // printf("\n");
    }

    int fc = 1;
    for(int i=0; i<P; i++) {
        if(cnts[i].empty()) continue;
        sort(cnts[i].begin(), cnts[i].end());
        // printf("%d === ", primos[i]);
        // for(const int a : cnts[i])
        //     printf("%d ", a);
        // printf("\n");
        int w = calca(cnts[i], N - (int) cnts[i].size());
        if(!w) continue;
        // printf("\t%d || %d\n", primos[i], w);
        while(w--)
            fc *= primos[i];
    }
    printf("%d\n", fc);
}

int main() {
    criba();
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
