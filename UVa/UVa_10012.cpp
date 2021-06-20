#include <bits/stdc++.h>
using namespace std;

double calcLen(const int &N, double* nums, double *dists) {
    double p;
    double b, c;
    double ans = 2*nums[0];
    dists[0] = p = nums[0];
    for(int i=1; i<N; i++) {
        p = nums[i] ;
        for(int j=0; j<i; j++) {
            b = -2.0*dists[j];
            c = dists[j]*dists[j] - 4.0*nums[j]*nums[i];
            p = max(p, (-b + sqrt(b*b - 4*c))/2.0);
        }
        dists[i] = p;

        // printf("%.3lf (%.3lf)===\n ", dists[i], nums[i]);
        // for(int j=0; j<i; j++) {
        //     printf("%.3lf => (%.3lf)\n", hypot(dists[i]-dists[j], nums[i]-nums[j]), nums[j] + nums[i]);
        // }
        // int cnt = 0;
        // for(int j=0; j<i; j++) {
        //     if( hypot(dists[i]-dists[j], nums[i]-nums[j]) + 1e6 < nums[j] + nums[i] ) {
        //         printf("WTF\n");
        //     }
        //     if( fabs(hypot(dists[i]-dists[j], nums[i]-nums[j]) - (nums[j] + nums[i])) < 1e4)
        //         cnt ++;
        // }

        // if(cnt==0)
        //     printf("Hey\n");
        
        ans = max(ans, p + nums[i]);
    }
    return ans;
}

void testCase() {
    int N;
    double nums[10];
    double dists[10];
    double ans = 1e9;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%lf", &nums[i]);

    sort(nums, nums+N);
    do {
        ans = min(ans, calcLen(N, nums, dists));
        //break;
    } while(next_permutation(nums, nums+N)) ;

    sort(nums, nums+N);
    do {
        if(ans == calcLen(N, nums, dists))
            break;
        //break;
    } while(next_permutation(nums, nums+N)) ;

    printf("%.3lf\n", ans);
    // printf("Graphics[{");
    // double maxX = 0.0, maxY = 0.0;
    // for(int i=0; i<N; i++) {
    //     if(i)
    //         printf(",");
    //     printf("Circle[{%.3lf, %.3lf}, %.3lf]", dists[i], nums[i], nums[i]);
    //     maxX = max(maxX, dists[i] + nums[i]);
    //     maxY = max(maxY, 2*nums[i]);
    // }
    // printf(",Rectangle[{0,0}, {%.3lf, %.3lf}]", maxX, maxY);
    // printf("}]\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase() ;
}
