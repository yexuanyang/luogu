#include <iostream>
#include <algorithm>
#define MAXNUM 1000
using namespace std;
struct Medicine
{
    int time, value;
    double tDivV;
    bool operator<(const Medicine &m)
    {
        return tDivV > m.tDivV;
    }
} medicine[MAXNUM];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++)
    {
        int time, v;
        cin >> time >> v;
        medicine[i].time = time;
        medicine[i].value = v;
        medicine[i].tDivV = v * 1.0 / time;
    }
    sort(medicine, medicine + m);
    /*for (int i = 0; i < m; i++)
    {
        cout << medicine[i].tDivV << endl;
    }*/
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        int temp = t;
        int ans = 0;
        if (medicine[i].time <= temp)
        {
            temp -= medicine[i].time;
            ans += medicine[i].value;
            for (int j = 1; j <= m - i; j++)
            {
                for (int k = i + j; k < m; k++)
                {
                    if (medicine[k].time <= temp)
                    {
                        temp -= medicine[k].time;
                        ans += medicine[k].value;
                    }
                }
            }
        }
        if (ans > max)
        {
            max = ans;
        }
    }
    cout << max << endl;
}