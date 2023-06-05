#include <iostream>
#include <string.h>

using namespace std;

/*
18238번 문제 접근 방식
->
문자 A, B끼리 빼본다. 이 값을 i라 한다. (시작 문자는 A로 두고 for문을 돌면서 문자를 B에 자리에 두고, 뺀뒤 값 비교후 문자 B를 A에 넣는다)
abs(i), 26 - abs(i)중 작은 값을 기준으로 더해준다.
*/

/*
태그
. 구현
. 문자열
. 그리디 알고리즘
*/

class zoac
{
private:
    char cur = 'A';
    int sum = 0;

public:
    void execute(char *s, int size_s)
    {
        for (int i = 0; i < size_s; i++)
        {
            sum += min(26 - abs(cur - s[i]), abs(cur - s[i]));
            cur = s[i];
        }

        printf("%d", sum);
    }
};

int main()
{
    char input[107];
    scanf("%s", input);

    int s = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        s++;
    }

    zoac z;
    z.execute(input, s);
}
