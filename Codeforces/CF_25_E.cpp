#include <bits/stdc++.h>
using namespace std;

int maxMtch(string &A, string &B) {
    int N = A.size(), M = B.size();
    vector <int> ant(M+1);
    int i, j;
    ant[0] = -1;
    for(i=-1, j=0; j<M; ) {
        while(i!=-1 && B[i] != B[j])
            i = ant[i];
        i++, j++;
        ant[j] = i;
    }
    for(i=0, j=0; j<N; ) {
        while(i!=-1 && B[i]!=A[j])
            i = ant[i];
        i++, j++;
        if(i==M)
            return M;
    }
    return i ;
}

int main() {
    string strs[3];
    int ans = 1e9;

    for(int i=0; i<3; i++)
        cin >> strs[i];

    sort(strs, strs+3);
    do {
        string w = strs[0];
        for(int i=1; i<3; i++) {
            int olp = maxMtch(w, strs[i]);
            w += strs[i].substr(olp, strs[i].size()-olp);
        }
        ans = min(ans, (int) w.size());
    } while(next_permutation(strs, strs+3));

    printf("%d\n", ans);
}
    
