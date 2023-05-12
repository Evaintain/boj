#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1007

using namespace std;

/*
2623번 문제

접근 방식
->
위상정렬, bfs로 탐색할때 연결된 노드의 가르키는 수를 -1 한다.
그때 0이 될시 queue에 넣는다.
만약 가수의 수가 정답vector의 수와 같지 않다면 0이다.
같다면 순서대로 출력(우선순위가 존재하지않으므로 큐를 써도 된다)
*/

/*
태그
. 그래프 이론
. 위상정렬
*/

/*
느낀점
입력 받아서 그래프 끼리 연결하는 것만 구현하고, 위상정렬에 대한 지식이 있다면 풀수있는 문제.
*/

vector<int> graphs[MAX];
queue<int> q;
vector<int> ans;
int arr[MAX];

void bfs(int now)
{
    ans.push_back(now);
    int next_node;
    for (int i = 0; i < graphs[now].size(); i++)
    {
        next_node = graphs[now][i];
        arr[next_node]--;
        if (arr[next_node] == 0)
        {
            q.push(next_node);
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
    int order;
    int temp = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        node = connect_node = 0;
        scanf("%d", &order);
        for (int j = 0; j < order; j++)
        {
            scanf("%d", &temp);
            if (node == 0)
            {
                node = temp;
            }
            else if (connect_node == 0)
            {
                connect_node = temp;
            }

            if (connect_node != 0)
            {
                arr[connect_node]++;
                graphs[node].push_back(connect_node);
                node = connect_node;
                connect_node = 0;
            }
        }
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

    if (n != ans.size())
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
}
