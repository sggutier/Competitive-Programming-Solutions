/*
ID: me60
LANG: C++11
TASK: dualpal
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(char* s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}

void itoa(int n, char s[], int base)
{
    int i, sign;
 
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % base + (n % base>=10? 'A' - 10 : '0');
    } while ((n /= base) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, s+i);
}


int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int num, cnt;
    scanf("%d%d", &cnt, &num);
    
    for(num++; cnt; num++) {
        char numS[50];
        int palCnt = 0;
        for(int j=2; j<=10; j++) {
            itoa(num, numS, j);
            if(isPalindrome(numS))
                palCnt ++;
        }
        if(palCnt>=2) {
            cnt --;
            printf("%d\n", num);
        }
    }
    
    return 0;
}
