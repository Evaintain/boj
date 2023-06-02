#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
1516번 문제 접근 방식
->
위상 정렬이다. 그 후에 위상정렬 순서대로 걸리는 시간을 만든후 차례대로 출력한다.
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 위상 정렬
*/

class topological_sorting
{
private:
    int arr[507];
    int time[507];
    int total_time[507];
    vector<int> graphs[507];
    queue<int> q;

public:
    void init()
    {
        for (int i = 1; i < 501; i++)
        {
            arr[i] = 0;
        }
    }

    void time_init(int a, int b)
    {
        time[a] = b;
        total_time[a] = b;
    }

    void input(int a, int b)
    {
        graphs[b].push_back(a);
        arr[a]++;
    }

    void order(int n)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (arr[i] == 0)
            {
                q.push(i);
            }
        }
    }


    void bfs(int now)
    {
        for (int e: graphs[now])
        {
            total_time[e] = max(total_time[e], total_time[now] + time[e]);
            arr[e]--;
            if (arr[e] == 0)
            {
                q.push(e);
            }
        }

        q.pop();
        if (q.empty())
        {
            return;
        }
        bfs(q.front());
    }

    void execute(int n)
    {
        order(n);
        bfs(q.front());

        for (int i = 1; i < n + 1; i++)
        {
            printf("%d\n", total_time[i]);
        }
    }
};

int main()
{
    topological_sorting ts;
    ts.init();

    int n;
    int time;
    int node;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time);
        ts.time_init(i + 1, time);
        while(true)
        {
            scanf("%d", &node);
            if (node == -1)
            {
                break;
            }
            ts.input(i + 1, node);
        }
    }

    ts.execute(n);
}
