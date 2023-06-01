#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

/*
13711번 문제 접근 방식
->
한 배열을 기준으로 정렬한다. 그후 LIS를 구한다.
*/

/*
태그
. 가장 긴 증가하는 부분 수열: o(n log n)
*/

vector<int> v;
map<int, int> m;

class lis
{
private:
    int idx;
    vector<int> ans;
public:
    void execute(vector<int> &v)
    {
        ans.push_back(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            if(ans.back() < v[i])
            {
                ans.push_back(v[i]);
            }
            else
            {
                idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                ans[idx] = v[i];
            }
        }

        printf("%d", ans.size());
    }
};

int main()
{
    int n;
    int in_m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_m);
        m[in_m] = i;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_m);
        v.push_back(m[in_m]);
    }

    lis ls;
    ls.execute(v);
}
