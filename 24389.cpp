#include <iostream>

using namespace std;

/*
24389번 문제 접근 방식
->
N, N의 보수 서로 다른 비트수 출력

0000 0000 0000... 0001
1111 1111 1111... 1111
*/

int main()
{
    int n;
    int not_n;
  
    // n을 입력 받음
    scanf("%d", &n);
    // n의 보수를 취해줌.
    not_n = ~n + 1;

    // n과 not_n을 xor 연산함.
    int xor_n = not_n ^ n;
    int cnt = 0;
    // 만약 xor_n의 비트가 켜져있으면 다르다는 것임.
    for (int i = 0; i < 32; i++)
    {
        if (xor_n & (1 << i))
        {
            cnt++;
        }
    }

    printf("%d", cnt);
}
