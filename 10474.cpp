#include <iostream>

using namespace std;

/*
10474번 문제 접근 방식
->
기약분수로 만들지 말아야 한다.(3/12를 1/4로 바꿔 출력하지 마시오.)
에 따라
n, m이 주어질때

n/m n%m / m 을 출력할것.
*/

/*
태그
. 수학
. 사칙연산
*/

class div_cal
{
public:
    void execute(int n, int m)
    {
        printf("%d %d / %d\n", n / m, n % m, m);
    }
};

int main()
{
    int n, m;
    div_cal d;

    while (true)
    {
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0)
        {
            break;
        }

        d.execute(n, m);
    }
}
