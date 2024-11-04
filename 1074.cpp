#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int cnt = 0;

void dc(int x, int y, int size){
    if(c==x && r==y){ // 조건으로 들어온 열과 행이 일치하는 경우
        cout << cnt;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y){
        // 4분면안에 있는 경우 
        dc(x, y, size / 2);
        dc(x + size / 2, y, size / 2);
        dc(x, y + size / 2, size / 2);
        dc(x + size / 2, y + size / 2, size / 2);
    }else{ // 없는 경우 정사각형 넓이
        cnt += size * size;
    }
}
int main(){
    cin >> N >> r >> c;
    dc(0, 0, pow(2, N)); // 2N-1 x 2N-1 행렬
    return 0;
}