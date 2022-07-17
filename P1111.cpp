//给出一张图，求出最小生成树权值之和
//如果图中的节点不能生成一个最小生成树，那么就输出-1

//可以使用prim算法
//如果dis数组里有INF，那么存在到达不了的村庄，输出-1
//思路有问题
//选取根节点生成最小生成树并不能从权值最小的边开始选取

//应该从权值最小的边开始选取，一直选取n-1条边，然后选取最大的那一条边的权值大小作为结果，如果最后的边的数量不够n-1那么输出-1

#include <iostream>
#include <algorithm>
#define EDGE_MAX_NUM ((unsigned long long)1e6 + 10)
#define NODE_MAX_NUM ((unsigned long long)1e3 + 10)
#define INF INT32_MAX
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge e) const
    {
        return w < e.w;
    }
} edge[EDGE_MAX_NUM << 1]; //无向图有两倍的边

int cnt = 1;
int head[NODE_MAX_NUM];
int edgeNum = 0; //记录当前合格的边的数量
int father[NODE_MAX_NUM];
int depth[NODE_MAX_NUM]; //初始深度是0

void add(int u, int v, int w)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    cnt++;
}

int find(int n)
{
    return n == father[n] ? n : father[n] = find(father[n]);
}

bool merge(int n, int m)
{
    int root1 = find(n), root2 = find(m);
    if (root1 != root2)
    {
        if (depth[root1] < depth[root2])
        {
            father[root1] = root2;
            if (depth[root1] == depth[root2])
                depth[root2]++;
        }
        else
        {
            father[root2] = root1;
            if (depth[root1] == depth[root2])
                depth[root1]++;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    for (int &i : head)
    {
        i = -1;
    }

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    //对边集的权值排序
    sort(edge, edge + (m << 1));

    //找出所有合格的边，直到找到n-1条
    for (int i = 1; i <= m << 1; i++)
    {
        if (merge(edge[i].u, edge[i].v))
        {
            edgeNum++;
        }
        if (edgeNum == n - 1)
        {
            cout << edge[i].w << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}