#include <iostream>
using namespace std;

int N;
int operand[11]; 
int operat[4]; 
int minnum = 1000000001;
int maxnum = -1000000001;
void getanswer(int result, int idx)
{
    if(idx == N)
    {
        if(result > maxnum)
            maxnum = result;
        if(result < minnum)
            minnum = result;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(operat[i] > 0)
        {
            operat[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            if(i == 0)
                getanswer(result + operand[idx], idx+1);
            else if(i == 1)
                getanswer(result - operand[idx], idx+1);
            else if(i == 2)
                getanswer(result * operand[idx], idx+1);
            else
                getanswer(result / operand[idx], idx+1);
            operat[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
    return;
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> operand[i];
    for(int i = 0; i < 4; i++)
        cin >> operat[i];

    getanswer(operand[0],1);

    cout << maxnum << '\n';
    cout << minnum;
}