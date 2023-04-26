#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

/*
17175번 문제

접근 방식
->
n은 50까지 호출되므로 배열은 51 + a개 잡아준다.
0 -> 1
1 -> 1
2 -> 3
3 -> 5
4 -> 9
5 -> 15
n -> n - 1 + n - 2 + 1 이므로 for 문을 돌리며 1,000,000,007로 나눠 준다
*/

/*
점화식 (n > 1)
arr[n] = arr[n - 1] + arr[n - 2] + 1
*/

/*
태그
. 다이나믹 프로그래밍
*/

int main()
{
    int arr[57];
    arr[0] = arr[1] = 1;
    for (int i = 2; i < 51; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2] + 1) % MOD;
    }
    int n;
    scanf("%d", &n);
    printf("%d", arr[n]);
}
