#include <iostream>

using namespace std;

/*
15000번 접근 방식
->
'\0' 까지 읽으면서 -32(대문자 = 소문자 - 32) 해서 출력
*/

/*
태그
. 구현
. 문자열
*/

char input[1000007];

class lower_to_upper
{
public:
    void execute(char *a)
    {
        for (int i = 0; a[i] != '\0'; i++)
        {
            printf("%c", a[i] - 32);
        }
    }
};

int main()
{
    lower_to_upper ltu;
    scanf("%s", input);
    ltu.execute(input);
}
