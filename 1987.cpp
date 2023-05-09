#include <iostream>

using namespace std;

/*
1987번 문제

접근 방식
->
깊이우선 탐색으로 가장 긴 길이를 구한다.
*/

/*
태그
. 그래프 이론
. 그래프 탐색
. 깊이 우선 탐색
. 백트래킹
*/

/*
생각
처음에 cnt랑 result 올려줘야 처음부터 계산한 셈이 된다.
시간이 452ms 가 걸렸다. 아마 모든 경우의수를 다 탐색해서 그런듯.
*/

struct location
{
    int x;
    int y;
};

char board[27][27];
bool visited[27][27];
int alphabet[27];
int n, m;
int cnt = 0;
int result = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(location now)
{
    int x = now.x;
    int y = now.y;

    int nx;
    int ny;

    char next_alpha;

    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        {
            continue;
        }

        next_alpha = board[ny][nx] - 'A';

        if (!visited[ny][nx] && alphabet[next_alpha] == 0)
        {
            visited[ny][nx] = true;
            alphabet[next_alpha]++;
            cnt++;
            if (cnt > result)
            {
                result = cnt;
            }
            dfs(location{nx, ny});
            cnt--;
            alphabet[next_alpha]--;
            visited[ny][nx] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    //보드 입력받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &board[i][j]);
            if (board[i][j] == '\n')
            {
                j--;
            }
        }
    }

    char start_alpha = board[0][0] - 'A';
    alphabet[start_alpha]++;
    cnt++;
    result++;
    dfs(location{0, 0});

    printf("%d", result);
}
