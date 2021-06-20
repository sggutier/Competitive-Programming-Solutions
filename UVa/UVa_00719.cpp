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

void testCase() {
    static char lin[limN];
    static int SA[limN];
    int n, n2 ;
    fgets(lin, limN, stdin);
    n = strlen(lin);
    lin[--n] = 0;
    for(int i=0; i<n; i++)
        lin[i+n] = lin[i];
    n2 = 2 * n;
    lin[n2+1] = 0;
    lin[n2] = 'a' + 26;
    constructSA(n2+1, lin, SA);
    for(int i=0; i<=n2; i++) {
        if(SA[i] < n) {
            printf("%d\n", SA[i]+1);
            return ;
        }
    }
}

int main() {
    int tc;
    char tmp[50];
    fgets(tmp, 50, stdin);
    tc = atoi(tmp);
    while(tc--)
        testCase();
}
