#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1922번 문제 접근 방식
->
크루스칼 알고리즘, 분리 집합을 이용하여 최소 신장 트리를 구성한다.
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
    vector<info> v;
    long long sum = 0;
public:
    void init()
    {
        for (int i = 1; i < 1001; i++)
        {
            arr[i] = i;
        }
    }

    void input(int idx_1, int idx_2, int w)
    {
        v.push_back(info{idx_1, idx_2, w});
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

    void execute()
    {
        sort(v.begin(), v.end(), compare);

        for (auto e: v)
        {
            if (union_set(e.idx_1, e.idx_2))
            {
                sum += e.w;
            }
        }

        printf("%lld", sum);
    }
};

int main()
{
    mst mt;
    mt.init();

    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    int idx1, idx2, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &idx1, &idx2, &w);
        mt.input(idx1, idx2, w);
    }

    mt.execute();
}
