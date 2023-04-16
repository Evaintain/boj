#include <bits/stdc++.h>

using namespace std;

/*
1806 문제
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중,
가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

접근 방식
->
투포인터 접근 N이 10만 이하니까 20만번이 최대 일거임.
1회 틀림 -> 범위 밖에서 불러오게함. 그래서 아래에 조건을 추가해줌.
*/

int main()
{
    int n, m, in_arr, ans = 100001;
    scanf("%d %d", &n, &m);
    int arr[100007] = { 0 };
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &in_arr);
        arr[i] = arr[i - 1] + in_arr;
    }

    int s = 0, e = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (arr[e] - arr[s] < m && e < n + 1) // && e < n + 1 추가
        {
            e++;
        }
        if (arr[e] - arr[s] >= m && s < n + 1) // && s < n + 1 추가
        {
            if (ans > e - s)
            {
                ans = e - s;
            }
            s++;
        }
    }
    if (ans != 100001) printf("%d", ans);
    else printf("0");
}