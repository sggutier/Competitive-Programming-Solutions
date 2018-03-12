#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
const int limN = 2e5 + 5;
const int limS = 101;

void countingSort(int n, int *SA, int *tempSA, int *RA, int k) {                                          // O(n)
    int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
    static int c[limN];
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA(int n, char *T, int *SA) {         // this version can go up to 100000 characters
    static int tempRA[limN], tempSA[limN], RA[limN];
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        countingSort(n, SA, tempSA, RA, k);  // actually radix sort: sort based on the second item
        countingSort(n, SA, tempSA, RA, 0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    }
}

int dueno[limN];
int owner(int idx) {
    // return (idx < n-m-1) ? 1 : 2;
    return dueno[idx];
}

void computeLCP(int n, char *T, int *SA, int *LCP) {
    static int Phi[limN], PLCP[limN];
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
        while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

void testCase(int n) {
    static char lin[limN];
    static int SA[limN];
    static int LCP[limN];
    int tot = 0;

    for(int i=0; i<n; i++) {
        int m = 0;
        char *s = lin+tot;
        fgets(s, limN, stdin);
        if(n==1) {
            printf("%s", lin);
            return;
        }
        for(m=0; s[m]!='\n'; m++, tot++) {
            dueno[tot] = i;
        }
        dueno[tot++] = i;
        s[m] = i+1;
    }

    constructSA(tot, lin, SA);
    computeLCP(tot, lin, SA, LCP);

    int ans = 0;
    vector <int> tips(n);
    multiset <int> eles;
    for(int i=0, j=0, tcnt=0; j<tot; j++) {
        if(tips[owner(SA[j])]++ == 0)
            tcnt++;
        eles.insert(LCP[j]);
        if(tcnt >= n) {
            while(i<j && tips[owner(SA[i])] > 1) {
                tips[owner(SA[i])]--;
                eles.erase(eles.find(LCP[i]));
                i++;
            }
            eles.erase(eles.find(LCP[i]));
            ans = max(ans, *eles.begin());
            eles.insert(LCP[i]);
        }
    }

    printf("%d\n", ans);    
}

int main() {
    int tc;
    char tmp[50];
    fgets(tmp, 50, stdin);
    int T = atoi(tmp);
    while(T--) {
        fgets(tmp, 50, stdin);
        tc = atoi(tmp);
        testCase(tc);
    }
}
