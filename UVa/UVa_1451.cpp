// - An array s can be computed by adding all the elements from 0 to i and putting that sum
//   in i
// - Then the problem can be reduced to finding the maximum (s[b] - s[a]) / (b -a) where 0 <= a < b
//   and b-a >= L.  In other words, the bigger slope such that the separation is at least L is looked for.
// - Let x_p, x_q, and x_r be integers such that 0 < x_p < x_q < x_r <= n.
//   Let P = (x_p, s[x_p]), Q = (x_q, s[x_q]), and R = (x_r, s[x_r]).  If R is below PQ, then
//   the slope of PR is bigger than the one of QR.  If R is in PQ, then the slope is the same.
//   Otherwise, if R is above PQ, then the slope of QR is bigger than the one of PR.
//   - Also, any slope with an R above PQ with Q will be bigger than any from any R' below PQ
//     with P.
// - Let a be an array.  The positions from L onwards are processed.  For each i, let T = (i-L, s[i-L]).
//   Then repeat the following until a has less than two elements:
//   - Let P be the penultimate point of the array and Q the last one.  If Q lies below PT,
//     stop there.
//   - Otherwise, it does not make sense to keep Q, since s is non decreasing and all the points
//     above QT from i onwards will also be above PT, which means they will make a bigger slope
//     with T anyways.  If they are below QT, they are also below PT, which means they make
//     its biggest slope with P.  In both cases, Q becomes useless and can be ditched away,
//     then the process repeated.
// - This process is exactly the same one does when doing the convex hull trick for DP, so
//   for sure the points form a convex hull.
// - After adding T, start considering the leftmost points in the array.  Let C = (i, s[i]).
//   Then start repeating until the array has less than two elements:
//   - Let A and B be the first and second points from the array.  If C lies below AB, it will
//     also lie below any other line in the convex hull; because of the arguments in the third bullet point
//     here, it will make its biggest slope with A so it is better to stop there.
//   - Otherwise, a VALID slope can now be considered for the answer, and since it lies above
//     the line AB, any point laying below it will have a smaller slope than the slope BC.  For
//     the ones above it, the slope to consider will be the one with B.  In both cases, A has
//     become useless and can be erased from the array. Keep repeating.
// - After finishing the process above, consider the first element from the array.  It will be
//   the best to consider for C, except maybe for another one which has already been eliminated
//   for the reasons in the last point (laying below AB), but which anyways will not produce
//   a better answer than one for a smaller i. 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 1e5 + 5;

struct Frac {
    int num, den;
    Frac() {}
    Frac(int num, int den) {
        if(den < 0)
            num *= -1;
        int d = __gcd(abs(num), den);
        this->num = num/d;
        this->den = den/d;
    }
};

bool operator<(Frac A, Frac B) {
    return ((long long) A.num)*B.den < ((long long) B.num)*A.den;
}

bool operator<=(Frac A, Frac B) {
    return ((long long) A.num)*B.den <= ((long long) B.num)*A.den;
}

int N, L ;
int sum[limN];
char str[limN];

Frac pend(const int l, const int r) {
    return {sum[r] - sum[l], r-l};
}

void testCase() {
    scanf("%d%d", &N, &L);
    scanf("%s", str+1);
    sum[0] = 0;
    for(int i=1; i<=N; i++)
        sum[i] = sum[i-1] + str[i]-'0';
    
    pair<Frac, pii> ans = {{sum[N], N}, {-N, 0}};
    deque <int> Q;
    // printf("Anso inicialmente: %d %d\n", ans.f.num, ans.f.den);
    for(int i=L, w=0; i<=N; i++) {
        int t = i-L;
        while(w >= 2 && pend(Q[w-1], t) <= pend(Q[w-2], Q[w-1]))
            w--, Q.pop_back();
        Q.push_back(t);
        w++;
        while(w >= 2 && pend(Q[0], i) <= pend(Q[1], i))
            w--, Q.pop_front();
        // printf("t = %d, %d %d\n", t, Q.front(), Q.back());
        // printf("[%d %d] => ", i, sum[i]);
        // for(int i=0; i<w; i++)
        //     printf("[%d %d] ", Q[i], sum[Q[i]]);
        // printf("\n");
        // printf("Pend a considerar: %d %d\n", pend(Q[0], i).num, pend(Q[0], i).den);
        ans = max(ans, {pend(Q[0], i), {Q[0]-i, -Q[0]}});                    
    }
    
    printf("%d %d\n", -ans.s.s + 1, -ans.s.s-ans.s.f);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
