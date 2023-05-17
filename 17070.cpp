#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
17070번 문제 접근 방식
->
이동 할 수 있는 경우의수, 그중 도달 가능한 수만 따져서 검색한다.
*/

/*
태그
. 다이나믹 프로그래밍
. 그래프 이론
. 그래프 탐색
*/

int arr[17][17];
int ans[17][17];

struct location
{
    int x;
    int y;
    int type;
};

int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

queue<location> q;
int n;

void bfs(location now)
{
    int x = now.x;
    int y = now.y;
    int type = now.type;
    q.pop();

    int nx;
    int ny;
    bool check = true;
    bool type_check = true;

    for (int i = 0; i < 3; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= n || ny >= n)
        {
            check = false;
            break;
        }

        if (arr[ny][nx] == 1)
        {
            check = false;
            break;
        }
    }

    if (check)
    {
        ans[y + 1][x + 1]++;
        q.push({x + 1, y + 1, 3});
    }

    if (type == 1 || type == 2)
    {
        nx = x + dx[type - 1];
        ny = y + dy[type - 1];
        if (nx >= n || ny >= n)
        {
            type_check = false;
        }

        if (type_check && arr[ny][nx] == 0)
        {
            ans[ny][nx]++;
            q.push({nx, ny, type});
        }
    }

    if (type == 3)
    {
        for (int i = 0; i < 2; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= n || ny >= n)
            {
                continue;
            }

            if (arr[ny][nx] == 0)
            {
                ans[ny][nx]++;
                q.push({nx, ny, i + 1});
            }
        }
    }

    if (q.empty())
    {
        return;
    }

    bfs(q.front());
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // 머리부분만 넣어준다.
    q.push({1, 0, 1});
    bfs(q.front());

    printf("%d", ans[n - 1][n - 1]);
}
