#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 32007

using namespace std;

/*
2252번 문제

접근 방식
->
위상정렬, bfs를 시작할때마다 시작 노드를 ans라는 곳에 추가해준다.
*/

/*
태그
. 그래프 이론
. 위상 정렬
*/

/*
느낀점
이거를 순서까지 정해주면 문제집(1766)문제와 같아질거 같다
*/

vector<int> graphs[MAX];
int arr[MAX];
queue<int> q;
vector<int> ans;

void bfs(int now)
{
    ans.push_back(now);
    int connect_node;

    for (int i = 0; i < graphs[now].size(); i++)
    {
        connect_node = graphs[now][i];
        arr[connect_node]--;
        if (arr[connect_node] == 0)
        {
            q.push(connect_node);
        }
    }
    q.pop();
    if (q.empty())
    {
        return;
    }
    bfs(q.front());
}

int main()
{
    int n, m;
    int node, connect_node;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &node, &connect_node);
        graphs[node].push_back(connect_node);
        arr[connect_node]++;
    }

    for (int i = 1; i < n + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
        if (arr[i] == 0)
        {
            q.push(i);
        }
    }

    bfs(q.front());

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
}
