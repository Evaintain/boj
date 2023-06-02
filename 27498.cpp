#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
27498번 문제 접근 방식
->
mst 문제, 내림차순으로 정렬하고, mst를 만든뒤 love총합에서 mst를 만드는 만큼 뺀다.
여기서 이미 1인경우는 계산하지 않는다.
*/

/*
태그
. 그래프 이론
. 최소 스패닝 트
*/

struct info
{
    int h1;
    int h2;
    int love;
};

bool compare(info a, info b)
{
    return a.love > b.love;
}

class mst
{
private:
    int arr[10007];
    int sum = 0;
public:
    void init()
    {
        for (int i = 1; i < 10001; i++)
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

    void execute(vector<info> &vec, int total)
    {
        sort(vec.begin(), vec.end(), compare);

        for (int i = 0; i < vec.size(); i++)
        {
            if (union_set(vec[i].h1, vec[i].h2))
            {
                sum += vec[i].love;
            }
        }

        printf("%d", total - sum);
    }
};

int main()
{
    mst mt;
    mt.init();

    int n, m;
    int sum_love = 0;
    vector<info> v;
    scanf("%d %d", &n, &m);
    int h1, h2, love, connect;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &h1, &h2, &love, &connect);
        if (connect == 1)
        {
            mt.union_set(h1, h2);
        }
        else
        {
            sum_love += love;
            v.push_back(info{h1, h2, love});
        }
    }


    mt.execute(v, sum_love);
}
