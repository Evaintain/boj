#include <iostream>

using namespace std;

/*
18258번 문제 접근 방식
->
큐를 구현한다. 명령어 제한이 200만이므로 큐의 크기도 200만정도로 잡아준다.
*/

/*
태그
. 자료 구조
. 큐
*/

int arr[2000007];

class que
{
private:
    int ptr = 0;
    int s = 0;

public:
    void push(int n)
    {
        arr[ptr++] = n;
    }

    void front_que()
    {
        if (ptr == s)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", arr[s]);
    }

    void back_que()
    {
        if (ptr == s)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", arr[ptr - 1]);
    }

    void pop_que()
    {
        if (ptr == s)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", arr[s++]);
    }

    void empty_que()
    {
        if (ptr == s)
        {
            printf("1\n");
        }

        else
        {
            printf("0\n");
        }
    }

    void size_que()
    {
        printf("%d\n", ptr - s);
    }
};

int main()
{
    que q;

    int n;
    int x;
    char order[7];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", order);
        if (order[0] == 'p')
        {
            if (order[1] == 'u')
            {
                scanf("%d", &x);
                q.push(x);
            }

            else
            {
                q.pop_que();
            }
        }

        else if (order[0] == 'b')
        {
            q.back_que();
        }

        else if (order[0] == 'f')
        {
            q.front_que();
        }

        else if (order[0] == 's')
        {
            q.size_que();
        }

        else
        {
            q.empty_que();
        }
    }
}
