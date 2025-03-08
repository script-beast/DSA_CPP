#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += s[i] - '0';
    if (sum % 3 == 0)
        cout << 0 << endl;
    else
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if ((sum - s[i] + '0') % 3 == 0)
            {
                cout << 1 << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((sum - s[i] + '0' - s[j] + '0') % 3 == 0)
                    {
                        cout << 2 << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }

    return 0;
}