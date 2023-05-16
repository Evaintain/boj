#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
2637번 문제

접근 방식
->
최상위 부품부터 아래로 내려온다.
위상정렬을 하고 내려온다.
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 위상 정렬
*/

//pair<시작노드, 가중치>
vector<pair<int, int>> graphs[107];
queue<int> q;
int arr[107];
int ans[107];

void travel(int now)
{
    int node;
    for (int i = 0; i < graphs[now].size(); i++)
    {
        node = graphs[now][i].first;
        //부품 추가
        ans[node] += ans[now] * graphs[now][i].second;

        arr[node]--;
        if (arr[node] == 0)
        {
            q.push(node);
        }
    }

    //중간 부품 초기화 (그래프의 자식이 없다면)
    if (!graphs[now].empty())
    {
        ans[now] = 0;
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
    int n;
    int k;
    //시작노드, 연결된 노드, 가중치
    int sv, ev, w;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &sv, &ev, &w);
        arr[ev]++;
        graphs[sv].push_back(make_pair(ev, w));
    }

    for (int i = 1; i < n + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
    }

    //완성품 부터 시작
    q.push(n);
    //완성품 하나 만드는데 필요하므로 1을 지정해준다.
    ans[n] = 1;
    travel(q.front());

    for (int i = 1; i < n; i++)
    {
        if (ans[i] != 0)
        {
            printf("%d %d\n", i, ans[i]);
        }
    }
}
