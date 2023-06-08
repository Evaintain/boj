#include <iostream>

using namespace std;

/*
17614번 문제 접근 방식
->
1 부터 n 까지
%10 -> 이것이 3으로 나눠 떨어지는지 본다. 10의 배수가 아닐때만 본다.
/10 -> 0이 될때까지
*/

/*
태그
. 구현
. 브루트포스 알고리즘
*/

class three_six_nine
{
private:
    long long ans = 0;

public:
    void execute(int n)
    {
        for (int i = 1; i < n + 1; i++)
        {
            int temp = i;
            while (temp != 0)
            {
                if ((temp % 10) % 3 == 0)
                {
                    if (temp % 10 != 0)
                    {
                        ans++;
                    }
                }

                temp /= 10;
            }
        }

        printf("%lld", ans);
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    three_six_nine tsn;

    tsn.execute(n);
}
