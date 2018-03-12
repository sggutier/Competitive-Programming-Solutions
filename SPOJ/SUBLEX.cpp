#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

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
    int lcp[limN];
    long long tots[limN];
    int n, Q ;
    // int numsi[limN], poss[limN];
    // int w = 1;
    // numsi[0] = -1e9;
    
    scanf("%s", lin);
    n = strlen(lin);
    //lin[n++] = 'a' + 27;
    lin[n++] = '$';
    
    constructSA(n, lin, SA);
    computeLCP(n, lin, SA, lcp);
    lin[--n] = 0;
    // poss[0] = n+1;
    // vector <int> sigP(n+1, 0);

    // for(int i=n; i>=0; i--) {
    //     int k = upper_bound(numsi, numsi + w, lcp[i]) - numsi - 1;
    //     sigP[i] = poss[k];
    //     if(numsi[k]!=lcp[i]) k++;
    //     numsi[k] = lcp[i];
    //     poss[k] = i;
    //     w = k+1;
    //     //tots[i] = sigP[i] - i;
    // }
    tots[0] = 0;
    for(int i=1; i<=n; i++) {
        tots[i] = (n-SA[i]) - lcp[i];
        //tots[i] = tots[i]*(sigP[i]-i);
        tots[i] += tots[i-1];
    }
    // for(int i=0; i<=n; i++)
    //     printf("%2d | %3d %3d %3lld => %s\n", i, n-SA[i]-lcp[i], lcp[i], tots[i], lin + SA[i]);

    scanf("%d", &Q);    
    for(int i=0; i<Q; i++) {
        int a ;
        scanf("%d", &a);
        a--;
        // printf("%s\n", lin + SA[a]);
        int p = upper_bound(tots, tots+n+1, a) - tots;
        a -= tots[p-1];
        // printf("%d %d => ", p, a);
        for(int f=a+lcp[p]+1, j=0; j<f; j++)
            printf("%c", (lin + SA[p])[j]);
        printf("\n");
    }
}

int main() {
    testCase();
}
