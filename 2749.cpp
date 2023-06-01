#include <iostream>

using namespace std;

/*
2749번 문제 접근 방식
->
피사노 주기를 이용하여 푼다
10^k k>=2 라면 15 * 10^k-1의 주기를 가진다
*/

/*
태그
. 수학
. 분할 정복을 이용한 거듭제곱
*/

const int mod = 1000000;
const int p = mod / 10 * 15;
int arr[p + 7];

class fibo
{
public:
    void init()
    {
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < p + 1; i++)
        {
            arr[i] = (arr[i - 2] + arr[i -  1]) % mod;
        }
    }

    void print(long long n)
    {
        printf("%lld", arr[n % p]);
    }
};

int main()
{
    long long n;
    scanf("%lld", &n);

    fibo fb;
    fb.init();
    fb.print(n);
}
