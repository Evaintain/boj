#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
4386번 문제 접근 방식
->
입력을 받고
for i = 1 -> n
for j = 0 -> i
를 하여 간선을 만든다.
만든 간선을 가중치 순으로 정렬한다.
분리 집합을 이용하여 연결이 되어있는지 판단후 안되어있다면,
간선을 적용한다.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int sv;
    int ev;
    double w;
};

struct location
{
    double x;
    double y;
};

bool compare(info a, info b)
{
    return a.w < b.w;
}

vector<info> v;
vector<location> dot;

class union_find
{
private:
    int arr[107];
public:
    void init()
    {
        for (int i = 1; i < 101; i++)
        {
            arr[i] = i;
        }
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
};

int main()
{
    union_find uf;
    uf.init();

    int n;
    double sum = 0;
    double x, y;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &y);
        dot.push_back({x, y});
    }

    double len_x, len_y;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            len_x = dot[i].x - dot[j].x;
            len_y = dot[i].y - dot[j].y;
            v.push_back({j + 1, i + 1, sqrt(len_x * len_x + len_y * len_y)});
        }
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        if (uf.union_set(v[i].sv, v[i].ev))
        {
            sum += v[i].w;
        }
    }

    printf("%.2lf", sum);
}
