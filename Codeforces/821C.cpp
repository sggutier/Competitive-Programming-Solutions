#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    stack <int> st;
    int u=1;
    int ans = 0;
    char tmp[20];

    scanf("%d", &n); n *= 2;
    while(n--) {
        scanf("%s", tmp);
        if(tmp[0]=='a') {
            int w ;
            scanf("%d", &w);
            st.push(w);
            //printf("Puchando %d\n", w);
        }
        else {
            int a = st.top(); st.pop();
            //printf("Quitando %d cds  %d\n", a, u);
            if(a != u) {
                if(a > 0)
                    ans ++;
                if(!st.empty()) {
                    a = st.top(); st.pop();
                    //printf("Poniendo  %d de comodin\n", -abs(a));
                    st.push(-abs(a));
                }
            }
            u++;
        }
    }

    printf("%d\n", ans);
}
