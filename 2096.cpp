#include <iostream>
#include <algorithm>

#define MAX 100007
using namespace std;

/*
2096번 문제

접근 방식
->
왼쪽 -> 왼쪽 or 가운데
가운데 -> 왼쪽 or 가운데 or 오른쪽
오른쪽 -> 가운데 or 오른쪽

i + 1 왼쪽 -> i의 왼쪽 or 가운데
i + 1 가운데 -> i의 왼쪽 or  가운데 or 오른쪽
i + 1 오른쪽 -> 가운데 or 오른쪽

1회 -> 메모리 초과 bits/stdc++.h -> iostream, algorithm로 변경
2회 -> 메모리 초과 방법을 바꿔야함. 질문게시판의 슬라이딩 윈도우라는 기법을 들음.
x,y x,y+1, x,y+2
x+1,y x+1,y+1 x+1,y+2
x + 1의 연산결과를 x에 다시 넣음으로써 배열의 크기를 줄인다.
*/

int max_arr[3][3];
int min_arr[3][3];
int arr[MAX][3];

int main()
{
    int n, in_arr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &in_arr);
            arr[i][j] = in_arr;
        }
    }

    max_arr[0][0] = min_arr[0][0] = arr[0][0];
    max_arr[0][1] = min_arr[0][1] = arr[0][1];
    max_arr[0][2] = min_arr[0][2] = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        max_arr[1][0] = max(max_arr[0][0], max_arr[0][1]) + arr[i][0];
        max_arr[1][1] = max({max_arr[0][0], max_arr[0][1], max_arr[0][2]}) + arr[i][1];
        max_arr[1][2] = max(max_arr[0][1], max_arr[0][2]) + arr[i][2];
        min_arr[1][0] = min(min_arr[0][0], min_arr[0][1]) + arr[i][0];
        min_arr[1][1] = min({min_arr[0][0], min_arr[0][1], min_arr[0][2]}) + arr[i][1];
        min_arr[1][2] = min(min_arr[0][1], min_arr[0][2]) + arr[i][2];

        max_arr[0][0] = max_arr[1][0];
        max_arr[0][1] = max_arr[1][1];
        max_arr[0][2] = max_arr[1][2];

        min_arr[0][0] = min_arr[1][0];
        min_arr[0][1] = min_arr[1][1];
        min_arr[0][2] = min_arr[1][2];
    }

    int min_val = min({min_arr[0][0], min_arr[0][1], min_arr[0][2]});
    int max_val = max({max_arr[0][0], max_arr[0][1], max_arr[0][2]});
    printf("%d %d", max_val, min_val);
}
