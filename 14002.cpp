#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
14002번 문제

접근 방식
->
n의 크기가 작으므로 O(n^2) 사용.
vector를 쓰는데 lis 배열의 수가 vector의 size보다 크면 그 수를 추가한다.
1회 실패 -> 1개가 입력되는 반례 적용 x
2회 실패 -> 반례적용 x

->
접근 방식을 바꿈 가장 큰 idx부터 아래로 내려오기로 바꿈.
vector에 넣은뒤 끝나면 뒤집어서 출력
*/

/*
태그
. 다이나믹 프로그래밍
*/

/*
느낀점
위에서 부터 내려오며 비교해야 반례에 안걸릴수 있다. 그걸 몰라서 반례에 걸렸었다.
*/

int main()
{
    int n;
    int idx = 0;
    int arr[1007];
    int lis[1007];
    int len = 1;
    vector<int> ans;

    scanf("%d", &n);

    //입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //lis 길이 구하기
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[j] + 1, lis[i]);
                if (lis[i] > len)
                {
                    len = lis[i];
                    idx = i;
                }
            }
        }
    }

    int cnt = len;
    //수열 넣기
    for (int i = idx; i > -1; i--)
    {
        if (cnt == 0)
        {
            break;
        }

        if (lis[i] == cnt)
        {
            if (!ans.empty() && ans.back() > arr[i])
            {
                ans.push_back(arr[i]);
                cnt--;
            }

            if (ans.empty())
            {
                ans.push_back(arr[i]);
                cnt--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    printf("%d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", ans[i]);
    }
}
