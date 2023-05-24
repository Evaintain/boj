#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1647번 문제 접근 방식
->
가중치가 가장 적은 간선부터 이동한다.
간선의 개수가 정점의 개수 - 1 이라면,
간선중 최댓값을 제외한 나머지를 더한다.
( = 다 더하고 최댓값을 뺀다.)
간선끼리의 연결은 분리 집합으로 표현한다.
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
int arr[100007];

void init_arr()
{
    for (int i = 1; i < 100001; i++)
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
    
  // 이렇게 안하면 시간초과 남
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
    init_arr();
    int n, k;
    int sv, ev, w;
    vector<int> ans;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &sv, &ev, &w);
        v.push_back({sv, ev, w});
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < k; i++)
    {
        if (union_set(v[i].sv, v[i].ev))
        {
            ans.push_back(v[i].w);
        }

        if (ans.size() == n - 1)
        {
            break;
        }
    }

    int max_value = 0;
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum += ans[i];
        max_value = max(max_value, ans[i]);
    }

    printf("%d", sum - max_value);
}
