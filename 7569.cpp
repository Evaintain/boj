#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
7569번 문제

접근 방식
->
7576번에서 N과 M의 범위가 줄고 H(높이)가 생긴 케이스이다 3차원 bfs를 해보자.
*/

/*
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다.
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 
둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
이러한 N개의 줄이 H번 반복하여 주어진다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.
*/

/*
태그
. 그래프 이론
. 그래프 탐색
. 너비 우선 탐색
*/

/*
느낀점
3차원 구현이 생각보다 어려웠다;;
*/

struct location
{
    int x;
    int y;
    int z;
};

//x -> 가로 | y -> 세로 | z -> 높이로 가정하고 시작

int arr[107][107][107]; //높이 / 세로 / 가로
int tomato_cnt = 0;
int n, m, h;
int cnt = 0;
int cnt_days = 0;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<location> tomato;

void bfs(location now)
{
    int x = now.x;
    int y = now.y;
    int z = now.z;

    int nx;
    int ny;
    int nz;

    for (int i = 0; i < 6; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        nz = z + dz[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h)
        {
            continue;
        }


        if (arr[nz][ny][nx] == 0)
        {
            tomato_cnt++;
            arr[nz][ny][nx] = arr[z][y][x] + 1;
            tomato.push(location{nx, ny, nz});
            if (arr[nz][ny][nx] > cnt_days)
            {
                cnt_days = arr[nz][ny][nx] - 1;
            }
        }
    }

    tomato.pop();
    if (tomato.empty())
    {
        return;
    }
    bfs(tomato.front());
}

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    cnt = n * m * h;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &arr[k][i][j]);

                if (arr[k][i][j] == 1)
                {
                    tomato.push(location{j, i, k}); //x = i, y = j, h = k
                    tomato_cnt++;
                }
                if (arr[k][i][j] == -1)
                {
                    cnt--;
                }
            }
        }
    }

    if (tomato_cnt == 0) //익은 토마토가 없는경우 -> 같은 오류가 난 질문게시판 참조
    {
        printf("-1");
        return 0;
    }

    bfs(tomato.front());

    if (tomato_cnt == cnt)
    {
        printf("%d", cnt_days);
    }
    else
    {
        printf("-1");
    }
}
