#include <bits/stdc++.h>

using namespace std;

/*
9063번 문제

접근 방식
->
min_x, max_x, min_y, max_y의 곱(max-min) x y의 곱.이 답임.
만약 n이 1이라면 0이 답임.
n이 2이더라도 x나 y가 같으면 0이 답일것.
*/
int main()
{
    int n, x, y, max_x, min_x, max_y, min_y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        if (i == 0)
        {
            min_x = max_x = x;
            min_y = max_y = y;
            continue;
        }
        if (x < min_x)
        {
            min_x = x;
        }
        if (x > max_x)
        {
            max_x = x;
        }
        if (y < min_y)
        {
            min_y = y;
        }
        if (y > max_y)
        {
            max_y = y;
        }
    }
    printf("%d", (max_x - min_x) * (max_y - min_y));
}
