#include <iostream>

using namespace std;

/*
21313번 문제 접근 방식
->
1번 문어가 1번손으로 2번을 잡음
2번 문어가 2번손으로 3번을 잡음
3번 문어가 1번손으로 4번을 잡음
...
2n번 문어가 2번손으로 2n+1번을 잡음
2n+1번 문어가 1번손으로 1번을 잡음.

틀린후
if 문어가 5마리라면?
1 -> 1번손 2번 잡음
2 -> 2번손 3번 잡음
3 -> 1번손 4번 잡음
4 -> 2번손 5번 잡음
5 -> 3번손 3번으로 잡음.

짝수 일땐 위의 공식이 성립하나 홀수 일땐
마지막에 3을 출력해야함.
*/

/*
태그
. 그리디 알고리즘
. 애드 혹
*/

class octopus
{
public:
    void execute(int input)
    {
        for (int i = 0; i < input; i++)
        {
            if (i == input - 1)
            {
                if (input % 2 == 0)
                {
                    printf("2 ");
                }

                else
                {
                    printf("3 ");
                }

                break;
            }

            if (i % 2 == 0)
            {
                printf("1 ");
            }

            else
            {
                printf("2 ");
            }
        }
    }
};

int main()
{
    int input;
    scanf("%d", &input);

    octopus op;
    op.execute(input);
}
