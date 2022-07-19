#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int v, n;
    int obj[40];
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> obj[i];
    }
    sort(obj + 1, obj + n + 1);
    int min = (int)1e9;
    for (int j = n; j >= 0; j--)
    {
        int temp = v;
        for (int i = j; i >= 0; i--)
        {
            if (temp >= obj[i])
            {
                temp -= obj[i];
            }
        }
        if (temp < min)
        {
            min = temp;
        }
    }

    cout << min << endl;
}