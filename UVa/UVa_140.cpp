#include <bits/stdc++.h>
using namespace std;

int calcBW(const int &n, int *arr, const vector <list<int>> &adj) {
    int sim[26];
    int ans = 0;
    for(int i=0; i<n; i++)
        sim[arr[i]] = i;
    // for(int i=0; i<n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    for(int i=0; i<n; i++) {
        // printf("%d => ", arr[i]);
        for(const int &sig:adj[arr[i]]) {
            ans = max(ans, abs(i-sim[sig]));
            // printf(" (%d %d)", sig, sim[sig]);
        }
        // printf("\n");
    }
    // cout << ans << endl;
    return ans;
}

void testCase(char *s) {
    set <char> lets;
    vector <list<int>> adj(26);
    while(*s) {
        int org = *s -'A';
        // printf("%c => ", org + 'A');
        lets.insert(org);
        s++;
        s++;

        while(*s && *s!=';') {
            // printf("%c", *s);
            int tmp = *s -'A';
            lets.insert(tmp);
            adj[org].push_back(tmp);
            adj[tmp].push_back(org);
            s++;
        }
        if(*s)
            s ++ ;
        // printf("\n");
    }

    int n = 0;
    int ans = (1<<30);
    int ansArr[(int) lets.size()];
    int arr[(int) lets.size()];
    for(const char &c:lets)
        arr[n++] = c;
    do {
        int tmp = calcBW(n, arr, adj);
        if(tmp<ans) {
            ans = tmp;
            for(int i=0; i<n; i++)
                ansArr[i] = arr[i];
        }
    } while(next_permutation(arr, arr+n)) ;
    for(int i=0; i<n; i++)
        printf("%c ", ansArr[i]+'A');
    printf("-> %d\n", ans);
}

int main() {
    char S[1000];
    while(gets(S) && S[0]!='#') {
        testCase(&S[0]);
    }
}
