#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;

// 전역 변수 선언
int A, B;
int DP[MAX], UP[MAX];
int Answer = 0;

// 소수 및 소인수 개수 초기화
void init() {
    // DP와 UP 배열 초기화
    for (int i = 2; i < MAX; i++) {
        DP[i] = i; // 소수라 가정
        UP[i] = 1; // 최소 소인수 개수
    }

    // 에라토스테네스의 체로 소수와 소인수 개수 계산
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (DP[i] == 0) continue; // i가 소수가 아니면 건너뜀

        // i의 배수 처리
        for (int j = i * i; j < MAX; j += i) {
            DP[j] = 0;                    // j는 소수가 아님
            UP[j] = UP[j / i] + 1;        // 소인수 개수 계산
        }
    }
}

// 입력 처리
void input() {
    cin >> A >> B;
}

// 결과 계산
void calculate() {
    for (int i = A; i <= B; i++) {
        // 소인수 개수가 소수라면 카운트 증가
        if (DP[UP[i]] != 0) {
            Answer++;
        }
    }
}

// 결과 출력
void output() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    init();       // 소수 및 소인수 초기화
    input();      // 입력 처리
    calculate();  // 결과 계산
    output();     // 결과 출력

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int MAX = 10001;

// int primeNumberSieve(vector<int>& isPrime, vector<int>& primeFactorCount) {

//     // vector 초기화
//     isPrime.assign(MAX+1, 1); // 모두 소수라고 가정 (1이면 소수, 아니면 소수 아님) 
//     primeFactorCount.assign(MAX+1, 0);

//     // 0과 1은 소수에서 제외
//     isPrime[0] = isPrime[1] = 0;

//     // 소수 판단
//     for (int i=2; i<=MAX; i++) {
//         if (isPrime[i]) { // i가 소수라면
//             // i의 배수에 대해 소인수 개수 증가
//             for (int j=i; j<=MAX; j+=i) {
//                 primeFactorCount[j]++;
//                 if (j != i) isPrime[j] = 0; // i 자체는 소수로 유지 -> j와 i가 동일하지 않으면 1로 바뀜
//             }
//         }
//     }

// }

// int main() {
//     int A, B;
//     int cnt=0;

//     cin >> A >> B;

//     vector<int> isPrime, primeFactorCount;
//     primeNumberSieve(isPrime, primeFactorCount); // 1. 소수 판별 2. 소인수 개수 저장 

//     for (int i=A; i<=B; i++) {
//         if(isPrime[primeFactorCount[i]])
//             cnt++;
//     }

//     cout << cnt << endl;

//     return 0;
// }