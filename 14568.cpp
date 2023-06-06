#include <iostream>

using namespace std;

/*
14568번 문제 접근 방식
->
n의 사탕을 나눠 가짐
3명이서 나눠 가지며
아무도 0을 받지 않음
a, b, c
a + b + c = n이라 할때
c = b + x(x >= 2)이며
a % 2 != 1 이어야한다.
->
a을 +2로 n까지 돌린다,
그리고 
b = n - a - 1(아니면 c가 0부터 시작함)
c = n - a - b
b - 2 >= c 일때 cnt++
b - 2 == c 일때 for문 종료
*/

/*
태그
. 수학
. 브루트포스 알고리즘
. 사칙연산
*/

class candy
{
private:
    long long sum = 0;

public:
    void execute(int n)
    {
        for (int a = 2; a < n + 1; a += 2)
        {
            for (int b = n - a - 1; b > 0; b--)
            {
                int c = n - a - b;

                if (b - 2 >= c)
                {
                    sum++;
                }

                if (b + 2 == c)
                {
                    break;
                }
            }
        }

        printf("%lld", sum);
    }
};


int main()
{
    int n;
    scanf("%d", &n);
    candy c;
    c.execute(n);
}
