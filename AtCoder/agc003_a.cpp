#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int dirs[300];
bool avils[4];

bool adira(int c) {
    if(c==0)
        return true;
    if(c < 0 && avils[1])
        return true;
    if(c > 0 && avils[3])
        return true;
    return false;
}

int main() {
    bool ans = false;
    dirs['N'] = 0;
    dirs['S'] = 2;
    dirs['E'] = 1;
    dirs['W'] = 3;
    string S ;
    cin >> S ;
    int r = 0, c = 0;
    for(char s : S) {
        int d = dirs[(int) s];
        r += dr[d];
        c += dc[d];
        avils[d] = true;
    }
    if(r==0 && c==0)
        ans |= true;
    else if(r==0)
        ans |= adira(c);
    else if(r < 0 && avils[2])
        ans |= adira(c);
    else if(r > 0 && avils[0])
        ans |= adira(c);
    printf("%s\n", ans? "Yes" : "No");  
}
