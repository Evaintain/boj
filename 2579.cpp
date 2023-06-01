#include <iostream>

using namespace std;

/*
2579번 문제

접근 방식
->
i > 3일때
i 번을 밟고 있다면?
i - 1번을 밟고, i - 2를 밟지 않았다. => i - 1를 밟고 올라왔다. + i - 3을 밟았다.
i - 2번을 밟고, 올라왔다.
*/

int stairs[307];
int sum[307];

int main()
{
    int n, in_stairs;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stairs[i + 1]);
    }
    sum[0] = 0;
    sum[1] = stairs[1];
    sum[2] = stairs[2] + stairs[1];

    for (int i = 3; i < n + 1; i++)
    {
        sum[i] = max(sum[i - 3] + stairs[i - 1], sum[i - 2]) + stairs[i];
    }

    printf("%d", sum[n]);
}
