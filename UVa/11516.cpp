#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 ;
#define tip int

bool works(int n, int arr[], int rem, tip dst) {
    rem --;
    tip pos = arr[0] + dst;
    for(int i=1; i<n; i++) {
        if(abs(arr[i] - pos) > dst) {
            if(rem==0) {
                return false;
            }
            rem --;
            pos = arr[i] + dst;
        }
    }
    return true;
}

void testCase() {
    int N, rem;
    int arr[limN];
    tip ini=0, fin=0;

    scanf("%d%d", &rem, &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        arr[i] *= 100;
        fin = max(fin, arr[i]);
    }
    sort(arr, arr+N);

    while(ini<fin) {
        tip piv = (ini+fin)/2 ;
        if(works(N, arr, rem, piv))
            fin = piv;
        else
            ini = piv+1;
    }
    
    ini /= 10;
    printf("%d.%d\n", ini/10, ini%10);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
