#include <iostream>
#include <stack>

using namespace std;

/*
3986번 문제 접근 방식
->
A, B를 추가할때, 만약 A가 스택의 마지막으로 들어갔고, 추가할게 A라면 뺀다.
그리고 스택활용 문제중 수식의 괄호쌍을 사용.
*/

/*
태그
. 자료 구조
. 스택
*/

char input[100007];

class stack_char
{
private:
    int cnt = 0;
    stack<char> s;

public:
    void init()
    {
        while (!s.empty())
        {
            s.pop();
        }
    }

    void execute()
    {
        init();

        s.push(input[0]);

        for (int i = 1; input[i] != '\0'; i++)
        {
            if (s.empty())
            {
                s.push(input[i]);
                continue;
            }

            if (s.top() == input[i])
            {
                s.pop();
            }

            else
            {
                s.push(input[i]);
            }
        }

        if (s.size() == 0)
        {
            cnt++;
        }
    }

    void print()
    {
        printf("%d", cnt);
    }
};

int main()
{
    int n;
    stack_char sc;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);
        sc.execute();
    }

    sc.print();
}
