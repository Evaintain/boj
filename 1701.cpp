#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
1701번 문제 접근 방식
->
모든 시작위치에서 부분 일치 테이블의 가장 큰 값 출력.
*/

/*
태그
. 문자열
. kmp
*/

class kmp
{
private:
    int max_val = 0;

public:
    vector<int> make_table(char *s, int cnt, int starting)
    {
        vector<int> table(cnt - starting, 0);

        int start = 1;
        int match = 0;
        while (start + match + starting < cnt)
        {
            if (s[start + match + starting] == s[match + starting])
            {
                match++;
                table[start + match - 1] = match;
            }

            else
            {
                if (match == 0)
                {
                    start++;
                }

                else
                {
                    start += match - table[match - 1];
                    match = table[match - 1];
                }
            }
        }

        return table;
    }

    void execute(char *s, int cnt)
    {
        for (int j = 0; j < cnt; j++)
        {
            vector<int> table = make_table(s, cnt, j);
            for (int i = 0; i < table.size(); i++)
            {
                max_val = max(max_val, table[i]);
            }
        }

        printf("%d", max_val);
    }
};

int main()
{
    char input[5007];
    int cnt;
    kmp k;

    scanf("%s", input);
    cnt = strlen(input);
    k.execute(input, cnt);
}
