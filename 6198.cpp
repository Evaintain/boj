#include <iostream>
#include <vector>

using namespace std;

/*
6198번 문제 접근 방식
->
모노토닉 스택을 읽고 한번 도전한다.
입력이 될때 자신보다 큰것만 남기고, 크기 - 1을 정답에 더해준다.
크거나, 같은 건물을 못보는데 <로 했음 <=가 답.
*/

/*
태그
. 자료 구조
. 스택
*/

class monotonic_stack
{
private:
    vector<int> s;
    long long sum = 0;
public:
    void input(int &a)
    {
        while(!s.empty() && s.back() <= a)
        {
            s.pop_back();
        }

        s.push_back(a);
        sum += s.size() - 1;
    }

    void execute()
    {
        printf("%lld", sum);
    }
};

int main()
{
    monotonic_stack ms;
    int n;
    int m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ms.input(m);
    }

    ms.execute();
}
