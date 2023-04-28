#include <iostream>

using namespace std;

/*
1644번 문제

접근 방식
->
에라토스테네스의 체로 400만 까지 거르고,
투 포인터로 값을 찾음.
*/

/*
조건
첫째줄에 자연수 N이 주어지는데 N은 1이상 400만이하
*/

/*
태그
. 수학
. 정수론
. 두 포인터
. 소수 판정
. 에라토스테네스의 체
*/

bool check[4000007];
int arr[300007];
int cnt = 0;

void sieve()
{
    for (int i = 2; i < 4000007; i++)
    {
        if (!check[i])
        {
            arr[cnt++] = i;
            for (int j = i ; j < 4000007; j += i)
            {
                check[j] = true;
            }
        }
    }
}

long long sum[300007];

int main()
{
    sieve();
    sum[0] = 0;
    for (int i = 1; i < cnt + 1; i++)
    {
        sum[i] = arr[i - 1] + sum[i - 1];
    }

    int s = 0, e = 1;
    int goal, goal_cnt = 0;
    scanf("%d", &goal);
    for (int i = 0; i < 2 * cnt; i++)
    {
        if (sum[e] - sum[s] > goal)
        {
            if (s >= cnt) continue;
            s++;
        }
        else if (sum[e] - sum[s] < goal)
        {
            if (e >= cnt) continue;
            e++;
        }
        else if (sum[e] - sum[s] == goal)
        {
            goal_cnt++;
            if (e < cnt) e++;
            else s++;
        }
    }
    printf("%d", goal_cnt);
}
