#include <iostream>

using namespace std;

/*
25591번 문제 접근 방식
->
a, b 주어짐.
x = 100 - a, y = 100 - b, q = 100 - (x + y), x * y, c = x * y / 100, r = x * y % 100
q + c, r
*/

/*
태그
. 수학
. 구현
. 사칙연산
*/

class math
{
private:
    int x;
    int y;
    int q;
    int c;
    int r;

public:
    void execute(int a, int b)
    {
        x = 100 - a;
        y = 100 - b;
        q = 100 - (x + y);
        c = x * y / 100;
        r = x * y % 100;
        printf("%d %d %d %d %d %d\n", x, y, q, x * y, c, r);
        printf("%d %d", q + c, r);
    }
};

int main()
{
    int a, b;

    math m;
    scanf("%d %d", &a, &b);

    m.execute(a, b);
}
