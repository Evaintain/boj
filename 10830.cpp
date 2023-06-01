#include <iostream>

using namespace std;

/*
10830번 문제 접근 방식
->
분할해서 행렬 제곱을 한다.
*/

/*
태그
. 수학
. 분할 정복
. 분할 정복을 이용한 거듭제곱
. 선형대수학
*/

int arr[5][5];
int n;

class div_con
{
private:
    int mod = 1000;
    int base[5][5];
public:
    void init(int a[5][5])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void copy_arr(int a[5][5], const int b[5][5])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = b[i][j];
            }
        }
    }

    void multiply(int a[5][5], const int b[5][5])
    {
        int temp[5][5];

        init(temp);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    temp[i][j] += a[i][k] * b[k][j];
                }
                temp[i][j] %= mod;
            }
        }

        copy_arr(a, temp);
    }

    void execute(long long b)
    {
        copy_arr(base, arr);

        b -= 1;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                multiply(base, arr);
            }
            multiply(arr, arr);
            b /= 2;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", base[i][j] % 1000);
            }
            printf("\n");
        }
    }
};

int main()
{
    long long b;
    scanf("%d %lld", &n, &b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    div_con dc;
    dc.execute(b);
}
