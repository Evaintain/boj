#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
16398번 문제 접근 방식
->
i = 0 j = 0 시작
i < j 일때만 입력받을것.

그후 mst 만들기
간선 최대 비용이 1억이므로 64비트 정수형 쓸것.
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
    long long sum = 0;

public:
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

        printf("%lld", sum);
    }
};

int main()
{
    int n;
    int w;
    vector<info> v;

    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            scanf("%d", &w);
            if (i < j)
            {
                v.push_back(info{i, j, w});
            }
        }
    }

    mst mt;
    mt.execute(v);
}
