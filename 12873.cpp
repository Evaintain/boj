#include <iostream>
#include <queue>

using namespace std;

/*
12873번 문제 접근 방식
->
1부터 n까지 다 채워놓고
1부터 n - 1까지 for문 돌리면서
t^3일때 제거.
이 문제는 시간초과가 뜨기 쉽다는 것임. sum(1^3 ... + 5000^3)이므로.
t^3 % 남아있는 수 만큼 하면 뜨기 쉽진 않을거임.

질문게시판을 들여다 보고 나서, 작성하는 글
(t^3 - 1) % q.size() -> t^3번째를 빼기 때문에, t^3 - 1 까지만 체크를함.
그후 pop해주면 pop하는 번째가 t^3번째 이므로.
*/

/*
태그
. 구현
. 자료 구조
. 시뮬레이션
. 큐
*/

class que
{
private:
    queue<int> q;
    int pop_q;
    int cnt;

public:
    void init(int n)
    {
        for (int i = 1; i < n + 1; i++)
        {
            q.push(i);
        }
    }

    void pop_and_push()
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    void execute(int n)
    {
        init(n);
        for (long long i = 1; i < n; i++)
        {
            cnt = (i * i * i - 1) % q.size();
            for (int j = 0; j < cnt; j++)
            {
                pop_and_push();
            }
            q.pop();
        }

        printf("%d", q.front());
    }
};

int main()
{
    int n;
    que q;

    scanf("%d", &n);
    q.execute(n);
}
