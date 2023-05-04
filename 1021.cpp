#include <iostream>
#include <deque>

using namespace std;

/*
1021번 문제

접근 방식
->
현재 위치에서 반시계, 시계 방향중 빠른것을 채택함.
*/

/*
느낀점
솔직히 시간초과날줄 알고 있었는데 안나서 놀랐다.
*/

int main()
{
    deque<int> deq;
    deque<int> deq_left, deq_right;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n + 1; i++)
    {
        deq.push_back(i);
    }

    int cnt = 0;
    int num;

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num);
        if (num == deq.front())
        {
            deq.pop_front();
        }
        else
        {
            deq_left.clear();
            deq_right.clear();

            int si = deq.size();
            for (int i = 0; i < si; i++)
            {
                deq_left.push_back(deq.front());
                deq_right.push_back(deq.front());
                deq.pop_front();
            }

            int left_to_right, right_to_left;

            while (1)
            {
                cnt++;

                right_to_left = deq_left.back();
                deq_left.pop_back();
                deq_left.push_front(right_to_left);

                left_to_right = deq_right.front();
                deq_right.pop_front();
                deq_right.push_back(left_to_right);

                if (right_to_left == num)
                {
                    deq_left.pop_front();
                    si = deq_left.size();
                    for (int i = 0; i < si; i++)
                    {
                        deq.push_back(deq_left.front());
                        deq_left.pop_front();
                    }
                    break;
                }

                if (deq_right.front() == num)
                {
                    deq_right.pop_front();
                    si = deq_right.size();
                    for (int i = 0; i < si; i++)
                    {
                        deq.push_back(deq_right.front());
                        deq_right.pop_front();
                    }
                    break;
                }
            }
        }
    }
    printf("%d", cnt);
}
