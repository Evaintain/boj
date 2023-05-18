#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1365번 문제 접근 방식
->
LIS n log n 을 이용하여 처음 입력되는 n - lis의 크기가 정답이다.
*/

/*
태그
. 가장 긴 증가하는 부분 수열 O(n log n)
*/

int main()
{
    vector<int> v;
    vector<int> ans;
    int n;
    int in_v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_v);
        v.push_back(in_v);
    }

    ans.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (ans.back() < v[i])
        {
            ans.push_back(v[i]);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[idx] = v[i];
        }
    }

    printf("%d", n - ans.size());
}
