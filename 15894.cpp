#include <bits/stdc++.h>

using namespace std;

/*
15894번 문제

접근 방식
->
n이 입력됐을때 그 피라미드를 구함.
즉, 밑변은 n 이고 높이도 n임. 그리고 윗변의 합도 n임. 결론은 4n임.
*/

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld", 4 * n);
}
