#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

/*
1005번 문제

접근 방식
->
위상 정렬을 한뒤, 건설시간의 최댓값을 저장함.
3회의 메모리 초과 이후 여러 글을 읽었다.
현상태에서 위상정렬을 구현하지 않은듯..
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 위상 정렬
*/

/*
어려웠던 점
위상 정렬을 하고 안하고의 차이가 메모리초과와 정답을 오가는데, 그것도 모르고 위상정렬 구현한줄알고 올렸다가 계속 틀렸다.
*/

int arr[1007];
int total_build_time[1007];
int time[1007];
queue<int> q;
int n;

void travel(int now, vector<int> graphs[])
{
    int now_time = time[now];
    int next_node;

    total_build_time[now] = max(total_build_time[now], now_time);

    for (int i = 0; i < graphs[now].size(); i++)
    {
        next_node = graphs[now][i];
        arr[next_node]--;
        if (arr[next_node] == 0)
        {
            q.push(next_node);
        }
        total_build_time[next_node] = max(total_build_time[next_node], total_build_time[now] + time[next_node]);
    }
    q.pop();
    if (q.empty())
    {
        return;
    }
    travel(q.front(), graphs);
}

void clear_arr(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        total_build_time[i] = -1;
    }
}

int main()
{
    int tc;
    int k;
    int build_time;
    int v, connect_v;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        vector<int> graphs[1007];
        scanf("%d %d", &n, &k);
        for (int j = 1; j < n + 1; j++)
        {
            scanf("%d", &time[j]);
        }

        for (int j = 0; j < k; j++)
        {
            scanf("%d %d", &v, &connect_v);
            graphs[v].push_back(connect_v);
            arr[connect_v]++;
        }

        for (int j = 1; j < n + 1; j++)
        {
            if (arr[j] == 0)
            {
                q.push(j);
            }
            sort(graphs[j].begin(), graphs[j].end());
        }

        travel(q.front(), graphs);

        int want_node;
        scanf("%d", &want_node);

        printf("%d\n", total_build_time[want_node]);
        clear_arr(n);
    }
}
