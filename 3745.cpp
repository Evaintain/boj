#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
3745번 문제 접근 방식
->
LIS n log n 의 형식이다.
n이 들어올때 EOF가 아니라면 LIS를 찾는다.
*/

int arr[100007];

int main()
{
    int n;
    int idx;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        vector<int> ans;

        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (ans.back() < arr[i])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }

        printf("%d\n", ans.size());
    }
}
