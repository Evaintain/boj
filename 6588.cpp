#include <iostream>

using namespace std;

/*
6588번 문제 접근 방식
->
골드바흐 파티션에서 확장된 문제
n을 입력받고,
n / 2 작은 소수로 판별 한다.
만약 소수 + n - 소수 가 정답이 된다면, 출력하고 종료, 소수가 n / 2을 넘어간다면, 오류 출력
*/

/*
태그
. 수학
. 정수론
. 소수 판정
. 에라토스테네스의 체
*/

int arr[100007];
int cnt = 0;
bool prime[1000007];

void sieve()
{
    // 에라토스테네스의 체
    for (int i = 2; i < 1000001; i++)
    {
        if (!prime[i])
        {
            arr[cnt++] = i;
            for (int j = i; j < 1000001; j += i)
            {
                prime[j] = true;
            }
        }
    }

    // 소수 판별
    for (int i = 0; i < cnt; i++)
    {
        prime[arr[i]] = false;
    }
}

int main()
{
    sieve();

    int n;
    while(true)
    {
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < cnt; i++)
        {
            if (arr[i] > n / 2)
            {
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
            if (!prime[n - arr[i]])
            {
                printf("%d = %d + %d\n", n, arr[i], n - arr[i]);
                break;
            }
        }
    }
}
