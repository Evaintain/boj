#include <iostream>

using namespace std;

/*
4134번 문제

접근 방식
->
4 *10^9 까지 주어짐. -> long long으로 받으면 됨.
4 * 10^9의 루트는 8만이하임. -> 에라토스테네스의 체로 거르고
+1 하면서 소수인지 판별하기.
without Retruning -> 1회 오답
틀렸습니다 -> 2회 오답.
*/

bool prime[80007];
int arr[40007];
int cnt = 0;

void sieve()
{
    for (int i = 2; i < 80007; i++)
    {
        if(!prime[i])
        {
            arr[cnt++] = i;
            for (int j = i; j < 80007; j += i)
            {
                prime[j] = true;
            }
        }
    }
}

int main()
{
    sieve();
    int tc;
    long long n;
    bool flag;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%lld", &n);
        if (n == 0 || n == 1)
        {
            printf("2\n");
            continue;
        }

        while (true)
        {
            flag = false;
            for (int j = 0; j < cnt; j++)
            {
                if (n != arr[j] && n % arr[j] == 0)
                {
                    flag = true;
                    n++;
                    break;
                }
                if (n == arr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                printf("%lld\n", n);
                break;
            }
        }
    }
}
