#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
21924번 문제 접근 방식
->
총값 - mst트리 값
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int v1;
    int v2;
    int w;
};

bool compare(info a, info b)
{
    return a.w < b.w;
}

int arr[100007];

class uf
{
private:
    int x, y, temp;

public:
    void init()
    {
        for (int i = 1; i < 100001; i++)
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
            temp = x;
            x = y;
            y = temp;
        }

        arr[x] = y;

        return true;
    }
};

class mst : uf
{
private:
    long long cnt = 0;
    int connect = 0;

public:
    void execute(vector<info> &v, long long total, int n)
    {
        init();
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].v1, v[i].v2))
            {
                connect++;
                cnt += v[i].w;
            }
        }

        if (connect + 1 != n)
        {
            printf("-1");
            return;
        }

        printf("%lld", total - cnt);
    }
};

int main()
{
    int n, m;
    long long total = 0;
    int v1, v2, w;
    vector<info> v;
    mst mt;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        total += w;
        v.push_back(info{v1, v2, w});
    }

    mt.execute(v, total, n);
}
