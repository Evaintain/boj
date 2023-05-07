#include <iostream>

using namespace std;

/*
10026번 문제

접근 방식
->
dfs를 2번해서 적록색약x 구역 수, 적록색약 o 구역수를 구한다.

입력받을때 R과 G중 하나로 통일한 배열을 만들어서 구역수를 정하는 방법도 있다.
*/

/*
테그
. 그래프 이론
. 그래프 탐색
. 너비 우선 탐색
. 깊이 우선 탐색
*/

/*
느낀점
탐색만 할줄알면 어렵지는 않은 문제, 색약처리 생각을 어떻게 하느냐가 중요
*/

struct location
{
    int x;
    int y;
};

char arr_rgb[107][107];
char arr_rb[107][107];

bool rgb_visited[107][107];
bool rb_visited[107][107];

int see_rgb = 0;
int see_rb = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n;

void travel(int type, location now)
{
    int x = now.x;
    int y = now.y;

    int nx;
    int ny;

    if (type == 0)
    {
        rgb_visited[y][x] = true;
    }

    if (type == 1)
    {
        rb_visited[y][x] = true;
    }

    for (int i = 0; i < 4; i++)
    {
        nx = now.x + dx[i];
        ny = now.y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        {
            continue;
        }

        if (type == 0)
        {
            if (!rgb_visited[ny][nx] && arr_rgb[y][x] == arr_rgb[ny][nx])
            {
                travel(0, location{nx, ny});
            }
        }

        if (type == 1)
        {
            if (!rb_visited[ny][nx] && arr_rb[y][x] == arr_rb[ny][nx])
            {
                travel(1, location{nx, ny});
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &arr_rgb[i][j]);

            if (arr_rgb[i][j] == '\n')
            {
                j--;
                continue;
            }

            if (arr_rgb[i][j] == 'G')
            {
                arr_rb[i][j] = 'R';
            }
            else
            {
                arr_rb[i][j] = arr_rgb[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!rgb_visited[i][j])
            {
                see_rgb++;
                travel(0, location{j, i});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!rb_visited[i][j])
            {
                see_rb++;
                travel(1, location{j, i});
            }
        }
    }

    printf("%d %d", see_rgb, see_rb);
}
