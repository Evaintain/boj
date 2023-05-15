#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
2056번 문제

접근 방식
->
위상 정렬, bfs를 하며 최댓값 갱신 + 연결노드의 간선 지우기
연결노드의 간선갯수가 0이되면 큐에 넣고 탐색
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론 -> 이걸로 품
. 위상 정렬 -> 이걸로 품
*/

/*
느낀점
ACM CRAFT를 풀고난 후에 이 문제를 풀어서 편했다. DP로 접근하는 방식으로도 짜봐야 할듯하다.
*/

vector<int> graphs[10007];
queue<int> now_q;
int edge[10007];
int add_value[10007];
int sum_value[10007];
int time = 0;

void bfs(int now)
{
    sum_value[now] = max(sum_value[now], add_value[now]);
    if (time < sum_value[now])
    {
        time = sum_value[now];
    }

    int connect_v;
    for (int i = 0; i < graphs[now].size(); i++)
    {
        connect_v = graphs[now][i];
        sum_value[connect_v] = max(sum_value[connect_v], sum_value[now] + add_value[connect_v]);

        edge[connect_v]--;
        if (edge[connect_v] == 0)
        {
            now_q.push(connect_v);
        }
    }

    now_q.pop();
    if (now_q.empty())
    {
        return;
    }
    bfs(now_q.front());
}

int main()
{
    int n;
    int input_add_value;
    int connect_node_count;
    int connect_node;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &input_add_value);
        add_value[i] = input_add_value;
        scanf("%d", &connect_node_count);
        if (connect_node_count == 0)
        {
            now_q.push(i);
        }
        else
        {
            for (int j = 0; j < connect_node_count; j++)
            {
                scanf("%d", &connect_node);
                edge[i]++;
                graphs[connect_node].push_back(i);
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
    }

    bfs(now_q.front());

    printf("%d", time);
}
