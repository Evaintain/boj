#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
28069번 문제 접근 방식
->
bfs를 통해 구현한다.
정확히 K번째에 도착하는 수,
K번째가 도착하는 수보다 큰경우,
도착하지 못하는 경우를 나눠서 푼다.
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 그래프 탐색
. 너비 우선 탐색
*/

int n;
bool check = false;
queue<pair<int, int>> q;
int visited[1000007];

void bfs(pair<int, int> pair_now)
{
    int now = pair_now.first;
    int num = pair_now.second;

    if (num == 0)
    {
        q.pop();
        if (now == n)
        {
            check = true;
            printf("minigimbob");
            return;
        }

        if (q.empty())
        {
            return;
        }
        bfs(q.front());
    }

    else
    {
        if (now + 1 <= 1e6 && !visited[now + 1])
        {
            visited[now + 1] = true;
            q.push(make_pair(now + 1, num - 1));
        }

        if (now + now / 2 <= 1e6 && !visited[now + now / 2])
        {
            visited[now + now / 2] = true;
            q.push(make_pair(now + now / 2, num - 1));
        }

        q.pop();
        if (q.empty())
        {
            return;
        }
        bfs(q.front());
    }
}


int main()
{
    int k;
    scanf("%d %d", &n, &k);
    visited[0] = true;
    q.push(make_pair(0, k));
    bfs(q.front());
    if (!check && visited[n])
    {
        printf("minigimbob");
    }

    else if (!check)
    {
        printf("water");
    }
}
