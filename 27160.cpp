#include <iostream>

using namespace std;

/*
27160번 문제

접근 방식
->
STRAWBERRY, BANANA, LIME, PLUM가 주어지므로
문자열 숫자를 받아서 S B L P 순서대로 for문을 돌리면서, 만약 문자열의 첫글자와 같을경우, 그 배열에 뒤에 숫자만큼 추가.
*/

/*
조건
카드의 갯수 N, 1이상 10^5이하,
과일의 갯수 X, 1이상 5이하,
입력으로 주어지는 수는 모두 정수.
*/

/*
태그
. 구현
. 자료구조
. 문자열
. 해시를 이용한 집합과 맵
*/

int main()
{
    int n, plus_arr_num;
    int arr[] = {0, 0, 0, 0};
    char check_s[] = {'S', 'B', 'L', 'P'};
    char input_s[17];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", input_s, &plus_arr_num);
        for (int j = 0; j < 4; j++)
        {
            if (input_s[0] == check_s[j])
            {
                arr[j] += plus_arr_num;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == 5)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
