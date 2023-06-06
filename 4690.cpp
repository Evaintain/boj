#include <iostream>

using namespace std;

/*
4690번 문제 접근 방식
->
a^3 = b^3 + c^3 + d^3
-> b, c, d < a
4중 for문으로 해결한다.
증가하는 순서이기 때문에, b c d 가아닌 d c b 순서로 for문을 돌린다.
틀린이후
-> 반례를 보았음.
(무조건적으로 d c b라고 b가 작은거 부터 올라오진 않음.)
-> 그렇다면, b = 1부터, c 는 b부터, d는 c부터 시작하면 b가 오름차순(b,c,d도 오름차순)이 될것임.
문제 조건. 1보다큰 자연수 -> 1이 아닌 2부터 시작
숫자간의 띄어쓰기가 없다..
*/

/*
문제를 푸는 이유
->
제일 처음 시작한 브루트포스 이지만, 브루트포스가 약하다고 느꼈기에 처음부터 시작한다.
*/

/*
태그
. 수학
. 구현
. 브루트포스 알고리즘
*/

class brute
{
private:
    int a3, b3, c3, d3;
    int sum;

public:
    int multiply_three(int x)
    {
        return x * x * x;
    }

    void execute()
    {
        for (int a = 2; a < 101; a++)
        {
            for (int b = 2; b < a; b++)
            {
                for (int c = b; c < a; c++)
                {
                    for (int d = c; d < a; d++)
                    {
                        a3 = multiply_three(a);
                        b3 = multiply_three(b);
                        c3 = multiply_three(c);
                        d3 = multiply_three(d);
                        sum = b3 + c3 + d3;


                        if (a3 == sum)
                        {
                            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    brute bf;
    bf.execute();
}
