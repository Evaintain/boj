#include <iostream>

using namespace std;

/*
10990번 문제 접근 방식
->
n을 입력 받음
n개 줄에 (0부터 n - 1) -> i
n - 1 - i 만큼 띄우고 별 출력.
+ 2 * i - 2 만큼 띄우고 별 출력후 \n
*/

/*
태그
. 구현
*/

class star
{
public:
    void execute(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n - 1; j++)
            {
                printf(" ");
            }

            printf("*");

            for (int j = 0; j < 2 * i - 1; j++)
            {
                printf(" ");
                if (j == 2 * i - 2)
                {
                    printf("*");
                }
            }

            if (n - 1 != i)
            {
                printf("\n");
            }
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    star s;
    s.execute(n);
}
