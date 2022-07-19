//使用bfs遍历整张图获取从第一个节点到其他节点的路径权值异或和
//然后通过异或的性质得到任意两个节点之间的路径权值异或和

#include <iostream>
#include <queue>

#define MAX_EDGE_NUM (int)1e6
#define MAX_NODE_NUM ((int)1e5 + 10)
using namespace std;
int n, m, q;
int cnt = 0;
struct Edge
{
    int to, next, w;
} edge[MAX_EDGE_NUM];
int head[MAX_NODE_NUM];
void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
}
int dis[MAX_NODE_NUM];
bool vis[MAX_NODE_NUM];
inline void bsf()
{
    queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int head1 = que.front();
        que.pop();
        if (vis[head1])
            continue;
        vis[head1] = true;
        for (int i = head[head1]; i != -1; i = edge[i].next)
        {
            if (!vis[edge[i].to])
            {
                dis[edge[i].to] = dis[head1] ^ edge[i].w;
                que.push(edge[i].to);
            }
        }
    }
}
int main()
{
    for (int &i : head)
    {
        i = -1;
    }
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    bsf();
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (dis[u] ^ dis[v]) << endl;
    }
}