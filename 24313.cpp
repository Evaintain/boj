#include <bits/stdc++.h>

using namespace std;

/*
24313번 문제

접근 방식
->
f(n) = a1 * n + a0 | 양의상수 c | g(n) = n 여기서 n >= n0에 대해 f(n) <= g(n) * c 가 만족해야함.
f(n) - c * g(n) <= 0 을 증명하면됨. n >= n0이니 n0에서의 증명을 시도하면 될거같음.
1회 오답 -> 기울기를 신경쓰지 않음. 2x -99 와 x 면 100부터는 f(x)가 커짐.
*/

int main()
{
    int a1, a0, c, n0;
    scanf("%d %d", &a1, &a0);
    scanf("%d", &c);
    scanf("%d", &n0);
    int result = (a1 - c) * n0 + a0;
    if (result <= 0 && c >= a1)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}
