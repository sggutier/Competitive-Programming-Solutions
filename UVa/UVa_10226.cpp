#include <bits/stdc++.h>
using namespace std;

void test_case() ;
int get_input(map<string, int> *cnt) ;

int main() {
    int tc ;

    scanf("%d\n\n", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        test_case();
    }
    
    return 0;
}

int get_input(map<string, int> *cnt) {
    int ans = 0;
    string str;
    char tmp;
    while( true ) {
        if( scanf("%c", &tmp)==EOF || (str=="" && tmp=='\n') ) {
            if(str!="") {
                (*cnt)[str]++;
                ans ++;
            }
            break;
        }
        else if(tmp=='\n') {
            (*cnt)[str]++;
            ans ++;
            str = "";            
        }
        else {
            str += tmp;
        }
    }
    return ans;
}

void test_case() {
    map<string, int> cnt;
    double tots = get_input(&cnt);
    for(map<string, int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
        printf("%s %.4lf\n", (it->first).c_str(), (it->second / tots)*100);
    }
}
