#include <bits/stdc++.h>

using namespace std;

/*
2670번 문제

접근 방식
->
실수형 배열을 잡고 그 배열의 0번칸에는 0을 넣는다
배열의 1번칸 부터 n번칸 까지는 n과 n, n * 배열의 n - 1번칸의 값 중 큰것을 넣는다.
*/

/*
점화식 (조건 = i > 0)
arr[i] = max(arr[i], arr[i] * arr[i - 1])
*/

/*
태그
. 다이나믹 프로그래밍
. 브루트포스 알고리즘
*/

int main()
{
    double result = 0;
    double arr[10007];
    for (int i = 0; i < 10007; i++)
    {
        arr[i] = 0;
    }
    int n;
    double in_arr;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%lf", &in_arr);
        arr[i] = max(in_arr, in_arr * arr[i - 1]);
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (arr[i] > result)
        {
            result = arr[i];
        }
    }
    printf("%.3lf", result);
}
