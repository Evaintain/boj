#include <iostream>

using namespace std;

/*
1182번 문제 접근 방식
->
n을 입력받아서 (1 << n) - 1 연산을 한다.
그 상태로 가능한 모든 배열을 탐색한다.
n이 5인경우
i = 1 ~ 31까지 탐색함
000001 ~ 011111 까지 탐색해서 덧셈을 함.
*/

/*
태그
. 브루트포스 알고리즘
. 백트래킹
*/

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    int arr[27];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum;
    int cnt = 0;

    for (int i = 1; i < (1 << n); i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
        }

        if (sum == s)
        {
            cnt++;
        }
    }

    printf("%d", cnt);
}
