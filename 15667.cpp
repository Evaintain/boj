#include <iostream>

using namespace std;

/*
15667번 문제 접근 방식
->
1 -> k -> k ^ 2
k^2 + k + 1 = n
여기에 맞는 n이 주어지면 조건에 맞는 k를 찾으면 된다
*/

/*
태그
. 수학
. 브루트포스 알고리즘
. 사칙연산
*/

class fire
{
private:
    int k = 0;

public:
    void execute(int n)
    {
        for (int i = 1; i * i + i + 1 < n + 1; i++)
        {
            k = i;
        }

        printf("%d", k);
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    fire f;
    f.execute(n);
}
