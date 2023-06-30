#include <iostream>

using namespace std;

/*
13116번 문제 접근 방식
->
공통 조상 찾는것이다.
*/

class problem
{
private:
    int arr[1507];

public:
    void init()
    {
        int two = 1;
        int cnt = 1;
        for (int a = 1; a < 11; a++)
        {
            for (int i = 0; i < two; i++)
            {
                arr[i + two] = cnt;
            }
            two *= 2;
            cnt++;
        }
    }

    void execute(int a, int b)
    {
        while (arr[a] != arr[b])
        {
            if (arr[a] > arr[b])
            {
                a /= 2;
            }

            else
            {
                b /= 2;
            }
        }

        while (a != b)
        {
            a /= 2;
            b /= 2;
        }

        printf("%d\n", a * 10);
    }
};

int main()
{
    int x;
    problem p;
    int a, b;
    p.init();

    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        scanf("%d %d", &a, &b);
        p.execute(a, b);
    }
}
