#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
3066번 문제 접근 방식
->
LIS n log n 의 형식이다.
tc때 마다 벡터를 초기화 하고 LIS의 길이를 구한다.
*/

/*
태그
. 이분 탐색
. 가장 긴 증가하는 부분 수열 O(n log n)
*/

int arr[40007];

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        vector<int> ans;
        int n;
        int idx;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        ans.push_back(arr[0]);

        for (int j = 1; j < n; j++)
        {
            if (ans.back() < arr[j])
            {
                ans.push_back(arr[j]);
            }
            else
            {
                idx = lower_bound(ans.begin(), ans.end(), arr[j]) - ans.begin();
                ans[idx] = arr[j];
            }
        }
        printf("%d\n", ans.size());
    }
}
