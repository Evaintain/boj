#include <iostream>

using namespace std;

/*
12833번 접근 방식
->
a ^ b ^ b = a
즉 c % 2 하고 나머지 만큼 XOR 연산 해주면 된다.
*/

/*
태그
. 수학
. 비트마스킹
*/

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c % 2 == 0)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d", a ^ b);
    }
}
