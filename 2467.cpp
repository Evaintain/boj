#include <iostream>

using namespace std;

/*
2467번 문제 접근 방식
->
0, n - 1부터 차례대로 검증한다.(정렬이 되어있는 상태이므로, 두 값을 더했을때 음수라면,
0쪽에 ++, 아니라면 n-1 --이다.) 그리고 두수가 겹치지 않을동안만 while문을 돌린다.)
*/

/*
태그
. 이분 탐색
. 두 포인터
*/

int main()
{
    int arr[100007];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = n - 1;
    int left_value;
    int right_value;

    int ans = 2e9 + 7;
    while (left < right)
    {
        if (ans > abs(arr[left] + arr[right]))
        {
            ans = abs(arr[left] + arr[right]);
            left_value = arr[left];
            right_value = arr[right];
        }

        if (arr[left] + arr[right] < ans)
        {
            left++;
        }

        else
        {
            right--;
        }
    }

    printf("%d %d", left_value, right_value);
}
