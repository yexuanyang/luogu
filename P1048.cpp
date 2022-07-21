//这题采药时间就是背包的容积，药品的采取时间就是weight，价值就是value，问题转换成背包问题
#include <iostream>
#include <vector>
#define max(n, m) n > m ? n : m
using namespace std;
int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> weight{0};
    vector<int> value{0};
    for (int i = 1; i <= m; i++)
    {
        int time, va;
        cin >> time >> va;
        weight.push_back(time);
        value.push_back(va);
    }
    vector<int> f(t + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= weight[i]; j--)
        {
            f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
    }
    cout << f[t];
    return 0;
}