#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
13418번 문제 접근 방식
->
최대 스패닝 트리
최소 스패닝 트리 구한다.
0 -> +1
1 -> 그대로

주어진 정점 - cnt -> 최소, 최대를 구함.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int idx_1;
    int idx_2;
    int road;
};

bool compare(info a, info b)
{
    return a.road < b.road;
}

bool rcompare(info a, info b)
{
    return a.road > b.road;
}

class mst
{
private:
    int arr[1007];
    int max_cnt = 0;
    int min_cnt = 0;
public:
    void init()
    {
        for (int i = 0; i < 1001; i++)
        {
            arr[i] = i;
        }
    }

    bool union_set(int a, int b)
    {
        int x = find_set(a);
        int y = find_set(b);

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

    int find_set(int x)
    {
        if (x == arr[x])
        {
            return x;
        }

        return find_set(arr[x]);
    }

    void sorting(vector<info> &v, int type = 0)
    {
        if (type == 1)
        {
            sort(v.begin(), v.end(), compare);
        }

        else
        {
            sort(v.begin(), v.end(), rcompare);
        }
    }

    void execute(vector<info> &v)
    {
        init();
        sorting(v, 1);
        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].idx_1, v[i].idx_2))
            {
                if (v[i].road == 0)
                {
                    max_cnt++;
                }
            }
        }

        init();
        sorting(v);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].idx_1, v[i].idx_2))
            {
                if (v[i].road == 0)
                {
                    min_cnt++;
                }
            }
        }

        printf("%d", max_cnt * max_cnt - min_cnt * min_cnt);
    }
};

int main()
{
    int n, m;
    int idx1, idx2, road;
    vector<info> v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m + 1; i++)
    {
        scanf("%d %d %d", &idx1, &idx2, &road);
        v.push_back({idx1, idx2, road});
    }

    mst mt;
    mt.execute(v);
}
