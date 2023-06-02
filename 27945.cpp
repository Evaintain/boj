#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
27945번 문제 접근 방식
->
노점을 여는날기준 정렬, 만약 간선이 서로 연결이 안되어 있고,
노점을 여는날이 세고있는 날과 같다면 이라면 간선 연결후 + 1, 아닐시 break하고 날짜 출력.
*/

/*
태그
. 자료 구조
. 그래프 이론
. 그리디 알고리즘
. 분리 집합
. 최소 스패닝 트리
*/

struct info
{
    int v1;
    int v2;
    int day;
};

bool compare(info a, info b)
{
    return a.day < b.day;
}

int arr[100007];

class mst
{
private:
    int days = 1;
    int x, y;

public:
    void init()
    {
        for (int i = 1; i < 100001; i++)
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
            int temp = x;
            x = y;
            y = temp;
        }

        arr[x] = y;

        return true;
    }

    void execute(vector<info> &vec)
    {
        init();
        sort(vec.begin(), vec.end(), compare);

        for (int i = 0; i < vec.size(); i++)
        {
            if (union_set(vec[i].v1, vec[i].v2) && vec[i].day == days)
            {
                days++;
            }
            else
            {
                break;
            }
        }
        printf("%d", days);
    }
};

int main()
{
    vector<info> v;
    int n, m;
    int v1, v2, day;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &day);
        v.push_back(info{v1, v2, day});
    }

    mst mt;
    mt.execute(v);
}
