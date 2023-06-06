#include <iostream>

using namespace std;

/*
11170번 문제 접근 방식
->
Test case 수 20
0 <= n <= m <= 100000
최대 20 * 1000000 * 14정도 걸림.
/ 10 | % 10 -> 14번정도 걸림
*/

/*
태그
. 수학
. 구현
. 브루트포스 알고리즘
*/

class brute_force
{
private:
    long long cnt = 0;
    int temp;

public:
    void init()
    {
        cnt = 0;
    }

    void execute(int a, int b)
    {
        init();

        for (int i = a; i < b + 1; i++)
        {
            temp = i;
            if (temp == 0)
            {
                cnt++;
            }

            while (temp != 0)
            {
                if (temp % 10 == 0)
                {
                    cnt++;
                }

                temp /= 10;
            }
        }

        printf("%lld\n", cnt);
    }
};

int main()
{
    brute_force bf;

    int tc;
    int n, m;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &n, &m);
        bf.execute(n, m);
    }
}
