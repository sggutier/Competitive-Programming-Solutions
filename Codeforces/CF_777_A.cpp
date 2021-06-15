#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p ;
    int arr[] = {0, 0, 0};

    scanf("%d%d", &n, &p);
    n %= 6;
    arr[p] = 1;
    for(int i=n-1; i>=0; i--)
        swap(arr[1], arr[i%2? 2 : 0]);

    for(int i=0; i<3; i++)
        if(arr[i]==1)
            printf("%d\n", i);
}
