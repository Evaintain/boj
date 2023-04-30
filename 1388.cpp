#include <iostream>

using namespace std;

/*
1338번 문제

접근 방식
->
bool visited 2차원 배열을 만든다.
-를 만날경우 y좌표를 증가시키며 | 를 만나기 전까지 또는 끝까지 가기 전까지 visited -> true 를 해준다.
|를 만날경우 x좌표를 증가시키며 - 를 만나기 전까지 또는 끝까지 가기 전까지 visited -> true 를 해준다.
*/

/*
조건
n, m (행 렬)이 주어진다, 단 50이하의 자연수이다
그 아랫줄에는 n * m 만큼의 바닥 무늬가 주어짐
*/

/*
태그
. 구현
. 그래프 이론
. 그래프 탐색
. 깊이 우선 탐색
*/

bool visited[57][57];
char arr[57][57];
int n, m;

void dfs(int x ,int y)
{
    visited[y][x] = true;
    if (x == m || y == n)
    {
        return;
    }
    if (arr[y][x] == '|' && arr[y][x] == arr[y + 1][x])
    {
        dfs(x, y + 1);
    }
    if (arr[y][x] == '-' && arr[y][x] == arr[y][x + 1])
    {
        dfs(x + 1,y);
    }
    return;
}

int main()
{
    int cnt = 0;
    char in_arr;
    scanf("%d %d",&n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &in_arr);
            if (in_arr == '\n')
            {
                j--;
            }
            else
            {
                arr[i][j] = in_arr;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                cnt++;
                dfs(j, i);
            }
        }
    }
    printf("%d", cnt);
}

/*
느낀점
아직도 행과 열이 헷갈린다.
*/
