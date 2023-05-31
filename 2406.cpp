#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
2406번 문제 접근 방식
->
mst를 구현하고 어느것이 이어지는지 찾는 문제.
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
    int sum = 0;
    int cnt = 0;
    vector<info> v;
public:
    void init()
    {
        for (int i = 1; i < 1001; i++)
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

        return find_set(arr[x]);
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

    void execute(vector<info> &input)
    {
        for (auto e: input)
        {
            // 본사 컴퓨터의 경우임.
            if (e.idx_1 == 1)
            {
                continue;
            }

            if (union_set(e.idx_1, e.idx_2))
            {
                sum += e.w;
                cnt++;
                v.push_back(info{e.idx_1, e.idx_2, 0});
            }
        }

        printf("%d %d\n", sum, cnt);
        for (int i = 0; i < cnt; i++)
        {
            printf("%d %d\n", v[i].idx_1, v[i].idx_2);
        }
    }
};

int main()
{
    mst mt;
    mt.init();

    int n, k;
    int connect1, connect2;
    int w;
    vector<info> input;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &connect1, &connect2);
        mt.union_set(connect1, connect2);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w);
            if (i < j)
            {
                input.push_back({i + 1, j + 1, w});
            }
        }
    }

    sort(input.begin(), input.end(), compare);

    mt.execute(input);
}
