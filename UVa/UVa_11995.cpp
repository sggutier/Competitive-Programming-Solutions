#include <bits/stdc++.h>
using namespace std;

void testCase(int queryCnt) {
    bool isStack = true, isQueue = true, isPQ = true;
    stack<int> S;
    queue<int> Q;
    priority_queue <int> P;

    while(queryCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a==1) {
            if(isStack) S.push(b);
            if(isQueue) Q.push(b);
            if(isPQ) P.push(b);
        }
        else {
            if(isStack) { isStack &= (!S.empty() && S.top()==b); S.pop(); }
            if(isQueue) { isQueue &= (!Q.empty() && Q.front()==b); Q.pop(); }
            if(isPQ) { isPQ &= (!P.empty() && P.top()==b); P.pop(); }
        }
    }
    int ans = ((isStack<<2) + (isQueue<<1) + isPQ);
    switch(ans) {
    case 0:
        printf("impossible\n");
        break;
    case 1:
        printf("priority queue\n");
        break;
    case 2:
        printf("queue\n");
        break;
    case 4:
        printf("stack\n");
        break;
    default:        
        printf("not sure\n");
        break;
    }
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF) {
        testCase(n);
    }
    
    return 0;
}
