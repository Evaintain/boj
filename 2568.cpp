#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
2568번 문제 접근 방식
->
시작점을 오름차순으로로 정렬한뒤 그에따라 끝점을 정렬한다.
그다음에 LIS 숫자, 인덱스 저장후 최대길이에서 역추적후,
len의 길이에서 역추적할때, 아닌것을 모아서 시작번호를 가져온다.
*/

/*
태그
. 이분 탐색
. 가장 긴 증가하는 부분 수열 O(n log n)
*/

/*
느낀점
- 구조체를 써서 푸는 것이 쉬웠는데 그 생각까지 가기 힘들었다.
*/

struct info
{
    int sv;
    int ev;
    int idx;
};

vector<info> v;
vector<pair<int, int>> input;
vector<int> ans;
vector<int> lis;

int main()
{
    int idx;
    int n;
    int sv, ev;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &sv, &ev);
        input.push_back(make_pair(sv, ev));
    }

    sort(input.begin(), input.end());

    v.push_back({input[0].first, input[0].second, 0});
    ans.push_back(input[0].second);

    for (int i = 1; i < n; i++)
    {
        if (ans.back() < input[i].second)
        {
            idx = ans.size();
            ans.push_back(input[i].second);
        }
        else
        {
            idx = lower_bound(ans.begin(), ans.end(), input[i].second) - ans.begin();
            ans[idx] = input[i].second;
        }
        v.push_back({input[i].first, input[i].second, idx});
    }

    int len = ans.size() - 1;


    for (int i = n - 1; i > - 1; i--)
    {
        if (len == v[i].idx)
        {
            len--;
        }
        else
        {
            lis.push_back(v[i].sv);
        }
    }

    printf("%d\n", lis.size());

    for (int i = lis.size() - 1; i > -1; i--)
    {
        printf("%d\n", lis[i]);
    }
}
