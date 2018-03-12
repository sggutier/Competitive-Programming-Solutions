#include <bits/stdc++.h>
using namespace std;

void testCase(int& loanMonths, double& downPay, double& carVal, int& valDecr, int* decrMonths, double* decrPercs) {
    double monthPay = carVal/loanMonths ;
    int ans=-1, nextDecr=0;
    double mult = 1.0, owed=carVal + monthPay;
    carVal = carVal + downPay;
    while(ans++, nextDecr=(decrMonths[nextDecr]==ans? (mult=1.0-decrPercs[nextDecr], nextDecr+1) : nextDecr), carVal*=mult, owed-=monthPay, owed>=carVal);
    printf("%d month%s\n", ans, ans==1? "" : "s");
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int loanMonths, valDecr, decrMonths[200];
    double downPay, carVal, decrPercs[200];
    while(scanf("%d%lf%lf%d", &loanMonths, &downPay, &carVal, &valDecr), loanMonths>0) {
        for(int i=0; i<valDecr; i++)
            scanf("%d%lf", &decrMonths[i], &decrPercs[i]);
        decrMonths[valDecr] = loanMonths;
        testCase(loanMonths, downPay, carVal, valDecr, decrMonths, decrPercs);
    }

    return 0;
}
