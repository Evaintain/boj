#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
16202번 문제 접근 방식
->
mst 찾기. 턴마다 하나씩 지우기.
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

class union_find
{
private:
    int arr[1007];
    int x, y, temp;

public:
    void init()
    {
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
            temp = x;
            x = y;
            y = temp;
        }

        arr[x] = y;

        return true;
    }
};

class mst : union_find
{
private:
    int cnt;
    int ans;
    bool check = true;

public:
    void execute(vector<info> &v, int n, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (!check)
            {
                printf("0 ");
                continue;
            }

            init();
            cnt = 0;
            ans = 0;

            for (int j = 0; j < v.size(); j++)
            {
                if (union_set(v[j].v1, v[j].v2))
                {
                    ans += v[j].w;
                    cnt++;
                }
            }

            if (cnt == n - 1)
            {
                printf("%d ", ans);
            }

            else
            {
                printf("0 ");
                check = false;
            }

            v.erase(v.begin());
        }
    }
};


int main()
{
    int n, m, k;
    int v1, v2;
    vector<info> v;

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i < m + 1; i++)
    {
        scanf("%d %d", &v1, &v2);
        v.push_back(info{v1, v2, i});
    }

    sort(v.begin(), v.end(), compare);

    mst mt;
    mt.execute(v, n, k);
}
