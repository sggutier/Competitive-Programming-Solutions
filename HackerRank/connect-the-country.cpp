// - When joining the cities, the only important thing is how they are organized in
//   connected components and how many roads are left to build.
// - Because of that, a DP can be made using the amount of cities in each CC and the amount
//   of roads left as the state
// - For calculating the answer (the average of roads to be built) for each state, all the way
//   of joining a pair of components plus joining cities that are already on a component have
//   to be added
// - There are only ~5500 ways of having a non decreasing sequence that adds up to 30, times
//   ~450 roads to be built about 3e6 states.  This sounds reasonable, but still does not run
//   in time because of the transitions between states and other calculations.
// - Fortunately, this is enough time to precalculate it.  I coded it, then went for lunch, and
//   when I came back it was already finished.
#include <bits/stdc++.h>
using namespace std;
const int limN = 905;

map < vector<int>, double > memo[limN];

double dp(int k, vector <int> a) {
    if(a.size() == 1)
        return 0;
    if(memo[k].count(a))
        return memo[k][a];
    double ans = 0;
    int tot = 0;
    for(int i=a.size()-1, s; i>0; i--) {
        for(int j=i-1; j>=0; j--) {
            s = a[i] + a[j];
            vector <int> cpy;
            for(int k=a.size()-1; k>=0; k--) {
                if(s > a[k]) {
                    cpy.push_back(s);
                    s = 0;
                }
                if(k != i && k != j)
                    cpy.push_back(a[k]);
            }
            ans += (1 + dp(k-1, cpy))*a[i]*a[j];
            tot += a[i]*a[j];
        }
    }
    if(tot < k)
        ans += (k-tot)*(1 + dp(k-1, a));
    return memo[k][a] = ans / k;
}

double anso[] = {0,
                 0.00000, // 1
                 1.00000, // 2
                 2.00000, // 3
                 3.20000, // 4
                 4.54762, // 5
                 6.00733, // 6
                 7.55817, // 7
                 9.18692, // 8
                 10.88440, // 9
                 12.64373, // 10
                 14.45940, // 11
                 16.32684, // 12
                 18.24211, // 13
                 20.20179, // 14
                 22.20287, // 15
                 24.24264, // 16
                 26.31872, // 17
                 28.42893, // 18
                 30.57133, // 19
                 32.74416, // 20
                 34.94581, // 21
                 37.17482, // 22
                 39.42987, // 23
                 41.70975, // 24
                 44.01332, // 25
                 46.33958, // 26
                 48.68758, // 27
                 51.05644, // 28
                 53.44536, // 29
                 55.85359}; // 30


int main() {
    int w;
    scanf("%d", &w);
    printf("%d\n", (int) anso[w]);
    return 0;
    vector <int> vc;
    for(int n=1; n<=30; n++) {
        // scanf("%d", &n);
        vc.resize(n, 1);
        printf("%.5lf, // %d\n", dp( (n*(n-1)) / 2, vc), n );
    }
}
