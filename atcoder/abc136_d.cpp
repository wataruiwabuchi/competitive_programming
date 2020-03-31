#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    string S;
    vector<int> count(1e6, 0);

    cin >> S;

    int i = 0, ir = 0, il = 0;
    while (i < S.size())
    {
        if (S[i] == 'L')
        {
            il = i;
            while (i < S.size())
            {
                if (S[i] == 'L')
                    i++;
                else
                    break;
            }

            count[il - 1] = (il - ir + 1) / 2 + (i - il) / 2;
            count[il] = (il - ir) / 2 + (i - il + 1) / 2;

            ir = i;
        }
        else
            i++;
    }

    for (int i = 0; i < S.size(); i++)
        cout << count[i] << ' ';
    cout << endl;
}