/*
ID: me60
LANG: C++11
TASK: palsquare
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
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int base ;
    char num[50], square[50];

    scanf("%d", &base);
    
    for(int i=1; i<=300; i++) {
        itoa(i, num, base);
        itoa(i*i, square, base);
        if(isPalindrome(square))
            printf("%s %s\n", num, square);
    }
    
    return 0;
}
