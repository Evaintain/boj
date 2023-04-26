#include <bits/stdc++.h>

using namespace std;

/*
10211번 문제

접근 방식
->
i > 0에서
arr[i] = max(arr[i], arr[i] + arr[i - 1]) => 점화식
*/

/*
태그
. 다이나믹 프로그래밍
. 브루트포스 알고리즘
. 누적 합
*/
int arr[1007];

int main()
{
    int tc, n, in_arr, result;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        result = -2100000000;
        scanf("%d", &n);
        for (int i = 1; i < n + 1; i++)
        {
            scanf("%d", &in_arr);
            arr[i] = max(in_arr, in_arr + arr[i - 1]);
            if (arr[i] > result)
            {
                result = arr[i];
            }
        }
        printf("%d\n", result);
    }
}
