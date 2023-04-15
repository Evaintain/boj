#include <bits/stdc++.h>
#define MAX 2100000000

using namespace std;

/*
1916문제 그래프 주어짐. 시작도시, 끝 도시 주어짐. 최소비용구하기 (다익스트라 알고리즘)

접근방식
->
문제에서 유향그래프라고 함. 그래프탐색을 하면서 Start -> End의 최소 비용을 갱신하며 답을 찾을것.
BFS로 탐색을 할거기에, 불린형 배열을 잡아줄것임. -> 계속 반복해서 닿아야 하니 불린형이 필요없음.(1회 디버깅)
정수형 배열을 잡아서 시작점을 0으로 잡고 가중치를 더해줘야 할듯함.
그리고 들리지않은 곳들은 무조건 21억으로 값을 정해줌.

1회 틀린후 -> BFS는 무슨. 그냥 정점을 싹다 탐색하는게 맞음.
2회 틀린후 -> 문제 이거 유향그래프가 아닌가? -> 유향 맞는거 같음
3회 틀린후 -> 다익스트라에 대해서 보고, 우선순위 큐를 이용해서 노드를 짤거임.
틀린 이유가 1 부터 n까지의 정점을 차례대로 돌았기 때문에 틀렸을거로 추정.
노드가 이어진것끼리 가중치가 작은거부터 돌겠음.
불린형이 필요없다했는데 필요할듯.
4회 틀린후 -> 메모리 초과임 뭐가 문제일까?
5,6회 틀린후 -> 글을 찾아보았다.
1753번 질문 답변에 있는 '무조건 우선순위 큐에 다 넣는 게 아니라 거리가 갱신될 때만 거리를 갱신하고 넣어야 합니다.'
7회 틀린후 -> 이번엔 시간초과다.
질문게시판의 힘을 빌려보니 '먼저 산입된 더 먼 경로의 정점은 탐색을 시작하지 않아야 합니다.',
'같은 경로지만 비용이 다른 경로가 존재합니다. 이 경우를 처리해주셔야 합니다'
이것들을 처리해야 할 것이다.
*/

int price[1007];
bool visited[1007];
vector<pair<int, int>> graphs[1007]; //vector<pair<가중치, 연결노드번호>>
queue<int> travel_queue;
int num, add_value;

void travel(int now)
{
    visited[now] = true;
    for (int i = 0; i < graphs[now].size(); i++)
    {
        num = graphs[now][i].second;
        add_value = graphs[now][i].first;
        if (add_value < price[num]) //6회 오답후 추가점. 지금 최솟값 보다 가중치가 낮아야 큐에 들어갈수 있음.
        {
            if (price[now] + add_value < price[num]) //7회 오답후 추가점. 지금 최솟값보다 가중치 + 현재까지의 노드거리가 더 작아야 큐에 들어갈 수 있음. -> 추가시 정답.
            {
                travel_queue.push(num);
                price[num] = price[now] + add_value;
            }
        }
    }
    travel_queue.pop();
    if (travel_queue.empty()) return;
    travel(travel_queue.front());
}

int main()
{
    for (int i = 0; i < 1007; i++) price[i] = MAX;
    int v, e, v1, v2, w;
    int sv, ev;
    scanf("%d", &v);
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        graphs[v1].push_back(make_pair(w, v2));
    }
    for (int i = 1; i < v + 1; i++)
    {
        sort(graphs[i].begin(), graphs[i].end());
    }
    scanf("%d %d", &sv, &ev);
    price[sv] = 0; //시작 지점은 비용이 0
    travel_queue.push(sv); //시작 지점을 큐에 넣어준다.
    travel(travel_queue.front());
    printf("%d", price[ev]);
}