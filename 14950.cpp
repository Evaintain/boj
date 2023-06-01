#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
14950번 문제 접근 방식
->
mst 구현 도로 가중치를 더할때마다, 추가 가중치를 더해주어야한다.
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
    int add_value = 0;
    int sum = 0;
    int arr[10007];
public:
    void init()
    {
        for (int i = 1; i < 10001; i++)
        {
            arr[i] = i;
        }
    }

    int find_set(int x)
    {
        if (x == arr[x])
        {
            return x;
        }

        return arr[x] = find_set(arr[x]);
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

    void execute(vector<info> &v, int add)
    {
        init();
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].idx1, v[i].idx2))
            {
                sum += (v[i].w + add_value);
                add_value += add;
            }
        }

        printf("%d", sum);
    }
};

int main()
{
    int n, m, add;
    vector<info> v;
    int idx1, idx2, w;
    scanf("%d %d %d", &n, &m, &add);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &idx1, &idx2, &w);
        v.push_back(info{idx1, idx2, w});
    }

    mst mt;
    mt.execute(v, add);
}
