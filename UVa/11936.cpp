#include <bits/stdc++.h>
using namespace std;

bool qda(int *a) {
    return a[0] + a[1] > a[2];
}

int main() {
    int n;
    int arr[4];

    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);
        printf("%s\n", qda(arr)? "OK" : "Wrong!!");
    }
}
