#include <iostream>

using namespace std;

/*
10775번 문제 접근 방식
->
게이트의 번호부터 1까지 내려가며 들어갈수 있는 게이트를 본다.
방문 한것은 0으로 처리한다.
틀린 이유 : O(n^2) 알고리즘 사용, 분리집합은 구현했으나 경로압축을 시도하지 않음.
*/

/*
태그
. 자료 구조
. 그리디 알고리즘
. 분리 집합
*/

int arr[100007];

class union_find
{
private:
    int cnt = 0;
public:
    void init()
    {
        for (int i = 0; i < 100001; i++)
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
        // 이제 까지 find_set(arr[x]) 이게 경로 압축인줄 알았는데, arr[x] = find_set(arr[x]) 가 경로압축이었음.
        return arr[x] = find_set(arr[x]);
    }

    bool execute(int n)
    {
        if (union_set(find_set(n) - 1, find_set(n)))
        {
            cnt++;
            return true;
        }

        return false;
    }

    void print()
    {
        printf("%d", cnt);
    }
};

int main()
{
    union_find uf;
    uf.init();

    int n;
    int m;
    int k;
    bool check = true;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        if (check)
        {
            check = uf.execute(k);
        }
    }

    uf.print();
}
