#include <bits/stdc++.h>
using namespace std;

bool testCase(int n, int* arr) {
    vector <bool> usd(1001, false);
    usd[0] = true;
    for(int i=0; i<n; i++) {
        if(i && arr[i] <= arr[i-1])
            return false;
        if(usd[arr[i]])
            return false;
        for(int j=1000-arr[i]; j>=0; j--) {
            if(usd[j])
                usd[j+arr[i]] = true;
        }
    }
    return true;
}

int main() {
    int tc = 0;
    int n;
    int arr[50];
    while(scanf("%d", &n)!=EOF) {
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        printf("Case #%d:", ++tc);
        for(int i=0; i<n; i++)
            printf(" %d", arr[i]);
        printf("\nThis is %san A-sequence.\n", testCase(n, arr)? "" : "not ");
    }
}
