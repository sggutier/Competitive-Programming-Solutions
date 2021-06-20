// - The sums can be flipped like sum_{j=2}^n sum_{i=1}^{j-1} gcd(i, j)
// - For every j, the possible gcds are only its divisors, each one repeating certain amount
//   of times.
// - By the way the sums were flipped, it is more or less clear that for each j the sum can
//   be calculated and then added cumulatively in some array.
// - The amount of times every divisor d appears as a gcd is floor(j / d) minus some possible
//   double counting that can appear as another divisor.  (For instance, 3 divides the both
//   the divisors of 24 6 and 12)
// - The above part can be calculated with two fors for the divisors of each j and another for
//   for cycling through the js.
// - Each number between 1 and 2e5 has not many divisors, at most 30 each I think, even less on
//   average.  In any case, I calculated the sum of the squares of the amount of divisors for
//   each number and it was quite less than 10^8, so this should run in time. I'm not sure about
//   how to express the complexity.
  
#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 1;

vector <int> divs[limN];
long long anso[limN];
int cnts[limN];

void precarga() {
    for(int i=1; i<limN; i++)
        for(int j=2*i; j<limN; j+=i)
            divs[j].push_back(i);
    for(int i=1, n; i<limN; i++) {
        n = divs[i].size();
        for(int j=n-1; j>=0; j--) {
            cnts[j] = i / divs[i][j] - 1;
            for(int k=j+1; k<n; k++)
                if(divs[i][k] % divs[i][j] == 0)
                    cnts[j] -= cnts[k];
            anso[i] += cnts[j]*divs[i][j];
        }
        anso[i] += anso[i-1];
    }
}

int main() {
    precarga();
    int n ;
    while(scanf("%d", &n)!=EOF && n)
        printf("%lld\n", anso[n]);
}
