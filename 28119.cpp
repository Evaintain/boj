#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
28119번 문제 접근 방식
->
돌아가는 것에는 0분이 걸린다.
그러니까 회의를 할수있는 길을 1부터 n까지 이어주는것이 중요하다.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int idx1;
    int idx2;
    int w;
};

bool compare(info a, info b)
{
    return a.w < b.w;
}

class mst
{
private:
    int arr[2007];
    int sum = 0;
    int x;
    int y;

public:
    void init()
    {
        for (int i = 1; i < 2001; i++)
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

        if (x < y);
        {
            int temp = x;
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
            if (union_set(v[i].idx1, v[i].idx2))
            {
                sum += v[i].w;
            }
        }

        printf("%d", sum);
    }
};

int main()
{
    int n, m, s;
    int v1, v2, w;
    vector<info> v;

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        v.push_back(info{v1, v2, w});
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s);
    }

    mst mt;
    mt.execute(v);
}
