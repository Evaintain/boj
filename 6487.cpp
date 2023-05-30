#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
6487번 문제 접근 방식
->
mst문제이다. 크루스칼 알고리즘을 이용한다. + 분리집합으로 연결을 확인한다.
모든 값의 합 - 최솟값 = 절약할수 있는 값임을 유의하고 문제를 풀어야한다.
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
    int dist;
};

bool compare(info a, info b)
{
    return a.dist < b.dist;
}

int arr[200007];

class mst
{
private:
    vector<info> v;
    long long sum = 0;

public:
    void init()
    {
        v.clear();
        sum = 0;

        for (int i = 1; i < 200001; i++)
        {
            arr[i] = i;
        }
    }

    void input(int idx_1, int idx_2, int dist)
    {
        v.push_back(info{idx_1, idx_2, dist});
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

    int find_set(int x)
    {
        if (x == arr[x])
        {
            return x;
        }

        return find_set(arr[x]);
    }

    void execute(long long total)
    {
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].idx_1, v[i].idx_2))
            {
                sum += v[i].dist;
            }
        }

        printf("%lld\n", total - sum);
        v.clear();
    }
};

int main()
{
    mst ms;
    int m;
    int n;
    int idx1, idx2, meter;
    long long total;

    while (true)
    {
        total = 0;
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
        {
            break;
        }

        ms.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &idx1, &idx2, &meter);
            ms.input(idx1, idx2, meter);
            total += meter;
        }
        ms.execute(total);
    }
}
