#include <iostream>

using namespace std;

/*
1562번 문제 접근 방식
->
arr[101][10][1<<10]을 만들고 1<<10 - 1(0~9 까지 다 켜짐)의 값의 합을 구한다.
*/

/*
태그
. 다이나믹 프로그래밍
. 비트마스킹
. 비트필드를 이용한 다이나믹 프로그래밍
*/

int arr[101][10][1<<10];

class dp
{
private:
    int mod = 1e9;
public:
    void init()
    {
        for (int i = 1; i < 10; i++)
        {
            arr[1][i][1<<i] = 1;
        }
    }

    void execute()
    {
        for (int i = 2; i < 101; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < (1<<10); k++)
                {
                    if (j == 9)
                    {
                        arr[i][j][k | (1<<j)] = (arr[i - 1][j - 1][k] + arr[i][j][k | (1<<j)]) % mod;
                    }

                    else if (j == 0)
                    {
                        arr[i][j][k | (1<<j)] = (arr[i - 1][j + 1][k] + arr[i][j][k | (1<<j)]) % mod;
                    }

                    else
                    {
                        arr[i][j][k | (1<<j)] = (arr[i - 1][j + 1][k] + arr[i - 1][j - 1][k] + arr[i][j][k | (1<<j)]) % mod;
                    }
                }
            }
        }
    }

    void print(int n)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += arr[n][i][(1<<10) - 1];
            sum %= mod;
        }
        printf("%d", sum);
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    dp d;
    d.init();
    d.execute();
    d.print(n);
}
