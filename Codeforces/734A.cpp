#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> cnt(300, 0);
    int N ;
    string S ;
    cin >> N >> S;
    for(char c:S) {
        cnt[(int) c]++;
    }
    if(cnt['A'] > cnt['D'])
        cout << "Anton" << endl;
    else if(cnt['A'] < cnt['D'])
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}
