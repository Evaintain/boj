#include <iostream>

using namespace std;

/*
1267번 문제 접근 방식
->
시간 s
s + 30 / 30 => 영식
s + 60 / 60 => 민식

이때 각각 값을 구해서 값을 비교한다.
*/

/*
태그
. 수학
. 사칙연산
*/

class price
{
private:
    int m = 0;
    int y = 0;

public:
    void execute(int n)
    {
        m += 15 * ((n + 60) / 60);
        y += 10 * ((n + 30) / 30);
    }

    void print()
    {
        if (m == y)
        {
            printf("Y M");
        }

        else
        {
            printf("%c", (y > m) ? 'M' : 'Y');
        }

        printf(" %d", (y > m) ? m : y);
    }
};

int main()
{
    price p;
    int n;
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        p.execute(x);
    }

    p.print();
}
