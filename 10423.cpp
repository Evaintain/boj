#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
10423번 문제 접근 방식
->
발전소는 0번이랑 이어준다. 가중치는 0으로. 그후 mst를 찾는다.
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
    int arr[1007];
    int sum = 0;
    int x, y, temp;

public:
    void init()
    {
        for (int i = 0; i < 1001; i++)
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

        printf("%d", sum);
    }
};

int main()
{
    mst mt;

    int n, m, s;
    int v1, v2, w;
    vector<info> v;

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &v1);
        v.push_back(info{0, v1, 0});
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        v.push_back(info{v1, v2, w});
    }

    mt.execute(v);
}
