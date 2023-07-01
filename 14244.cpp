#include <iostream>

using namespace std;

/*
14244번 문제 접근 방식
->
0시작
m - 1개의 리프 노드 만들기. -> n - m - 1;
*/

/*
태그
. 트리
. 해 구성하기
*/

class tree
{
public:
    void execute(int n, int m)
    {
        int cnt = 0;
        int leaf = n - m    ;
        for (int i = 1; i < n; i++)
        {
            printf("%d %d\n", cnt, i);
            if (cnt < leaf)
            {
                cnt++;
            }
        }
    }
};

int main()
{
    tree t;
    int n, m;

    scanf("%d %d", &n, &m);
    t.execute(n, m);
}
