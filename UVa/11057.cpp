#include <bits/stdc++.h>
using namespace std;

void testCase(int bookCnt) {
    int books[bookCnt];
    int sum ;
    pair <int,int> ans;
    for(int i=0; i<bookCnt; i++) {
        scanf("%d", &books[i]);
    }
    scanf("%d", &sum);
    ans = make_pair(sum, 0);
    for(int i=0; i<bookCnt; i++) {
        for(int j=i+1; j<bookCnt; j++) {
            if(books[i] + books[j]==sum) {
                ans = min(ans, make_pair(abs(books[i] - books[j]), min(books[i], books[j])));
            }
        }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", ans.second, ans.second + ans.first);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
}
