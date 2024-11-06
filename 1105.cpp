#include <iostream>
#include <string>

using namespace std;
string L, R;
int result = 0;
int num = 0;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> R;

    if(R.size() > L.size()){
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 0; i < R.size(); i++){
        if(R[i] == L[i] and R[i] == '8'){
            result++;
            continue;
        }

        if(R[i] != L[i]){
            break;
        }
    }

    cout << result;
    cout << 0;
    return 0;
}