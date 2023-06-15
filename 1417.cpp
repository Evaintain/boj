#include <iostream>
#include <queue>

using namespace std;

/*
1417번 문제 접근 방식
->
다솜이표는 따로 빼고 나머지 표는 우선순위큐에 내림차순으로 우선순위를 정하고.
우선순위가 가장 높은거 보다 다솜이표가 크면 종료
아니라면 우선순위가 가장큰것 - 1을 하고 다시 큐에 넣는다.
*/

/*
태그
. 구현
. 자료 구조
. 그리디 알고리즘
. 시뮬레이션
. 우선순위 큐
*/

class pyo
{
private:
    int cnt = 0;
    int base;

public:
    void init(int base)
    {
        this->base = base;
    }

    void execute(priority_queue<int, vector<int>, less<int>> q)
    {
        while (!q.empty() && q.top() >= cnt + base)
        {
            int top = q.top();
            q.pop();
            cnt++;
            q.push(top - 1);
        }

        printf("%d", cnt);
    }
};

int main()
{
    int n;
    int in;
    priority_queue<int, vector<int>, less<int>> q;
    pyo p;

    scanf("%d", &n);
    scanf("%d", &in);
    p.init(in);

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &in);
        q.push(in);
    }

    p.execute(q);
}
