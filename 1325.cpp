#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10007


using namespace std;

/*
1325번 문제

접근 방식
->
노드 탐색마다 cnt를 늘려간다.
배열[시작노드]에 cnt값을 저장한다.
그중 최댓값을 골라서 출력한다.
*/

/*
태그
. 그래프 이론
. 그래프 탐색
. 너비 우선 탐색
. 깊이 우선 탐색
*/

/*
느낀점
유향그래프라 visited가 필요없을줄 알았으나(어쩌피 가르키는곳이 있을것이므로), 사이클을 생각하지 못해서 어려웠던 문제.
*/

vector<int> graphs[MAX];
int arr[MAX];
queue<int> q;
int cnt = 0;
int max_value = 0;
bool visited[MAX];

void visited_clear()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

void bfs(int now, int start)
{
    cnt++;
    int next_node;

    for (int i = 0; i < graphs[now].size(); i++)
    {
        next_node = graphs[now][i];
        if (!visited[next_node])
        {
            visited[next_node] = true;
            q.push(next_node);
        }
    }

    q.pop();
    if (q.empty())
    {
        arr[start] = cnt;
        if (cnt > max_value)
        {
            max_value = cnt;
        }
        return;
    }
    bfs(q.front(), start);
}

int main()
{
    int n, m;
    int node, connect_node;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &connect_node, &node);
        graphs[node].push_back(connect_node);
    }

    for (int i = 1; i < n + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
    }

    for (int i = 1; i < n + 1; i++)
    {
        cnt = 0;
        q.push(i);
        visited_clear();
        visited[i] = true;
        bfs(q.front(), i);
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] == max_value)
        {
            printf("%d ", i);
        }
    }
}
