#include <bits/stdc++.h>

using namespace std;

/*
9663 문제

접근 방식
->
백트래킹 문제임.
피스를 배치할때, 검사하는 함수와, 배치한 함수를 따져야 할거임.
2차원 배열이 아닌 1차원 배열을 잡고 배열의 인덱스, 값을 좌표로 사용함.
검사 방식
1. 현재순서 - 인덱스 == |값 - 배열[인덱스]| 일경우 대각선이므로 배제함.
2. 배열[인덱스] == 값 이면 같은 행에 존재하는 것이미 배제함.
*/

int chess[17];
int ans = 0;

bool check(int now, int col) //now 현재 값, col 놓을 좌표
{
    for (int i = 0; i < col; i++)
    {
        if (col - i == abs(chess[i] - now) || chess[i] == now)
        {
            return false;
        }
    }
    return true;
}

void n_queen(int goal, int col)
{
    if (col == goal)
    {
        ans++;
        return;
    }

    for (int i = 0; i < goal; i++)
    {
        if (check(i, col))
        {
            chess[col] = i;
            n_queen(goal, col + 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    n_queen(n, 0);
    printf("%d", ans);
}
