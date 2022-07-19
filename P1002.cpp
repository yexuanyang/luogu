#include <iostream>
#define ull unsigned long long
using namespace std;

int locx[] = {0, 2, 2, -2, -2, 1, 1, -1, -1};
int locy[] = {0, 1, -1, 1, -1, 2, -2, 2, -2};
ull PathNum[40][40];
bool isAttack[40][40];
int main()
{
    int bx, by, hx, hy;
    cin >> bx >> by >> hx >> hy;
    bx += 2;
    by += 2;
    hx += 2;
    hy += 2;
    for (int i = 0; i < 9; i++)
    {
        isAttack[hx + locx[i]][hy + locy[i]] = true;
    }
    PathNum[1][2] = 1;
    for (int i = 2; i <= bx; i++)
    {
        for (int j = 2; j <= by; j++)
        {
            if (!isAttack[i][j])
            {
                PathNum[i][j] = PathNum[i - 1][j] + PathNum[i][j - 1];
            }
        }
    }
    cout << PathNum[bx][by] << endl;
    return 0;
}
