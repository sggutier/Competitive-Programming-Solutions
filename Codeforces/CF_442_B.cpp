#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

double calcP(vector <double> ps) {
    double dp[3] = {1.0, 0, 0};
    for(double p : ps) {
        double w = p;
        double nw = 1 - w;
        for(int i=2; i>=0; i--) {
            dp[min(i+1, 2)] += dp[i]*w;
            dp[i] *= nw;
        }
        
        // for(int i=0; i<3; i++)
        //     printf("%.3lf ", dp[i]);
        // printf("\n");
    }
    return dp[1];
}

int main() {
    int N ;
    double ps[limN];
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lf", &ps[i]);
    }
    sort(ps, ps+N);

    // for(int b=0; b<=(1<<N)-1; b++) {
    //     vector <double> arr;
    //     for(int i=0; i<N; i++)
    //         if((1<<i) & b)
    //             arr.push_back(ps[i]);
    //     for(int i=0; i<N; i++)
    //         printf("%d ", (1<<i) & b? 1 : 0);
    //     printf(" => %.3lf\n", calcP(arr));
    // }

    double ans = 0.0;
    for(int j=N-1; j>=0; j--) {
        vector <double> arr;
        for(int i=N-1; i>=j; i--)
            arr.push_back(ps[i]);
        // for(double p : arr)
        //     printf("%.3lf ", p);
        // printf("\n");
        // for(int i=0; i<N; i++)
        //     printf("%d ", (1<<i) & b? 1 : 0);
        // printf(" => %.3lf\n", calcP(arr));
        ans = max(ans, calcP(arr));
    }
    printf("%.9lf\n", ans);
    
    // printf("%.9lf\n", dp[1]);
}
