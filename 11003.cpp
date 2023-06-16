#include <iostream>
#include <queue>

using namespace std;

/*
11003번 문제 접근 방식
->
data, idx
data를 기준으로 오름차순 우선순위큐
idx가 i - L + 1 ~ i 를 벗어날경우 우선순위큐에서 제거.

시간초과 후
-> execute함수에서 입력받고 처리함.
*/

/*
태그
. 자료 구조
. 우선순위 큐
. 덱
*/

struct info
{
    int data;
    int idx;
};

struct compare
{
    bool operator()(info a, info b)
    {
        if (a.data == b.data)
        {
            return a.idx > b.idx;
        }
        return a.data > b.data;
    }
};

class min_val
{
private:
    int n;
    int l;
    int input;
    priority_queue<info, vector<info>, compare> q;

public:
    void init(int n, int l)
    {
        this->n = n;
        this->l = l;
    }

    void execute()
    {
        for (int i = 1; i < n + 1; i++)
        {
            cin >> input;
            q.push(info{input, i});
            while (!q.empty() && i - l + 1 > q.top().idx)
            {
                q.pop();
            }
            cout << q.top().data << " ";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    int l;
    min_val mv;

    cin >> n >> l;
    mv.init(n, l);
    mv.execute();
}
