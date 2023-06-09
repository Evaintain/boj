#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
11000번 문제 접근 방식
->
끝나는 시간순 정렬 끝나는 시간이 같다면, 시작 시간순 정렬후
우선순위큐를 쓴다. -> 끝나는 시간만 넣음
이때 끝나는 시간이 다른 강의의 시작 시간보다 크면
다른 강의의 끝나는 시간을 넣는다.
아닐 경우 그 숫자를 빼고, 그 다음 강의가 끝나는 시간을 넣는다.

1회 틀림 -> 시작 순서대로 정렬한다.
*/

/*
태그
. 자료 구조
. 그리디 알고리즘
. 우선순위 큐
. 정렬
*/

struct info
{
    int s;
    int e;
};

bool compare(info a, info b)
{
    if (a.s == b.s)
    {
        return a.e < b.e;
    }

    return a.s < b.s;
}

class time
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;

public:
    void execute(vector<info> &v)
    {
        pq.push(v[0].e);
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].s >= pq.top())
            {
                pq.pop();
                pq.push(v[i].e);
            }

            else
            {
                pq.push(v[i].e);
            }
        }

        printf("%d", pq.size());
    }
};

int main()
{
    int n;
    int s, e;
    vector<info> v;
    time t;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s, &e);
        v.push_back(info{s, e});
    }

    sort(v.begin(), v.end(), compare);

    t.execute(v);
}
