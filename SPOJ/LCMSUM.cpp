#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 ;

int divCnt[limN + 5];
pair<int, int> dvs[limN + 5];

int main() {
    int N = limN;
    for(int i=1; i<=limN; i++) {
        dvs[i] = {divCnt[i], i};
        for(int j=i; j<=limN; j+=i)
            divCnt[j] ++;
    }
    sort(dvs, dvs+limN+1);
    reverse(dvs, dvs+limN+1);
    for(int i=0; i<10000; i++)
        printf("%d %d\n", dvs[i].second, dvs[i].first);
}
