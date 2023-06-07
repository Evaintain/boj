#include <bits/stdc++.h>

using namespace std;

/*
10093번 문제

접근 방식
->
a ~ b 사이 정수 출력.
a + 1 부터 b - 1 까지 출력하기
갯수는 b - a - 1

* 오답후
오답 1 ~ 2회, a == b의 경우 처리 x -> 질문게시판 보고 알음
오답 3회, a > b 일경우 처리 x -> 질문게시판 보고 알음.
갈길이 멀다..
*/


/*
조건
30점 -> 1 <= a, b <= 1000
70점 -> 1 <= a, b <= 10^15 a와 b의 차이는 최대 10^5
*/

/*
태그
. 구현
*/

class number
{
public:
    void execute(long long a, long long b)
    {
        if (a > b)
        {
            long long temp = a;
            a = b;
            b = temp;
        }
        
        if (b == a)
        {
            printf("0\n");
            return;
        }
        printf("%lld\n", b - a - 1);

        for (long long i = a + 1; i < b; i++)
        {
            printf("%lld ", i);
        }
    }
};

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);

    number n;
    n.execute(a, b);
}
