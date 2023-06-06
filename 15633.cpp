#include <iostream>

using namespace std;

/*
15633번 문제 접근 방식
->
주어진수의 약수의 합을 구한뒤, * 5 - 24를 한다.
*/

/*
태그
. 수학
. 브루트포스 알고리즘
. 사칙연산
*/

class brute
{
private:
    int sum = 0;

public:
    void execute(int n)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (n % i == 0)
            {
                sum += i;
            }
        }

        printf("%d", sum * 5 - 24);
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    brute b;
    b.execute(n);
}
