#include <iostream>
#define MAX_NODE_NUM 1010
#define MAX_EDGE_NUM 100010
#define INF (int)1e9

using namespace std;

int n, m;
int matrix[MAX_NODE_NUM][MAX_NODE_NUM];

inline void floyd()
{
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            for (int w = 1; w <= n; w++)
            {
                if (matrix[v][u] + matrix[u][w] < matrix[v][w])
                {
                    matrix[v][w] = matrix[v][u] + matrix[u][w];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                matrix[i][j] = INF;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        if (matrix[from][to] > weight)
            matrix[from][to] = weight;
    }

    //弗洛伊德算法
    floyd();
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += matrix[1][i] + matrix[i][1];
    }
    cout << ans;
    return 0;
}
