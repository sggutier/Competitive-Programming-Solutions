#include <bits/stdc++.h>
using namespace std;

long double getWinProbability(long double ra, long double rb) {
    return 1.0 / (1.0 + pow((long double) 10.0, (rb - ra) / 400.0));
}

long double aggregateRatings(vector<long double> teamRatings)
{
    long double left = 1;
    long double right = 1E4;

    for (int tt = 0; tt < 100; tt++) {
        long double r = (left + right) / 2.0;

        long double rWinsProbability = 1.0;
        for(int i=0; i < (int) teamRatings.size(); i++)
            rWinsProbability *= getWinProbability(r, teamRatings[i]);

        long double rating = log10(1 / (rWinsProbability) - 1) * 400 + r;

        if (rating > r)
            left = r;
        else
            right = r;
    }

    return (left + right) / 2.0;
}

int main() {
	cout << aggregateRatings({2201}) << endl;;
	cout << aggregateRatings({2485}) << endl;;
	cout << aggregateRatings({2125, 2143, 2338}) << endl;;
	cout << aggregateRatings({1459,	2042, 1821}) << endl;;
	cout << aggregateRatings({1765,	1514, 1910}) << endl;;
	cout << aggregateRatings({2123,	1266, 1630}) << endl;;
}
