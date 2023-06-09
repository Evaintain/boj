#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
2170번 문제 접근 방식
->
시작점 순서대로 정렬.
다른 시작점이 두 점사이에 있으면 끝점을 큰곳으로 합침.
ex) 1 3, 2 5 -> 1 5 | 1 4, 2 3 -> 1 4
만약 두점사이에 없으면 다른 선분을 새로 시작함.
*/

/*
태그
. 정렬
. 스위핑
*/

struct info
{
    int s;
    int e;
};

bool compare(info a, info b)
{
    return a.s < b.s;
}

class line
{
private:
    int sum = 0;
    int s;
    int e;

public:
    void execute(vector<info> &v)
    {
        s = v[0].s;
        e = v[0].e;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].s >= s && v[i].s <= e)
            {
                e = max(v[i].e, e);
            }

            else
            {
                sum += (e - s);
                s = v[i].s;
                e = v[i].e;
            }
        }

        sum += (e - s);

        printf("%d", sum);
    }
};

int main()
{
    int n;
    int s, e;
    vector<info> v;
    line l;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s, &e);
        v.push_back(info{s, e});
    }

    sort(v.begin(), v.end(), compare);
    l.execute(v);
}
