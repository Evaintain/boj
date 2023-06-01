#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
14621번 문제 접근 방식
->
mst를 구현한다. 주의점은 M, W 을 엮어야 하며, 간선이 n - 1개가 아닐경우 -1이다.
간선을 입력 받을때 M M, W W를 연결하는건 싹다 쳐내면 된다.
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
    int cnt = 0;
    int sum = 0;
    int arr[1007];

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

        return arr[x] = find_set(arr[x]);
    }

    bool union_set(int x, int y)
    {
        int a = find_set(x);
        int b = find_set(y);

        if (a == b)
        {
            return false;
        }

        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        arr[a] = b;

        return true;
    }

    void execute(vector<info> &v, int n)
    {
        sort(v.begin(), v.end(), compare);
        for (auto e: v)
        {
            if (union_set(e.idx_1, e.idx_2))
            {
                cnt++;
                sum += e.w;
            }
        }

        if (n - 1 == cnt)
        {
            printf("%d", sum);
        }

        else
        {
            printf("-1");
        }
    }
};

int main()
{
    int n, m;
    int u, v, d;
    char gender[1007];
    char input;
    vector<info> vec;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &gender[i + 1]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &d);
        if (gender[u] != gender[v])
        {
            vec.push_back(info{u, v, d});
        }
    }

    mst mt;
    mt.init();
    mt.execute(vec, n);
}
