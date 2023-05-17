#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
14567번 문제

접근 방식
->
위상 정렬을 이용한 방문순서를 적는다.
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 위상 정렬
*/

vector<int> graphs[1007];
queue<int> q;
int arr[1007];
int ans[1007];

void travel(int now)
{
    for (auto node : graphs[now])
    {
        arr[node]--;
        if (arr[node] == 0)
        {
            ans[node] = ans[now] + 1;
            q.push(node);
        }
    }

    q.pop();
    if (q.empty())
    {
        return;
    }
    travel(q.front());
}

int main()
{
    int n, k;
    int sv, ev;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &sv, &ev);
        arr[ev]++;
        graphs[sv].push_back(ev);
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] == 0)
        {
            ans[i] = 1;
            q.push(i);
        }
    }

    travel(q.front());

    for (int i = 1; i < n + 1; i++)
    {
        printf("%d ", ans[i]);
    }
}
