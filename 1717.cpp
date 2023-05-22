#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
1717번 문제 접근 방식
->
union - find를 구현한다.
*/

/*
태그
. 자료 구조
. 분리 집합
*/

int arr[1000007];

int find_set(int x)
{
    if (x == arr[x])
    {
        return x;
    }

    arr[x] = find_set(arr[x]);
    return arr[x];
}

void union_set(int a, int b)
{
    int x = find_set(a);
    int y = find_set(b);

    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    if (x == y)
    {
        return;
    }
    else
    {
        arr[x] = y;
    }
}

int main()
{
    // 각자가 루트노드를 갖게 초기화 한다.

    for (int i = 1; i < 1000001; i++)
    {
        arr[i] = i;
    }

    int n, m;
    int order, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &order, &a, &b);
        if (order == 1)
        {
            if (find_set(a) == find_set(b))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            union_set(a, b);
        }
    }
}
