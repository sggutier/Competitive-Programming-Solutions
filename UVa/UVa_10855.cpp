#include <bits/stdc++.h>
using namespace std ;

class Square {
protected:
    int size;
    vector <string> content;
public:
    Square() {
        size = 0;
    }
    Square(int _s) {
        size = _s;
    }
    int get_size() {
        return size;
    }
    vector <string> get_content() {
        return content;
    }
    char get_content_pos(int r, int c) {
        return content[r][c];
    }
    void print_self() {
        printf("Square:: %d\n", size);
        for(int i=0; i<size; i++)
            printf("%s\n", content[i].c_str());
    }
    void get_input() {
        content = vector<string> (size);
        for(int i=0; i<size; i++) {
            char tmp[1005];
            scanf("%s", tmp);
            content[i] = tmp;
        }
    }
    void rotate() {
        vector <string> content2 = content;
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                content[i][j] = content2[size-1-j][i];
    }
};

class BigSquare: public Square {
public:
    BigSquare() {}
    BigSquare(int size) : Square(size) {}
    bool small_square_matches(int r, int c, Square small) {
        if(r+small.get_size() > this->size || c + small.get_size() > this->size)
            return false;
        for(int i=0; i<small.get_size(); i++)
            for(int j=0; j<small.get_size(); j++)
                if(this->content[i + r][j + c] != small.get_content_pos(i,j))
                    return false;
        return true;
    }
};

int main() {
    int a, b;
    Square sm;
    BigSquare big;
    while(scanf("%d%d", &a, &b), a!=0 && b!=0) {
        big = BigSquare(a);
        big.get_input();
        sm = Square(b);
        sm.get_input();
        for(int d=0; d<4; d++) {
            int ans = 0;
            for(int i=0; i<=a-b; i++) {
                for(int j=0; j<=a-b; j++) {
                    if(big.small_square_matches(i, j, sm)) {
                        ans ++;
                    }
                }
            }
            printf("%d%c", ans, d==3? '\n' : ' ' );
            sm.rotate();
        }
    }
}
