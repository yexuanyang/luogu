//用二维数组模拟棋盘
//添加棋子之后把棋盘中可以被攻击的区域标记
//添加完所有的棋子之后计算未被攻击的区域
//此方法内存会超出限制

//另外一个方法是遍历每一行
//然后把每一行中未被攻击到的格子计算出来然后加到最后的结果里
//需要开一个flag数组去标记当前行中那些格子已经被攻击了

#include <iostream>
#define MAXSIZE (int)2e4 + 10
#define MAXNUM 510

using namespace std;
int n, m, k;

/*第一个方法
// n行m列k个棋子
bool pannel[MAXSIZE][MAXSIZE];

//添加棋子的操作
void add(int row, int col)
{
    //行标记
    for (int i = 0; i < m; i++)
    {
        pannel[row][i] = true;
    }
    //列标记
    for (int i = 0; i < n; i++)
    {
        pannel[i][col] = true;
    }
    //左对角线
    int tempRow = row, tempCol = col;
    while (tempRow >= 0 && tempCol >= 0)
    {
        pannel[tempRow][tempCol] = true;
        tempRow--;
        tempCol--;
    }
    tempRow = row;
    tempCol = col;
    while (tempRow <= n && tempCol <= m)
    {
        pannel[tempRow][tempCol] = true;
        tempRow++;
        tempCol++;
    }
    //右对角线
    tempRow = row;
    tempCol = col;
    while (tempRow >= 0 && tempCol <= m)
    {
        pannel[tempRow][tempCol] = true;
        tempRow--;
        tempCol++;
    }
    tempRow = row;
    tempCol = col;
    while (tempRow <= n && tempCol >= 0)
    {
        pannel[tempRow][tempCol] = true;
        tempRow++;
        tempCol--;
    }
}

int findNum()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!pannel[i][j])
                ans++;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int row, col;
        cin >> row >> col;
        add(row - 1, col - 1);
    }
    int result = findNum();
    cout << result << endl;
    return 0;
}
#pragma endregion
*/

//第二个方法
int row[MAXNUM], col[MAXNUM]; //记录五百个棋子的行下标和列下标
int flag[MAXSIZE]{0};         //记录行中格子的状态
//记录某行有没有棋子
bool havePawn[MAXSIZE];

int main()
{
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    { //存储k个棋子的位置
        cin >> row[i] >> col[i];
        havePawn[row[i]] = true;
    }
    //开始遍历每一行
    for (int i = 1; i <= n; i++)
    {
        //初始化每一行没有被攻击的格子数量
        int sum = m;

        //当前行没有棋子才需要遍历所有棋子去找当前行剩余的没有被攻击的棋子的数量
        if (!havePawn[i])
        {
            //遍历所有皇后
            for (int j = 1; j <= k; j++)
            {
                if (flag[col[j]] != i)
                {
                    sum--; //当前行棋子当前列占的格子没有被攻击过，则记录下来
                    flag[col[j]] = i;
                }
                //寻找棋子的对角线影响到的格子
                //如果棋子在当前行的上方(行数比当前行小)
                if (row[j] < i)
                {
                    //右下对角线
                    if (col[j] + (i - row[j]) >= 1 && col[j] + (i - row[j]) <= m)
                    { //对角线中的格子在范围内
                        if (flag[col[j] + (i - row[j])] != i)
                        {
                            sum--;
                            flag[col[j] + (i - row[j])] = i;
                        }
                    }
                    //左下对角线
                    if (col[j] - (i - row[j]) >= 1 && col[j] - (i - row[j]) <= m)
                    {
                        if (flag[col[j] - (i - row[j])] != i)
                        {
                            sum--;
                            flag[col[j] - (i - row[j])] = i;
                        }
                    }
                }
                else
                { //棋子在当前行的下方
                    //右上对角线
                    if (col[j] + (-i + row[j]) >= 1 && col[j] + (-i + row[j]) <= m)
                    { //对角线中的格子在范围内
                        if (flag[col[j] + (-i + row[j])] != i)
                        {
                            sum--;
                            flag[col[j] + (-i + row[j])] = i;
                        }
                    }
                    //左上对角线
                    if (col[j] - (-i + row[j]) >= 1 && col[j] - (-i + row[j]) <= m)
                    {
                        if (flag[col[j] - (-i + row[j])] != i)
                        {
                            sum--;
                            flag[col[j] - (-i + row[j])] = i;
                        }
                    }
                }
            }
            //遍历完所有棋子
            //结果加上这一行未被攻击的数量
            ans += sum;
        }
    }
    cout << ans << endl;
}
