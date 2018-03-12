#include <bits/stdc++.h>
using namespace std;

void get_input(int &n, int** &mat)  {
    scanf("%d", &n);
    mat = new int*[3]
    for (int i = 0; i < 3; i++)
        mat[i] = new int[n];
    for(int i=0; i<3; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &mat[i][j]);
}

long long tc(int n, int** mat) {
    long long** ans = new long long*[3];
    for (int i = 0; i < 3; i++)
        ans[i] = new long long[n];
    ans[0][0] = mat[0][0];
    ans[1][0] = mat[1][0] + ans[0][0];
    ans[2][0] = mat[2][0] + ans[1][0];
    for(int j=1; j<n; j++) {
        long long tmp[3] ;
        for(int i=0; i<3; i++)
            ans[i][j] = tmp[i] = ans[i][j-1] + mat[i][j];
        for(int i=0; i<3; i++) {
            long long suma = mat[i][j];            
            for(int r=i-1; r>=0; r--) {
                ans[i][j] = max(ans[i][j], suma + tmp[r]);
                suma += mat[r][j];
            }
            suma = mat[i][j];
            for(int r=i+1; r<3; r++) {
                ans[i][j] = max(ans[i][j], suma + tmp[r]);
                suma += mat[r][j];
            }
            if(i != 1) {
                ans[i][j] = max(ans[i][j], (j == 1? 0: max(ans[0][j-2], ans[2][j-2]))
                                + mat[0][j-1] + mat[1][j-1] + mat[2][j-1]
                                + mat[0][j] + mat[1][j] + mat[2][j]);
            }
        }
    }
    long long tmp = ans[2][n-1];
    for (int i = 0; i < 3; ++i)
        delete [] ans[i];
    delete [] ans;
    return tmp;
}


int main() {
    int n;
    int **mat = NULL;
    get_input(n, mat);
    cout << tc(n, mat) << endl;
    for (int i = 0; i < 3; ++i)
        delete [] mat[i];
    delete [] mat;
    return 0;
}
