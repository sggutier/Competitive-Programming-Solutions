/*
ID: me60
LANG: C++11
TASK: sort3
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    
    int n;
    int ans = 0;
    int cnt[3] = {0, 0, 0};

    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        arr[i]--;
        cnt[arr[i]]++;
    }

    for(int i=0; i<cnt[0]; i++) {
        if(arr[i]==0)
            continue;
        ans ++;
        if(arr[i]==2) {
            for(int j=n-1; j; j--) {
                if(arr[j]==0) {
                    swap(arr[j], arr[i]);
                    break;
                }
            }
        }
        else {
            for(int j=cnt[0]; j<n; j++) {
                if(arr[j]==0) {
                    swap(arr[j], arr[i]);
                    break;
                }
            }
        }
    }
    for(int i=n-cnt[2]; i<n; i++) {
        if(arr[i]!=2)
            ans ++;
    }

    printf("%d\n", ans);
    
    return 0;
}
