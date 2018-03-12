#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct BIT {
    int n ;
    int arr[limN];
    BIT(int n) : n(n+3) {}
    void mete(int pos) {
        for(pos++; pos<n; pos+=(pos & -pos))
            arr[pos]++;
    }
    long long saca(int pos) {
        int ans = 0;
        pos++;
        pos = min(pos, n-1);
        for(; pos>0; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

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

void testCase() {
    static char lin[limN];
    static int SA[limN];
    char vald[limN];
    int lcp[limN];
    int sigP[limN], preP[limN];
    int n;
    int numsi[limN], poss[limN];
    int w = 1;
    numsi[0] = -1e9;

    scanf("%d", &n);
    scanf("%s", lin);
    scanf("%s", vald);
    lin[n++] = '$';
    BIT bt(n);
    
    constructSA(n, lin, SA);
    computeLCP(n, lin, SA, lcp);
    lin[--n] = 0;

    poss[0] = n+1;
    for(int i=n; i>=0; i--) {
        int k = lower_bound(numsi, numsi + w, lcp[i]) - numsi - 1;
        sigP[i] = poss[k]-1;
        k++;
        numsi[k] = lcp[i];
        poss[k] = i;
        w = k+1;
    }
    w = 1;
    poss[0] = -1;
    for(int i=0; i<=n; i++) {
        int k = lower_bound(numsi, numsi + w, lcp[i]) - numsi - 1;
        preP[i] = poss[k]+1;
        k++;
        numsi[k] = lcp[i];
        poss[k] = i;
        w = k+1;
    }

    long long ans = 0;

    vald[n] = '1';
    for(int i=0; i<=n; i++) {
        if(vald[SA[i]]=='1')
            continue;
        bt.mete(i);
        // else
        ans = max(ans, 0LL + n-SA[i]);
    }

    for(int i=0; i<=n; i++) {
        ans = max(ans, (bt.saca(sigP[i]) - bt.saca(preP[i]-2)) * lcp[i] );        
        printf("%2d %c == ", SA[i], vald[SA[i]]);
        printf("%2d | lcp is %3d | %3d %3d | %3lld %3lld %3lld %3lld  => %s\n", i, lcp[i], preP[i], sigP[i], bt.saca(preP[i]-2), bt.saca(sigP[i]), (bt.saca(sigP[i]) - bt.saca(preP[i]-2)), (bt.saca(sigP[i]) - bt.saca(preP[i]-2)) * lcp[i], lin + SA[i]);
    }

    // for(int i=0; i<n; i++) {
    //     for(int t=1; i+t<=n; t++) {
    //         long long c = 0;
    //         for(int j=i; j+t<=n; j++) {
    //             if(vald[j]=='1')
    //                 continue;
    //             bool works = true;
    //             for(int k=0; k<t; k++)
    //                 works &= lin[i+k] == lin[j+k];
    //             if(works)
    //                 c++;
    //         }
    //         printf("%lld %d\n", c, t);
    //         ans = max(ans, c*t);
    //     }
    // }

    printf("%lld\n", ans);

    return;
}

int main() {
    testCase();
}
