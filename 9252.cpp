#include <bits/stdc++.h>

using namespace std;

/*
9252번 문제

접근방식
->
LCS를 뒤로 돌아가며 부분 문자열을 만들어 출력한다.
*/

vector<char> v;
int lcs[1007][1007];
char input_o[1007], input_t[1007];
int dx[] = {-1, 0};
int dy[] = {0, -1};

void travel(int o_len, int t_len)
{
    bool flag = true;
    if (o_len == 0 || t_len == 0)
    {
        return;
    }
    int x = o_len;
    int y = t_len;
    int nx, ny;

    for (int i = 0; i < 2; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (lcs[x][y] == lcs[nx][ny])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        v.push_back(input_o[x - 1]);
        travel(x - 1, y - 1);
    }
    else
    {
        travel(nx, ny);
    }
}

int main()
{
    scanf("%s\n%s", input_o, input_t);
    int o_len = strlen(input_o), t_len = strlen(input_t);

    for (int i = 0; i < o_len; i++)
    {
        for (int j = 0; j < t_len; j++)
        {
            if (input_o[i] == input_t[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else lcs[i + 1][j + 1] = max({lcs[i + 1][j], lcs[i][j + 1]});
        }
    }
    printf("%d\n", lcs[o_len][t_len]);
    if (lcs[o_len][t_len] == 0)
    {
        return 0;
    }
    travel(o_len, t_len);

    for (int i = v.size() - 1; i > -1; i--)
    {
        printf("%c", v[i]);
    }
}
