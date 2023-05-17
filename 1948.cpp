#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
1948번 문제

접근 방식
->
위상정렬
탐색 시에 최장거리를 저장한다. 만약 최장거리가 같은경우, 걸어온 도로의 갯수를 더해준다.
시작노드에서의 위상정렬을 해야할것이다.
1회 틀린후 -> 역 bfs로 도로 갯수를 구한다.라는 글을 보고 적용해보았다.
2회 틀린후 -> 일부 반례가 통과가 안된다.
3회 틀린후 -> 위상정렬 역으로 적용.
4회 틀린후 -> 3회차를 지우고 visited적용했다.
5회 틀린후 -> visited를 개선했다.
*/

/*
태그
. 그래프 이론
. 그래프 탐색
. 위상 정렬
*/

/*
느낀점
역으로 bfs를 하며 도로의 갯수를 계산하는 것이 매우 어려웠다.
구글링과 백준의 질문 게시판을 통해서 답을 얻었다.
*/

//연결노드, 가중치
vector<pair<int, int>> graphs[10007];
vector<pair<int, int>> road[10007];

queue<int> q;
queue<int> arr_q;
queue<int> road_q;
queue<int> road_arr_q;

bool added[10007];
bool visited[10007];

int arr[10007];
int ans[10007];

//그래프 탐색 bfs
void travel(int now)
{
    int add_w;
    int node;

    for (auto node : graphs[now])
    {
        arr[node.first]--;
        if (arr[node.first] == 0)
        {
            q.push(node.first);
        }

        if (ans[node.first] < ans[now] + node.second)
        {
            ans[node.first] = ans[now] + node.second;
        }
    }

    q.pop();
    if (q.empty())
    {
        return;
    }
    travel(q.front());
}

void cnt_road(int now, int &cnt)
{
    for (auto node : road[now])
    {
        if (ans[now] - node.second == ans[node.first])
        {
            cnt++;
            if (!visited[node.first])
            {
                visited[node.first] = true;
                road_q.push(node.first);
            }
        }
    }

    road_q.pop();
    if (road_q.empty())
    {
        return;
    }
    cnt_road(road_q.front(), cnt);
}

void make_sorting_arr(int now)
{
    int node;

    for (auto node : graphs[now])
    {
        arr[node.first]++;
        if (!added[node.first])
        {
            added[node.first] = true;
            arr_q.push(node.first);
        }
    }

    arr_q.pop();
    if (arr_q.empty())
    {
        return;
    }
    make_sorting_arr(arr_q.front());
}

int main()
{
    int n;
    int k;
    int sv, ev, w;
    int s, e;
    scanf("%d", &n);
    scanf("%d", &k);

    //그래프 만들기
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &sv, &ev, &w);
        graphs[sv].push_back(make_pair(ev, w));
        road[ev].push_back(make_pair(sv, w));
    }

    //그래프 오름차순 정렬
    for (int i = 1; i < n + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
    }

    scanf("%d %d", &s, &e);
    q.push(s);
    ans[s] = 0;

    //(BFS)위상 정렬할 배열 만들기
    arr_q.push(s);
    make_sorting_arr(arr_q.front());

    //탐색 시작
    int cnt = 0;
    visited[e] = true;
    road_q.push(e);

    travel(q.front());
    cnt_road(road_q.front(), cnt);

    printf("%d\n", ans[e]);
    printf("%d", cnt);
}
