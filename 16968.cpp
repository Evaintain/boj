#include <iostream>

using namespace std;

/*
16968번 문제
->
d가 2개 겹칠경우
10 * 9
d가 3개 겹칠 경우
10 * 9 * 9(앞과 안겹쳐야함)

c가 2개 겹칠 경우
26 * 25
*/

/*
태그
. 수학
. 조합론
*/

class brute_force
{
private:
    int sum = 0;

public:
    void init(char *s)
    {
        if (*s == 'c')
        {
            sum = 26;
        }

        else
        {
            sum = 10;
        }
    }

    void execute(char *s, int size_s)
    {
        init(s);

        for (int i = 1; i < size_s; i++)
        {
            if (*(s + i) == *(s + i - 1))
            {
                if (*(s + i) == 'c')
                {
                    sum *= 25;
                }

                else
                {
                    sum *= 9;
                }
            }

            else
            {
                if (*(s + i) == 'c')
                {
                    sum *= 26;
                }

                else
                {
                    sum *= 10;
                }
            }
        }

        printf("%d", sum);
    }
};

int main()
{
    char input[10];
    scanf("%s", input);

    int s = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        s++;
    }

    brute_force bf;
    bf.execute(input, s);
}
