#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
25511번 문제

접근 방식
->
그래프 구현(인접 리스트) K번째 정점의 깊이 구하기 -> bfs 구현
*/

/*
조건
2 ≤ n ≤ 100,000
0 ≤ k ≤ n - 1
0 ≤ p, c ≤ n - 1, p ≠ c
간선들로 만들어진 그래프는 트리이다.
0 ≤ 정점에 부여된 값 ≤ n - 1
각 정점에 부여된 값은 서로 다른 정수이다.
*/

/*
태그
. 그래프 이론
. 그래프 탐색
. 트리
*/

vector<int> graphs[100007];
int arr[100007];
int order_arr[100007];
bool visited[100007];
queue<int> order;

void bfs(int now)
{
    int next_node;
    for (int i = 0; i < graphs[now].size(); i++)
    {
        next_node = graphs[now][i];
        if (!visited[next_node])
        {
            visited[next_node] = true;
            order.push(next_node);
            arr[next_node] = arr[now] + 1;
        }
    }
    order.pop();
    if (order.empty()) return;
    bfs(order.front());
}

int main()
{
    int order_num;
    int node, connect_node;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) //그래프 연결
    {
        scanf("%d %d", &node, &connect_node);
        graphs[node].push_back(connect_node);
        graphs[connect_node].push_back(node);
    }

    for (int i = 0; i < n; i++) //정점에 값 할당
    {
        scanf("%d", &order_num);
        order_arr[order_num] = i;
    }

    order.push(0);
    visited[0] = true;
    arr[0] = 0;
    bfs(order.front()); //탐색 시작
    printf("%d", arr[order_arr[k]]);
}

/*
느낀점
트리를 구현하고 정점값을 할당하는것을 잘생각해야 풀수있는문제.
bfs로 구현해서 실행시간이 조금 걸린거같다. (76ms)
*/
