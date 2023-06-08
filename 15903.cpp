#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
15903번 문제 접근 방식
->
가장 작은 2개의 수를 꺼낸다 ->
우선순위 큐를 쓴다. (정렬 계속 하기엔 시간이 걸림) 150000 lg 150000 이니까 1초를 넘을수있다.

그후 더한뒤 다시 큐에 넣는다.
*/

/*
태그
. 자료 구조
. 그리디 알고리즘
. 우선순위 큐
*/

typedef long long ll;

class card
{
private:
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    ll x, y, s;

public:
    void init(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            pq.push(*(arr + i));
        }
    }

    void execute(int m)
    {
        for (int i = 0; i < m; i++)
        {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();

            pq.push(x + y);
            pq.push(x + y);
        }

        s = pq.size();
        for (int i = 0; i < s; i++)
        {
            sum += pq.top();
            pq.pop();
        }

        printf("%lld", sum);
    }

};

int main()
{
    int n, m;
    int arr[1007];
    card c;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    c.init(arr, n);
    c.execute(m);
}
