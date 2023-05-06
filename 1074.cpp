#include <iostream>

using namespace std;

/*
1074번 문제

접근 방식
->
N이 주어질때 가로 세로(0~ 2^N - 1)를 /2로 분할하여 4등분을 한뒤 4등분을 재귀로 구현하여 조건에 부합하는 곳을 찾는다.
*/

/*
조건 & 입출력
첫째 줄에 정수 N, r, c가 주어진다.
r행 c열을 몇 번째로 방문했는지 출력한다.
1 ≤ N ≤ 15
0 ≤ r, c < 2N
*/

/*
태그
. 분할 정복
. 재귀
*/

/*
느낀점
구현 자체의 어려움보다 고칠때 수식 수정이 더 어려웠다;
*/

int arr[17];
int min_value = 0;
int max_value = 1;

struct location
{
    int x;
    int y;
};

void div_square(int n, location now)
{;
    if (n == 0)
    {
        return;
    }

    int x = now.x;
    int y = now.y;

    if (x >= arr[n - 1])
    {
        if (y >= arr[n - 1])
        {
            min_value = max_value - (arr[n - 1] * arr[n - 1]) + 1;
            div_square(n - 1, location{x - arr[n - 1], y - arr[n - 1]});
        }
        else //x, y 가 x만  n / 2를 넘을경우 min, max값을 당겨준다.
        {
            max_value -= (2 * arr[n - 1] * arr[n - 1]);
            min_value = (max_value - (arr[n - 1] * arr[n - 1]) + 1);
            div_square(n - 1, location{x - arr[n - 1], y});
        }
    }
    else //x, y 가 y만  n / 2를 넘을경우 min, max값을 당겨준다. (max - arr[n - 1] * arr[n - 1])
    {
        if (y >= arr[n - 1])
        {
            max_value -= (arr[n - 1] * arr[n - 1]);
            min_value = (max_value - (arr[n - 1] * arr[n - 1]) + 1);
            div_square(n - 1, location{x, y - arr[n - 1]});
        }
        else //x, y 가 둘다 n / 2를 못넘을경우 max값을 당겨준다.
        {
            max_value -= (3 * arr[n - 1] * arr[n - 1]);
            div_square(n - 1, location{x, y});
        }
    }
}

int main()
{
    arr[0] = 1;
    for (int i = 1; i < 16; i++)
    {
        arr[i] = arr[i - 1] * 2;
    }
    int n, y, x;
    scanf("%d %d %d", &n, &y, &x);

    //n의 크기의 최댓값 적는 함수
    for (int i = 0 ; i < 2 * n; i++)
    {
        max_value *= 2;
    }

    max_value--;

    div_square(n, location{x, y});

    printf("%d", min_value);
}
