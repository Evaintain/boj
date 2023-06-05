#include <iostream>

using namespace std;

/*
2847번 문제 접근 방식
->
점수를 줄이는 것을 최소한으로 줄여야 하기때문에,
뒤부터 시작 i, i-1의 차이는 1이 되도록 한다.
*/

/*
태그
. 그리디 알고리즘
*/

class game
{
private:
    int sum = 0;

public:
    void execute(int n, int *arr)
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (*(arr + i) <= *(arr + i - 1))
            {
                sum += *(arr + i - 1) - *(arr + i) + 1;
                *(arr + i - 1) = *(arr + i) - 1;
            }
        }

        printf("%d", sum);
    }
};

int main()
{
    int arr[107];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    game g;
    g.execute(n, arr);
}
