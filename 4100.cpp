#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
4100번 문제 접근 방식
->
n이 0이 아닐때 마다 초기화후(분리집합, x,y 정보가 담긴 vector, 거리와 점 2개가 담긴 vector, 최소값의 합) 최소 연결점을 구한다.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct location
{
    int x;
    int y;
};

struct info
{
    int idx1;
    int idx2;
    double dist;
};

bool compare(info a, info b)
{
    return a.dist < b.dist;
}

class mst
{
public:
    int arr[1007];
    int x;
    int y;
    double sum = 0;

public:
    void init()
    {
        sum = 0;
        for (int i = 1; i < 1001; i++)
        {
            arr[i] = i;
        }
    }

    int find_set(int a)
    {
        if (a == arr[a])
        {
            return a;
        }

        return arr[a] = find_set(arr[a]);
    }

    bool union_set(int a, int b)
    {
        x = find_set(a);
        y = find_set(b);

        if (x == y)
        {
            return false;
        }

        if (x < y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

        arr[x] = y;
        return true;
    }

    void execute(vector<info> &vec)
    {
        init();
        sort(vec.begin(), vec.end(), compare);

        for (int i = 0; i < vec.size(); i++)
        {
            if (union_set(vec[i].idx1, vec[i].idx2))
            {
                sum += vec[i].dist;
            }
        }

        printf("%.2lf\n", sum);
    }
};

int main()
{
    mst mt;
    int n;
    int x, y;
    int _x, _y;
    vector<info> v;
    vector<location> vec;
    while(true)
    {
        v.clear();
        vec.clear();
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            vec.push_back(location{x, y});
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                _x = vec[i].x - vec[j].x;
                _y = vec[i].y - vec[j].y;
                v.push_back(info{j + 1, i + 1, sqrt(_x * _x + _y * _y)});
            }
        }

        mt.execute(v);
    }
}
