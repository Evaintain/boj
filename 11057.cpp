#include <iostream>
#define MOD 10007

using namespace std;

/*
11057번 문제 접근 방식
->
arr[1][0~9] 까지 1로 초기화 한후
arr[n][i~9] 까지 다 더해준다.
->
ex ) arr[10][1] 이면 arr[10][9] 까지 다 더해준다.
그후 mod 10007를 한다.
*/

/*
태그
. 다이나믹 프로그래밍
*/

/*
느낀점
- 보자마자 쉬운 계단수가 떠올랐다.
*/

class dp
{
private:
    int arr[10007][17];
    int sum = 0;
public:
    void init()
    {
        for (int i = 0; i < 10007; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            arr[1][i] = 1;
        }
    }

    void create_dp_arr()
    {
        for (int i = 2; i < 10001; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = j; k < 10; k++)
                {
                    arr[i][j] += arr[i - 1][k];
                }
                arr[i][j] %= MOD;
            }
        }
    }

    void sum_ans(int n)
    {
        for (int i = 0; i < 10; i++)
        {
            sum += arr[n][i];
        }
        sum %= MOD;
    }

    void print_ans()
    {
        printf("%d", sum);
    }
};

int main()
{
    dp dynamic_programming;
    dynamic_programming.init();
    dynamic_programming.create_dp_arr();

    int n;
    scanf("%d", &n);

    dynamic_programming.sum_ans(n);
    dynamic_programming.print_ans();
}
