#include <iostream>
using namespace std;
int minum(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}
int main(){
    int n;
    int dp[3][1003];
    int rgb[3][1003];
    
    cin >> n;
    
    for (int i = 0; i < n;i++){ 
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    }
    
    dp[0][0] = rgb[0][0];
    dp[1][0] = rgb[1][0];
    dp[2][0] = rgb[2][0];
    
    for (int i = 1; i < n;i++){
        dp[0][i] = minum(dp[1][i - 1] + rgb[0][i], dp[2][i - 1] + rgb[0][i]); //0번 색으로 i번 집 색을 칠하는데 드는 최소비용
        dp[1][i] = minum(dp[0][i - 1] + rgb[1][i], dp[2][i - 1] + rgb[1][i]); //1번 색으로
        dp[2][i] = minum(dp[1][i - 1] + rgb[2][i], dp[0][i - 1] + rgb[2][i]); //2번 색으로 
    }
    
    cout << minum(minum(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]); 
    
    return 0;
}