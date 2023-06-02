#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1368번 문제 접근 방식
->
0번을 우물로 본다.
0번부터 n까지의 mst를 구한다.
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

class mst
{
private:
    int arr[307];
    long long sum = 0;
    int x, y, temp;

public:
    void init()
    {
        for (int i = 0; i < 301; i++)
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

    void execute(vector<info> &v)
    {
        init();
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].v1, v[i].v2))
            {
                sum += v[i].w;
            }
        }

        printf("%lld", sum);
    }
};

int main()
{
    int n;
    int x;
    vector<info> v;

    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &x);
        v.push_back(info{0, i, x});
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            scanf("%d", &x);
            if (j > i)
            {
                v.push_back(info{i, j, x});
            }
        }
    }

    mst mt;
    mt.execute(v);
}
