#include <iostream>

using namespace std;

/*
1011번 문제 접근 방식
->
홀수 번째 1 * 2 + 2 * 2 ... (n - 1) * 2 + n ->
짝수 번째 1 * 2 + 2 * 2 ... (n - 1) * 2 + n * 2 ->
제곱수 일때 홀수 번째이고
제곱수 + sqrt(제곱수) 가 짝수 번째임.
그 구간에 속함
=> sqrt(제곱수) * (sqrt(제곱수) + 1)
*/

/*
태그
. 수학
*/

int arr[100007];

int main()
{
    // 배열 만드는것.
    int a = 1, b = 1;
    for (int i = 1; i < 92681; i++)
    {
        arr[i] = a * b;
        if (i % 2 == 1)
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    int tc;
    int x, y;
    scanf("%d", &tc);
    for (int j = 0; j < tc; j++)
    {
        scanf("%d %d", &x, &y);
        int value = y - x;
        int ans = 0;

        for (int i = 1; i < 92681; i++)
        {
            if (value <= arr[i])
            {
                ans = i;
                break;
            }

            if (i == 92680 && arr[i] < value)
            {
                ans = i + 1;
            }
        }
        printf("%d\n", ans);
    }
}
