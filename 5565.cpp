#include <iostream>

using namespace std;

/*
5565번 문제 접근 방식
->
1번쨰 입력 -> 총값
2~10번째 입력의 합 -> 읽을수 있는 가격의 합
총값 - 읽을수 있는 가격의 합 = 읽을수 없는 가격의 합
*/

/*
태그
. 수학
. 구현
. 사칙연산
*/

int main()
{
    int total;
    scanf("%d", &total);
    int sum = 0;
    int each;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &each);
        sum += each;
    }

    printf("%d", total - sum);
}
