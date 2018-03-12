#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int rows, cols;
    char tmp[50];
    cin.getline(tmp+1, 50);
    cols = strlen(tmp+1);
    vector <int> sums[50];
    rows = 1;
    sums[0].resize(cols+1);
    sums[1].resize(cols+1);
    for(int j=1; j<=cols; j++) {
        sums[1][j] = tmp[j]-'0';
    }
    while(cin.getline(tmp+1, 50) && tmp[1]) {
        rows ++;
        sums[rows].resize(cols+1);
        for(int j=1; j<=cols; j++) {
            sums[rows][j] = sums[rows-1][j] + tmp[j] - '0';
        }
    }

    int ans = 0;
    for(int i=0; i<=rows; i++) {
        for(int j=i+1; j<=rows; j++) {
            for(int k=1, cnt=0; k<=cols; k++) {
                if(sums[j][k] - sums[i][k]==j-i) {
                    cnt ++;
                    ans = max(ans, cnt*(j-i));
                }
                else
                    cnt = 0;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    char tmp[50];
    cin.getline(tmp, 50);
    int tc;
    sscanf(tmp, "%d", &tc);
    cin.getline(tmp, 50);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
