#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
1774번 문제 접근 방식
->
n개 만큼 좌표를 받는다. idx, x, y로 나눠 표시한다.
k개 만큼 좌표를 받는다. idx가 2개 주어지면 그것 끼리 묶는다. 그다음 최소 스패닝 트리 구성
틀린이유 : int형 범위를 벗어날수있는데 int형을 썼다.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int idx;
    int x;
    int y;
};

struct dist
{
    int idx_1;
    int idx_2;
    double _distance;
};

bool compare(dist a, dist b)
{
    return a._distance < b._distance;
}

class mst
{
private:
    int arr[1007];
    vector<info> v;
    vector<dist> dis;
    double sum = 0;
public:
    void init()
    {
        for (int i = 1; i < 1001; i++)
        {
            arr[i] = i;
        }
    }

    void input(int idx, int x, int y)
    {
        v.push_back(info{idx, x, y});
    }

    bool union_set(int x, int y)
    {
        int a = find_set(x);
        int b = find_set(y);

        if (a == b)
        {
            return false;
        }

        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        arr[a] = b;
        return true;
    }

    int find_set(int x)
    {
        if (x == arr[x])
        {
            return x;
        }

        return find_set(arr[x]);
    }

    void make_dist_arr()
    {
        long long _x;
        long long _y;
        for (int i = 1; i < v.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
               _x = v[i].x - v[j].x;
               _y = v[i].y - v[j].y;
               dis.push_back(dist{v[j].idx, v[i].idx, sqrt(_y * _y + _x * _x)});
            }
        }

        sort(dis.begin(), dis.end(), compare);
    }

    void _execute()
    {
        for (int i = 0; i < dis.size(); i++)
        {
            if (union_set(dis[i].idx_1, dis[i].idx_2))
            {
                sum += dis[i]._distance;
            }
        }
        printf("%.2lf", sum);
    }
};

int main()
{
    mst ms;
    ms.init();

    int n, k;
    int x, y;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n ; i++)
    {
        scanf("%d %d", &x, &y);
        ms.input(i + 1, x, y);
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &x, &y);
        ms.union_set(x, y);
    }

    ms.make_dist_arr();
    ms._execute();
}
