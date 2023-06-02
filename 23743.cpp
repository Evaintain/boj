#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
23743번 문제 접근 방식
->
분리집합으로 묶을때, 워프 설치 최솟값으로 초기화 하여야한다.
구글링을 통해서 0번 간선을 방밖으로 가정한다라는 풀이를 보고, 내 코드를 고쳤다.
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

int arr[200007];

class mst
{
private:
    long long sum = 0;
    int x, y, temp;

public:
    void init()
    {
        for (int i = 0; i < 200001; i++)
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

    void execute(vector<info> &v, int n)
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
    int n, m;
    int v1, v2, w;
    vector<info> v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        v.push_back(info{v1, v2, w});
    }

    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &w);
        v.push_back(info{0, i, w});
    }

    mst mt;
    mt.execute(v, n);
}
