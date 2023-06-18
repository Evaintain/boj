#include <iostream>

using namespace std;

/*
13752번 문제 접근방식
->
n 입력후 숫자 입력 받은만큼 =출력 다 끝나면 \n
*/

/*
태그
. 구현
*/

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            printf("=");
        }
        printf("\n");
    }
}
