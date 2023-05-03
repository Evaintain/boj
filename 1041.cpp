#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1041번 문제

접근 방식
->
n이 주어지고 n^3 형태의 정육면체를 만들어짐.
여기서 우리가 구해야할것은 5 * n^2 개의 면의 최솟값이다.
n <= 1,000,000(10^6) 이기에 long long 자료형을 쓴다. (쓰여있는 수가 모두 50 일경우) 50 * 5 * 10^12 -> 가장 큰경우.

그러면 여기서 n >= 2 일때 4개의 3면이 노출되는 주사위(꼭짓점 부분)가 생긴다.
그리고 윗부분(바닥과 평행한 면) 모서리에는 n - 2(꼭짓점 부분을 뺀 모서리 부분)개의 2면이 노출되는 주사위(모서리 부분)가 생기고,
아랫부분(바닥과 만나는 면) 모서리에는 n - 1(이 역시 꼭짓점 부분을 뺀 모서리 부분)개의 2면이 노출되는 주사위가 생긴다.
5 * n ^ 2 - (4(갯수) * 3(노출된 수) + (n - 2)(갯수) * 4(가짓수) * 2(노출된 면의 수) + (n - 1)(갯수) * 4(가짓수) * 2(노출된 면의 수))
5 * n ^ 2 - (12 + 8n - 16 + 8n - 8) * 최솟값(나머지는 1면만 노출되어 있기 때문에)

(1은 6개중 정렬했을때 가장 큰수 빼고 다 더해주면된다.)
1번 틀림 -> 정렬을 하면 안됨. 이유 -> 마주보는 면이 최솟값이면 그게 인정이됨.
*/

/*
조건
첫째 줄에 N이 주어진다. 둘째 줄에 주사위에 쓰여 있는 수가 주어진다.
N은 1,000,000보다 작거나 같은 자연수이고, 쓰여 있는 수는 50보다 작거나 같은 자연수이다.
*/

/*
태그
. 수학
. 그리디 알고리즘
*/

/*
느낀점
질문 게시판을 보면 안된다는 걸 아는데, 이게 정렬을 못하는 문제일거라고는 생각도 못했었다. 누군가의 "아 - 정렬을 하면 안되는군요"를 보고,
"! 이거 주사위라 정렬하면 안되는구나" 했던 기억이 있다..
*/

int main()
{
    vector<int> dice;
    long long n;
    long long total = 0;
    int in_v;
    int one, two, three;
    int result_two, result_three;
    one = two = three = 200;
    scanf("%lld", &n);
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &in_v);
        dice.push_back(in_v);
    }

    for (int i = 0; i < 6; i++)
    {
        // 한면 최솟값 갱신(6개중 최솟값을 찾으면된다)
        if (dice[i] < one)
        {
            one = dice[i];
        }
        for (int j = i + 1; j < 6; j++)
        {
            //두면이 마주보는 면인 경우
            if (i + j == 5)
            {
                continue;
            }

            result_two = dice[i] + dice[j];

            // 최솟값 갱신
            if (result_two < two)
            {
                two = result_two;
            }

            for (int k = j + 1; k < 6; k++)
            {
                //3면중 마주보는 면이 있는 경우(3면도 마주보는 면이 없어야하기에 continue)
                if (j + k == 5 || i + k == 5)
                {
                    continue;
                }

                result_three = result_two + dice[k];

                //3개의 면이 이전 3개의 면의 합보다 작은경우 값 갱신.
                if (result_three < three)
                {
                    three = result_three;
                }
            }
        }
    }

    // n = 1인경우를 위해서 정렬한다.(이미 3면 노출 주사위, 2면 노출 주사위, 1면 노출 주사위의 값은 구했다.
    sort(dice.begin(), dice.end());

    if (n == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            total += dice[i];
        }
        printf("%lld", total);
    }
    else
    {
        total += 4 * three; //3면 노출 주사위 더하기
        total += (n - 2) * two * 4; //2면 노출 주사위 더하기 (상단 부분)
        total += (n - 1) * two * 4; //2면 노출 주사위 더하기 (하단 부분)
        total += (5 * (n * n) - (16 * n) + 12) * one; //나머지 1면 노출 주사위 더하기
        printf("%lld", total);
    }
}
