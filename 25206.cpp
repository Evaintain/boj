#include <bits/stdc++.h>

using namespace std;

/*
25206번 문제
접근방식
->
문자열 실수 평점 순으로 입력이 되는데
문자열은 의미가 없다.
평점을 보고 실수랑 곱해서 평균을 내야하는데
평점이 P면. 계산하지 않는다.
*/

int main()
{
    char subject[57], grade[7]; //과목, 학점 배열
    char grade_alpha[] = {'A', 'B', 'C', 'D'}; // 학점 알파벳 등급
    char grade_plus[] = {'+', '0'}; //학점 +, 0 의 차이
    double grade_alpha_score[] = {4.0, 3.0, 2.0, 1.0}; //학점 알파벳의 점수
    double grade_plus_score[] = {0.5, 0.0}; // 학점 +, 0에 따른 추가 점수.
    double score, sum = 0, num = 0;
    while(scanf("%s %lf %s", subject, &score, grade) != EOF)
    {
        if (grade[0] == 'P') continue; //등급이 P라면 재시작한다.
        else if (grade[0] == 'F') //등급이 F라면 num에다가 학점만 추가하고 반복문을 재시작한다.
        {
            num += score;
            continue;
        }
        else
        {
            for (int i = 0; i < 4; i++) //등급 알파벳 찾는 반복문.
            {
                if (grade[0] == grade_alpha[i]) //grade[0]이 grade_alpha[i]와 같으면
                {
                    for (int j = 0; j < 2; j++) //등급 +, 0를 보는 반복문.
                    {
                        if (grade[1] == grade_plus[j]) //grade[1]에 grade_plus[j]와 같으면
                        {
                            num += score; //학점을 num에 추가해준다.
                            sum += score * (grade_alpha_score[i] + grade_plus_score[j]); //학점 * 등급점수를 sum에 더해준다
                        }
                    }
                }
            }
        }
    }
    printf("%.6f", sum / num); //EOF일때 출력한다.
}
