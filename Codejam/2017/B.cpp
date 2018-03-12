#include <bits/stdc++.h>
using namespace std;

void testCase(long long k) {
    char arr[22];
    int n, pos ;
    sprintf(arr, "%lld", k);
    n = strlen(arr);

    for(pos=1; pos<n && arr[pos]>=arr[pos-1]; pos++) ;

    if(pos!=n && arr[pos-1]=='1') {
        for(int i=1; i<n; i++)
            printf("9");
        printf("\n");
        return ;
    }
    else if(pos!=n) {
        // for(int i=pos-1, w = arr[pos-1]; i>=0 && arr[i]==w; i--)
        //  arr[i] -- ;
        for(pos-=2; pos>=0 && arr[pos]==arr[pos+1]; pos--) ;
        pos ++ ;
        arr[pos] -- ;
        pos ++ ;
        for(; pos<n; pos++)
            arr[pos] = '9';
    }

    printf("%s\n", arr);
}

int main() {
    // int lst = 1;
    // int mark[10000] ;

    // for(int i=1; i<=1000; i++) {
    //     int k = i;
    //     bool itworks = true;
    //     while(k>=10) {
    //         if(k%10 < (k/10)%10) {
    //             itworks = false;
    //             break ;
    //         }
    //         k /= 10;
    //     }
    //     if(itworks)
    //         lst = i;
    //     // printf("%d -> %d -> ", i, lst);
    //     // testCase(i);
    //     mark[i] = lst;
    // }
    
    int tc ;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        long long k;
        scanf("%lld", &k);
        printf("Case #%d: ", i);
        // printf("%d\n", mark[k]);
        testCase(k);
    }
    
    return 0;
}
