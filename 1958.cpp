#include <iostream>
#include <cstring>

using namespace std;

/*
1958번 문제

접근 방식
->
3차원 LCS 구현.
*/

/*
태그
. 문자열
. 다이나믹 프로그래밍
*/

int lcs[107][107][107];

int main()
{
    char in_a[107], in_b[107], in_c[107];
    scanf("%s\n%s\n%s", in_a, in_b, in_c);
    int a_len, b_len, c_len;
    a_len = strlen(in_a);
    b_len = strlen(in_b);
    c_len = strlen(in_c);

    for (int i = 0; i < a_len; i++)
    {
        for (int j = 0; j < b_len; j++)
        {
            for (int k = 0; k < c_len; k++)
            {
                if (in_a[i] == in_b[j] && in_b[j] == in_c[k]) lcs[i + 1][j + 1][k + 1] = lcs[i][j][k] + 1;
                else
                {
                    lcs[i + 1][j + 1][k + 1] = max(lcs[i + 1][j + 1][k], lcs[i + 1][j][k + 1]);
                    lcs[i + 1][j + 1][k + 1] = max(lcs[i + 1][j + 1][k + 1], lcs[i][j + 1][k + 1]);
                }
            }
        }
    }

    printf("%d", lcs[a_len][b_len][c_len]);
}
