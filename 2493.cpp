#include <iostream>
#include <vector>

using namespace std;

/*
2493번 문제 접근 방식
->
내림차순으로 스택을 정렬한다
6, 9, 5
-> 6
-> 9
-> 9, 5 이렇게 정한다.
이때 가장 앞에있는 것은 수신할 곳이 없으므로 0이고,
나머지는 자신 앞 숫자 위치에 수신이 가능하다.
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

info arr[500007];

class ms
{
private:
    vector<info> v;
    vector<int> ans;

public:
    void execute(int n)
    {
        v.push_back(arr[1]);
        ans.push_back(0);

        for (int i = 2; i < n + 1; i++)
        {
            while(!v.empty() && v.back().data < arr[i].data)
            {
                v.pop_back();
            }

            v.push_back(arr[i]);

            if (v.size() == 1)
            {
                ans.push_back(0);
            }

            else
            {
                ans.push_back(v[v.size() - 2].idx);
            }
        }

        for (int i = 0; i < n; i++)
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

    ms s;
    s.execute(n);
}
