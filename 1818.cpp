#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1818번 문제 접근 방식
->
LIS n log n를 구현하면 된다.
*/

/*
태그
. 가장 긴 증가하는 부분 수열: o(n log n)
*/

int main()
{
    int n;
    int in_v;
    vector<int> arr;
    vector<int> ans;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_v);
        arr.push_back(in_v);
    }

    ans.push_back(arr[0]);
    int idx;

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
    printf("%d", n - ans.size());
}
