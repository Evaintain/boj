#include <iostream>

using namespace std;

/*
1540번 문제

접근 방식
->
115 -> 340이라함.
115보다 작은 최대의 제곱수 -> 100
100 -> (100칸 1,81칸 4...) -> 1 + 4 + 9(64) + 16(49) + 25(36) + 36(25) + 49(16) + 64(9) + 81(4) => 285
101 -> 100에서 1추가되었음.4칸도 만족 못하므로 -> 285 + 0
102 -> 100에서 2추가되었음 4칸 만족하므로 -> 285 + 1
103 -> 100에서 3추가 되었음 4칸 2개 9칸 1개 만족하므로 -> 285 + 3
104 -> 100에서 4추가 되었음 4칸 3개 9칸 2개 16칸 1개 만족하므로 -> 285 + 6
... 0 1 3 6 10 15 21 28 36 45 [n이 10일때]
110 -> 285 + 45
115 -> 285 + 45 + 10 => 340

->
n이 제곱수일 경우 1 부터 sqrt(n) - 1 까지의 제곱의 합임.
n 보다 작은 최대의 제곱수 k^2, n보다 큰 최소의 제곱수 (k+1)^2의 범위에서 n이
((k + 1) ^ 2 - 1 + k ^ 2) / 2 = k 보다 클경우 0부터 k-1의 합만큼 더해주고
나머지 숫자를 다시 더해줌

정리
=> n보다 작은 최대의 제곱수 k^2을 0 부터 (k - 1)^2 까지 더해주고,
n - k ^ 2 >= k 일경우 0부터 k-1 까지의 합을 더해준뒤, 남은수(아래과정)를 더한다.
n - K ^ 2 < k 일경우 0 부터 k - (n - k ^ 2) - 1 까지의 합을 더해준다.

(예시 115 -> 100(k = 10) | 10(115는 (121 - 1 + 100) / 2) 보다 큼 | 5
*/

/*
조건
첫째줄에 N이 주어진다. N은 0이상 10^6이하. -> N은 최대 1000^2을 가진다.
배열의 크기 1001(0 포함이므로) + a
*/

/*
태그
. 수학
*/

int prefix_sum[1007];
int prefix_sqaure_sum[1007];

int main()
{
    prefix_sqaure_sum[0] = prefix_sum[0] = 0;
    prefix_sqaure_sum[1] = prefix_sum[1] = 0;
    for (int i = 2; i < 1001; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + (i - 1);
        prefix_sqaure_sum[i] = prefix_sqaure_sum[i - 1] + (i - 1) * (i - 1);
    }

    int n;
    int cnt = 1;
    int total = 0;
    scanf("%d", &n);

    while (cnt * cnt <= n) //위에서 설명한 k 구하는 수. k^2 = n 이어도 아래서 -1을 하기에 같아도 1번 더 더해준다.
    {
        cnt++;
    }
    cnt--;
    total += prefix_sqaure_sum[cnt];
    n -= cnt * cnt;

    while(n != 0)
    {
        if (n >= cnt)
        {
            total += prefix_sum[cnt];
            n -= cnt;
        }
        else
        {
            total += prefix_sum[n]; //이전엔 cnt - n 이었는데 10 -> 5가 나와야하는데 6이 나옴. cnt - n 이 아닌 n이 답임.
            n = 0;
        }
    }
    printf("%d", total);
}
