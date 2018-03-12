#include <bits/stdc++.h>
using namespace std;

bool sq(int *a) {
    return a[0] == a[1] && a[0] == a[2] && a[0] == a[3];
}

bool rt(int *a) {
    return a[0] == a[1] && a[2] == a[3];
}

bool qda(int *a) {
    return a[0] + a[1] + a[2] > a[3];
}

int main() {
    int n;
    int arr[4];

    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]);
        sort(arr, arr+4);
        if(sq(arr))
            printf("square\n");
        else if(rt(arr))
            printf("rectangle\n");
        else if(qda(arr))
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
}
