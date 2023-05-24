#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1197번 문제 접근 방식
->
가장 가중치가 적은 간선부터 시작.
분리 집합으로 표현했을때 사이클이 만들어 진다면, 포함하지 않을것.
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
    int w;
};

bool compare(info a, info b)
{
    return a.w < b.w;
}

vector<info> v;

int arr[10007];

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

int main()
{
    // 분리 집합 초기화
    for (int i = 1; i < 10001; i++)
    {
        arr[i] = i;
    }

    int n, k;
    int start_v, end_v, add_value;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &start_v, &end_v, &add_value);
        v.push_back({start_v, end_v, add_value});
    }

    sort(v.begin(), v.end(), compare);

    int min_value = 0;

    for (int i = 0; i < k; i++)
    {
        if(union_set(v[i].sv, v[i].ev))
        {
            min_value += v[i].w;
        }
    }

    printf("%d", min_value);
}
