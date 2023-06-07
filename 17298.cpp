#include <iostream>
#include <stack>

using namespace std;

/*
17298번 문제 접근 방식
->
내림차순 모노토닉 스택 구현,
만약 이번값이 이전의 스택의 값보다 크다면,
이번 값보다 작은 스택안의 값을 빼면서, 이번값으로 교체한다.
만약 끝난후에도 스택에 남아있다면, 그것은 -1의 값을 가진다.
*/

/*
태그
. 자료 구조
. 스택
*/

struct info
{
    int data;
    int idx;
};

info arr[1000007];
int ans[1000007];

class right_bigger
{
private:
    stack<info> s;

public:
    void init(int n)
    {
        for (int i = 1; i < n + 1; i++)
        {
            ans[i] = -1;
        }
    }

    void execute(int n)
    {
        init(n);
        s.push(arr[1]);

        for (int i = 2; i < n + 1; i++)
        {
            while(!s.empty() && s.top().data < arr[i].data)
            {
                int idx = s.top().idx;
                ans[idx] = arr[i].data;
                s.pop();
            }

            s.push(arr[i]);
        }

        for (int i = 1; i < n + 1; i++)
        {
            printf("%d ", ans[i]);
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &arr[i].data);
        arr[i].idx = i;
    }

    right_bigger rb;
    rb.execute(n);
}
