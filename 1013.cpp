#include <iostream>
#include <regex>

using namespace std;

void Solve()
{
    int t;
    string s;
    cin >> t;
    regex re("(([1][0][0]+[1]+)|([0][1]))+");
    while (t--) 
    {
        cin >> s;
        if (regex_match(s, re))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    Solve();
    return 0;
}