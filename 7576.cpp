#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
7576번 문제

접근 방식
->
n * m 만큼의 토마토를 받는 배열이 있음(최대갯수 n * m)
-1 가 나올 때마다 최대갯수 -1 연산
1이 나오는 만큼 토마토 갯수 세기
최대갯수 != 토마토 갯수일 경우 -1 출력
아닐시 일자 출력
1회 틀림(segfault) -> 토마토가 하나이상 있는데 '익은' 토마토라는 보장이 없다는 것을 생각하지 못함
*/

/*
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. 
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
단, 2 ≤ M,N ≤ 1,000 이다. 
둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 
하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

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
다 짜두고 마지막 반례 하나를 찾지 못했었다. '익은' 토마토라는 보장이 없었는데;
*/

int arr[1007][1007];
int tomato_cnt = 0;
int n, m;
int cnt = 0;
int cnt_days = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> tomato;

void bfs(pair<int, int> now)
{
    int x = now.second;
    int y = now.first;

    for (int i = 0; i < 4; i++)
    {
        if (y + dy[i] < 0 || y + dy[i] >= n || x + dx[i] < 0 || x + dx[i] >= m)
        {
            continue;
        }


        if (arr[y + dy[i]][x + dx[i]] == 0)
        {

            tomato_cnt++;
            arr[y + dy[i]][x + dx[i]] = arr[y][x] + 1;
            tomato.push(make_pair(y + dy[i], x + dx[i]));
            if (arr[y + dy[i]][x + dx[i]] > cnt_days)
            {
                cnt_days = arr[y + dy[i]][x + dx[i]] - 1;
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
    scanf("%d %d", &m, &n);
    cnt = n * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                tomato.push(make_pair(i, j));
                tomato_cnt++;
            }
            if (arr[i][j] == -1)
            {
                cnt--;
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
