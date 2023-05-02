#include <iostream>

using namespace std;

/*
1012번 문제

접근 방식
->
정수형 배열을 잡고 1과 0로 가야하는지 아닌지를 따진뒤 dfs의 호출 수만큼을 출력.
*/

/*
조건
n, m, k가 주어진 n, k 는 50이하 자연수 | k는 2500이하 자연수
*/

int arr[57][57];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

void dfs(int x, int y)
{
    if (x == m || y == n || x < 0 || y < 0)
    {
        return;
    }
    arr[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[y + dy[i]][x + dx[i]])
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
    return;
}

int main()
{
    int tc, k, in_x, in_y, cnt = 0;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        cnt = 0;
        scanf("%d %d %d", &m, &n, &k);
        for (int j = 0; j < k; j++) //k번 동안 배추위치 입력하는 함수
        {
            scanf("%d %d", &in_x, &in_y);
            arr[in_y][in_x] = 1;
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (arr[y][x] == 1)
                {
                    cnt++;
                    dfs(x, y);
                }
            }
        }
        printf("%d\n", cnt);
    }
}
