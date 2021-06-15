#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> ans;
    int a, b ;
    scanf("%d%d", &a, &b);
    while(b>a) {
        ans.push_back(b);
        if(b%2==0)
            b /= 2;
        else if(b%10==1)
            b /= 10;
        else
            break;
    }
    if(a!=b) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        ans.push_back(b);
        printf("%d\n", (int) ans.size());
        for(int i=ans.size()-1; i>=0; i--)
            printf("%d ", ans[i]);
        printf("\n");
    }
}
