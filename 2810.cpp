#include <iostream>

using namespace std;


/*
2810번 문제 접근 방식
->
S -> *S*
L -> *LL*

*의 갯수를 센다.
n, 이랑 *의 갯수중 작은걸 채택함.
*/

/*
태그
. 구현
. 문자열
. 그리디 알고리즘
*/

class hold
{
private:
    int s = 1;
    int sll = -1;

public:
    void execute(int n, char *order)
    {
        for (int i = 0; i < n; i++)
        {
            if (order[i] == 'S')
            {
                s++;
            }

            if (order[i] == 'L')
            {
                s++;
                i++;
            }
        }

        printf("%d", min(s, n));
    }
};

int main()
{
    int n;
    char order[57];
    scanf("%d", &n);
    scanf("%s", order);
    hold h;
    h.execute(n, order);
}
