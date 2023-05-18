#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
2565번 문제 접근 방식
->
LIS 응용 문제이다.
pair<시작점, 끝점>으로 넣어서 정렬한뒤,
LIS 갯수를 구한다.입력받은 n - LIS 갯수가 정답일 것이다.
*/

/*
태그
. 다이나믹 프로그래밍
*/

vector<pair<int, int>> lines;

int main()
{
    int n;
    int start_point, end_point;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &start_point, &end_point);
        lines.push_back(make_pair(start_point, end_point));
    }

    //정렬
    sort(lines.begin(), lines.end());

    // LIS 배열
    vector<int> lis;
    int idx;

    for (int i = 0; i < n; i++)
    {
        if (lis.empty())
        {
            lis.push_back(lines[i].second);
        }

        else
        {
            if (lis.back() < lines[i].second)
            {
                lis.push_back(lines[i].second);
            }
            else
            {
                 idx = lower_bound(lis.begin(), lis.end(), lines[i].second) - lis.begin();
                 lis[idx] = lines[i].second;
            }
        }
    }

    printf("%d", n - lis.size());
}
