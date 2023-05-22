#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
14003번 문제 접근 방식
->
lis 숫자, 위치를 저장하여 가장 긴 위치부터 아래로 내려오며 값을 저장한뒤,
뒤집어서 출력
*/

/*
태그
. 가장 긴 증가하는 부분 수열 O(n log n)
. 이분탐색
*/

/*
느낀점
- 역탐색이 매우 어려워서 구글링을 하고 이해를 하고나서, 1주일 뒤에 풀었는데, 더 쉽게 구현하는 방법이 있을거 같다.
*/

int arr[1000007];
vector<pair<int, int>> v;
vector<int> ans;
vector<int> lis;

int main()
{
    int n;
    int idx;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    v.push_back(make_pair(arr[0], 0));
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (ans.back() < arr[i])
        {
            idx = ans.size();
            ans.push_back(arr[i]);
        }
        else
        {
            idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
        v.push_back(make_pair(arr[i], idx));
    }

    int len = ans.size() - 1;
    printf("%d\n", len + 1);
    for (int i = n - 1; i > -1; i--)
    {
        if (v[i].second == len)
        {
            len--;
            lis.push_back(v[i].first);
        }
    }

    // 내림차순을 뒤집는 거기에 오름차순 정렬도 맞다.
    sort(lis.begin(), lis.end());

    for (int i = 0; i < lis.size(); i++)
    {
        printf("%d ", lis[i]);
    }
}
