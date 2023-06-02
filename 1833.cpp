#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
1833번 문제 접근 방식
->
n * n에서 나올수 있는 가짓수
(n * n - n)(자기 자신) / 2 그중 이미 연결된거 제외 하고 mst 돌리기
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트리
*/

struct info
{
    int idx1;
    int idx2;
    int w;
};

bool compare(info a, info b)
{
    return a.w < b.w;
}

class mst
{
private:
    vector<info> vec;
    int arr[10007];
    int sum = 0;
    int cnt = 0;
    int x;
    int y;

public:
    void init()
    {
        for (int i = 1; i < 10001; i++)
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

    void execute(vector<info> &v, int total)
    {
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < v.size(); i++)
        {
            if (union_set(v[i].idx1, v[i].idx2))
            {
                cnt++;
                sum += v[i].w;
                vec.push_back(info{v[i].idx1, v[i].idx2, 0});
            }
        }

        printf("%d %d\n", sum + total, cnt);

        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d %d\n", vec[i].idx1, vec[i].idx2);
        }
    }
};

int main()
{
    mst mt;
    mt.init();

    int n;
    int x;
    int sum = 0;
    vector<info> v;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            scanf("%d", &x);
            if (j > i)
            {
                if (x < 0)
                {
                    sum += -1 * x;
                    mt.union_set(i, j);
                }
                else
                {
                    v.push_back(info{i, j, x});
                }
            }
        }
    }

    mt.execute(v, sum);
}
