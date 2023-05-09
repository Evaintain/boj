#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
1766번 문제

접근 방식
->
위상 정렬후, 처음 시작점을 우선순위로해서 우선순위 큐에 넣음(형태는 int, queue<int>)
우선순위 대로 출력
*/

/*
태그
. 자료 구조
. 우선순위 큐
. 그래프 이론
. 위상 정렬
*/

/*
느낀점
그래프들이 서로 다른게 아닌 다 연결되었을 경우를 생각하는게 너무 구현이 빡셌다.
*/

vector<int> graphs[32007];
int arr[32007];
queue<int> ans;
priority_queue<int, vector<int>, greater<int>> travel_queue;
bool visited[32007];
int n;


void travel(int now_node)
{

    int next_node;

    if (!visited[now_node])
    {
        visited[now_node] = true;
        ans.push(now_node);
    }

    travel_queue.pop();

    for (int i = 0; i < graphs[now_node].size(); i++)
    {
        next_node = graphs[now_node][i];
        arr[next_node]--;
        if (arr[next_node] == 0 && !visited[next_node])
        {
            travel_queue.push(next_node);
        }
    }

    if (travel_queue.empty())
    {
        return;
    }

    travel(travel_queue.top());
}

int main()
{
    int k;
    int node, connect_node;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
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
            travel_queue.push(i);
        }
    }

    int start_node = travel_queue.top();

    travel(start_node);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans.front());
        ans.pop();
    }
}
