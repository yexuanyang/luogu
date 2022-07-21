// 01背包问题
//状态矩阵f存储背包容量的信息
//动态转移关系如下
// f[i][j] = max(f[i-1][j] , f[i-1][j-w[i]] + v[i]);
//含义：f[i-1][j]表示第i件物品不放到背包里面，那么背包容量还是j不变
// f[i-1][j-w[i]]+v[i]表示第i件物品放到背包里面，那么背包容量要减少w[i]，然后价值要增加v[i]
//取两者中的最大值，因为可能物品的价值是负数，物品放进去反而减少了总价值

// f[i][j]的含义就是当前有i件物品被检查过，背包剩余容量是j的情况下的最大价值
//使用vector容器存储每个物品的重量和价值
//矩阵f的大小需要开大一些避免遍历的时候越界
//如果有n个物体，那么需要开n+1行
//如果容量是V，那么需要开V+1列
//矩阵f的初始状态都是0

//对于装箱问题，物品的价值和物品的体积从数值上看是一样的
//这样得到的最大价值就是装进去的物品的最大容积
//最终得到的最大价值并不是我们要的结果
//箱子的容量减去最大价值才是我们要的结果

//这种解法的空间复杂度太高了
//可以优化状态矩阵，降低空间复杂度
//代码中的状态矩阵在动态规划的过程中，只用到了第i-1行的数据
//所以可以把状态矩阵改成一维的

#include <iostream>
#include <vector>
#include <algorithm>
#define max(N, D) N > D ? N : D
using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    vector<int> weight;
    vector<int> value;
    weight.clear();
    value.clear();
    weight.push_back(0);
    value.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int n;
        cin >> n;
        weight.push_back(n);
        value.push_back(n);
    }

    //优化之前
    /*vector<vector<int>> f;
    f.clear();
    for (int i = 0; i < n + 1; i++)
    {
        vector<int> buff(v + 1, 0);
        f.push_back(buff);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            if (j >= weight[i])
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    int answer = v - f[n][v];*/

    //优化之后
    vector<int> f(v + 1, 0);
    for (int i = 1; i <= n; i++) //对应之前的遍历每一个物品
    {
        for (int j = v; j >= weight[i]; j--) //当背包余量比当前的物品的体积还小，那么就没有必要再循环下去了，直接去检查下一件物品
        {
            f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
    }
    int answer = v - f[v];
    cout << answer << endl;
    return 0;
}