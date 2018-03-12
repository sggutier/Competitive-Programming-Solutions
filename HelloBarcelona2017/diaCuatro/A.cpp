#include <bits/stdc++.h>
using namespace std;

void testCase() {
    char str[1050];
    memset(str, 0, sizeof(str));
    
    scanf("%s", str);
    int N = strlen(str);
    string ans = "";

    reverse(str, str+N);
    for(int i=0; i<N; i+=4) {
        int num = 0;
        for(int j=0; j<4; j++) {
            if(str[i+j]=='1')
                num += (1<<j);
        }
        if(num<10)
            ans += (char)(num + '0');
        else
            ans += (char)(num-10 + 'A');
    }

    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
