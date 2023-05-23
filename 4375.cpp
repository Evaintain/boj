#include <iostream>

using namespace std;

/*
4375번 문제 접근 방식
->
입력은 여러개의 테스트 케이스로 이루어져 있다 -> EOF
1 부터 n으로 나눠질때까지 * 10 + 1을 반복한다. int형의 범위를 벗어날수 있으므로
long long으로 선언한다
시간 초과가 떴다. 배열에다가 선언 해줘야 할듯.
+
모듈러 연산을 써야한다.
*/

/*
태그
. 수학
. 브루트포스 알고리즘
. 정수론
*/

int arr[10007];

int main()
{
    for (int i = 1; i < 10001; i++)
    {
        if (i % 2 == 0 || i % 5 == 0)
        {
            continue;
        }
        int cnt = 1;
        long long total = 1;
        while (total % i != 0)
        {
            total *= 10;
            total++;
            total %= i;
            cnt++;
        }
        arr[i] = cnt;
    }

    int n;
    long long total = 0;
    int cnt = 0;
    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", arr[n]);
    }
}
