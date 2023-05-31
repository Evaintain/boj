#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
10723번 문제 접근 방식
->
mst, 도로가 추가될때마다 mst를 시작한다. -> 그래서 시간제한이 20초다..
틀린이유 : 4바이트 정수형 초과를 생각하지 못했다.
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
    long long ans = 0;
    long long result = 0;
    int arr[2007];
    vector<info> v;
    bool check = true;
public:
    void init()
    {
        v.clear();
        result = 0;

        for (int i = 0; i < 2001; i++)
        {
            arr[i] = i;
        }
    }

    void forced_init()
    {
        init();
        check = true;
        ans = 0;
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
            if (union_set(e.idx_1, e.idx_2))
            {
                if (check)
                {
                    ans += e.w;
                }

                result += e.w;
            }
        }

        if (check)
        {
            check = false;
            return;
        }

        ans ^= result;
    }

    void print()
    {
        printf("%lld\n", ans);
    }
};

int main()
{
    mst mt;

    int tc;
    int n, m;
    int idx1, idx2, w;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        mt.forced_init();
        vector<info> input;
        scanf("%d %d", &n, &m);
        for (int i = 1; i < n; i++)
        {
            scanf("%d %d", &idx2, &w);
            input.push_back({i, idx2, w});
        }

        for (int i = 0; i < m; i++)
        {
            mt.init();
            scanf("%d %d %d", &idx1, &idx2, &w);
            input.push_back({idx1, idx2, w});
            sort(input.begin(), input.end(), compare);
            mt.execute(input);
        }
        mt.print();
    }
}
