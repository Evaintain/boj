#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1931번 문제 접근 방식
->
회의가 끝나는 시간이 가장 짧은거 부터 선택한다.
회의가 끝나는대로 바로 회의를 시작할수 있음을 유의한다.
만약 회의가 끝나는 시간이 같을경우, 시작시간 순서대로 배치한다.
*/

/*
태그
. 그리디 알고리즘
. 정렬
*/

struct info
{
    int s;
    int e;
};

bool compare(info a, info b)
{
    if (a.e == b.e)
    {
        return a.s < b.s;
    }
    return a.e < b.e;
}

class time
{
private:
    int s = 0;
    int e = 0;
    int cnt = 0;

public:
    void execute(vector<info> &v)
    {
        s = v[0].s;
        e = v[0].e;
        cnt++;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].s >= e)
            {
                e = v[i].e;
                cnt++;
            }
        }

        printf("%d", cnt);
    }
};

int main()
{
    int n;
    int s, e;
    vector<info> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s, &e);
        v.push_back(info{s, e});
    }

    sort(v.begin(), v.end(), compare);

    time t;
    t.execute(v);
}
