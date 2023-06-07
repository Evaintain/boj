#include <iostream>

using namespace std;


/*
10804번 문제 접근 방식
->
10번 for문 을 돌리는데,
a, b가 입력이 되면 a부터 (a+b) / 2까지만 돌려서 서로를 바꾼다.
i = 0 부터 (b - a) / 2 + 1까지만 돌리고 a + i, b - i를 바꿔도 된다.
*/

/*
태그
. 구현
. 시뮬레이션
*/

class reverse_arr
{
private:
    int arr[27];

public:
    void init()
    {
        for (int i = 1; i < 21; i++)
        {
            arr[i] = i;
        }
    }

    void execute(int a, int b)
    {
        for (int i = 0; i < (b - a) / 2 + 1; i++)
        {
            int temp = arr[a + i];
            arr[a + i] = arr[b - i];
            arr[b - i] = temp;
        }
    }

    void print()
    {
        for (int i = 1; i < 21; i++)
        {
            printf("%d ", arr[i]);
        }
    }
};

int main()
{
    int a, b;

    reverse_arr ra;
    ra.init();

    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &a, &b);
        ra.execute(a, b);
    }

    ra.print();
}
