#include <iostream>
#include <vector>

using namespace std;

/*
1786번 문제 접근 방식
->
kmp 알고리즘을 사용한다.
=> 원본, 비교, 부분일치 테이블
메모리사용을 조금이나마 줄이기 위해 부분일치 테이블은 벡터로 구현한다.
*/

/*
태그
. 문자열
. KMP
*/

char string_original[1000007];
char string_compare[1000007];

class kmp
{
private:
    vector<int> ans;
    int cnt = 0;

public:
    vector<int> create_partial_table(int len)
    {
        vector<int> v(len, 0);

        int start = 1;
        int match = 0;

        while (start + match < len)
        {
            if (string_compare[start + match] == string_compare[match])
            {
                match++;
                v[start + match - 1] = match;
            }

            else
            {
                if (match == 0)
                {
                    start++;
                }

                else
                {
                    start += match - v[match - 1];
                    match = v[match - 1];
                }
            }
        }

        return v;
    }

    void execute(int len, int ori_len)
    {
        vector<int> table = create_partial_table(len);

        int start = 0;
        int match = 0;

        while (start < ori_len - len + 1)
        {
            if (match < len && string_original[start + match] == string_compare[match])
            {
                match++;

                if (match == len)
                {
                    ans.push_back(start + 1);
                    cnt++;
                }
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

        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
        {
            printf("%d ", ans[i]);
        }
    }
};

int main()
{
    int cnt = 0;
    int ori = 0;
    char input_original;
    char input_compare;
    kmp k;

    while (true)
    {
        scanf("%c", &input_original);
        if (input_original == '\n')
        {
            break;
        }

        string_original[ori++] = input_original;
    }

    while (true)
    {
        scanf("%c", &input_compare);
        if (input_compare == '\n')
        {
            break;
        }

        string_compare[cnt++] = input_compare;
    }

    k.execute(cnt, ori);
}
