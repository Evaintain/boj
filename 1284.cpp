#include <iostream>

using namespace std;

/*
1284번 문제 접근 방식
->
\n전 까지 센뒤 - 1 (간격) 그다음 첫문자 부터 비교.
*/

/*
태그
. 수학
. 구현
. 사칙연산
*/

class compare
{
public:
    void execute(char *s, int cnt)
    {
        int len = 0;
        for (int i = 0; i < cnt - 1; i++)
        {
            if (s[i] == '1')
            {
                len += 2;
            }

            else if (s[i] == '0')
            {
                len += 4;
            }

            else
            {
                len += 3;
            }
        }

        printf("%d\n", len + 2 + cnt - 2);
    }
};

int main()
{
    char num[7];
    int cnt = 0;
    compare c;

    while (true)
    {
        scanf("%c", &num[cnt++]);
        if (num[cnt - 1] == '0' && cnt == 1)
        {
            break;
        }

        if (num[cnt - 1] == '\n')
        {
            c.execute(num, cnt);
            cnt = 0;
        }
    }
}
