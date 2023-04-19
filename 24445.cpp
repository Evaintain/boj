#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

/*
24445번 문제 -> 24444문제와 다른점은 '오름차순' 이 아닌 '내림차순'이라는 것.
너비 우선탐색 노드의 방문 순서 출력하기, 인접 정점은 '내림차순'으로 방문
양방향 그래프.

접근 방식
->
vector<pair<가중치, 연결노드 번호>> -> 가중치는 1이라 vector<int>도 무관하다.
불린형 visited
정수형 arr(방문 순서)
Queue (탐색순서) 를 잡아서 BFS를 구현한다.
*/

vector<pair<int, int>> graphs[MAX];
int arr[MAX];
bool visited[MAX];
queue<int> q;
int connect_node, cnt = 1;

void bfs(int now)
{
    arr[now] = cnt++; //탐색하는 순서를 배열에 저장함.
    for (int i = 0; i < graphs[now].size(); i++)
    {
        connect_node = graphs[now][i].second; //연결 노드 번호를 변수에 지정해줌.2
        if (!visited[connect_node])
        {
            visited[connect_node] = true;
            q.push(connect_node);
        }
    }
    q.pop();
    if (q.empty()) return;
    bfs(q.front());
}

int main()
{
    int n, m, r, node1, node2;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &node1, &node2);
        graphs[node1].push_back(make_pair(1, node2));
        graphs[node2].push_back(make_pair(1, node1));
    }

    for (int i = 1; i < n + 1; i++) // 연결 노드를 오름차순으로 정렬함.
    {
        sort(graphs[i].rbegin(), graphs[i].rend());
        //오름차순이면 begin(), end() 내림차순이면 rbegin(), rend()
    }

    q.push(r); // Queue에 시작 정점을 넣어줌.
    visited[r] = true; //시작 정점을 방문함으로 표시
    bfs(q.front()); // 탐색시작
    for (int i = 1; i < n + 1; i++) //정점의 번호는 1부터 시작함.
    {
        printf("%d\n", arr[i]);
    }
}
