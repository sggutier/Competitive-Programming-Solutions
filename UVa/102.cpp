#include <bits/stdc++.h>
using namespace std;

void caso(int tmp) {
    int sum = 0;
    int arr[3][3] ;
    string bins = "BGC";
    int comb[3] = {0, 1, 2};
    pair <int, string> ans;
    ans.first = (1<<30);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i||j) {
                scanf("%d", &arr[i][j]);
            }
            else
                arr[i][j] = tmp;
            sum += arr[i][j];
        }
    }
    do {
        tmp = sum;
        string a="###";
        for(int i=0; i<3; i++) {
            tmp -= arr[i][comb[i]];
            a[i] = bins[comb[i]];
        }
        ans = min(ans, pair<int, string>(tmp, a));
    }while(next_permutation(comb, comb+3));    
    printf("%s %d\n", ans.second.c_str(), ans.first);
}

int main() {
    int tmp;
    while(scanf("%d", &tmp)!=EOF) {
        caso(tmp);
    }
    return 0;
}
