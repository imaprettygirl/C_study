#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("\n\n == 랜덤 연산 퀴즈 게임 == \n\n");
    int correctAnswers = 0; // 사용자가 맞힌 문제 개수
    int answer;            // 사용자가 입력한 답

    int prevOperation = -1; // 이전 문제의 연산 종류
    int operation;          // 현재 문제의 연산 종류 (0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈)

    // 5번의 문제 출제
    for (int i = 1; i <= 5; i++)
    {
        int num1 = rand() % 10 + 1; // 1~10 사이의 첫 번째 숫자
        int num2 = rand() % 10 + 1; // 1~10 사이의 두 번째 숫자
        int calculatedAnswer;       // 정답

        // 연산 종류 결정 (이전과 다른 연산 종류 선택)
        do {
            operation = rand() % 4; // 0~3 사이의 연산 선택
        } while (operation == prevOperation);
        prevOperation = operation; // 현재 연산을 이전 연산으로 저장

        printf("\n%d번째 문제: ", i);

        // 문제 출제 및 정답 계산
        if (operation == 0) // 덧셈
        {
            printf("%d + %d = ? ", num1, num2);
            calculatedAnswer = num1 + num2;
        }
        else if (operation == 1) // 뺄셈
        {
            printf("%d - %d = ? ", num1, num2);
            calculatedAnswer = num1 - num2;
        }
        else if (operation == 2) // 곱셈
        {
            printf("%d * %d = ? ", num1, num2);
            calculatedAnswer = num1 * num2;
        }
        else // 나눗셈
        {
            num1 = (num1 / num2) * num2; // num1이 num2로 나누어떨어지게 조정
            printf("%d / %d = ? ", num1, num2);
            calculatedAnswer = num1 / num2;
        }

        // 사용자 입력 처리
        scanf("%d", &answer);

        if (answer == calculatedAnswer)
        {
            printf(" >> 정답입니다!\n");
            correctAnswers++;
        }
        else
        {
            printf(" >> 땡! 정답은 %d입니다.\n", calculatedAnswer);
        }

        printf("\n 계속하려면 아무 키나 누르세요\n");
        getchar(); // 입력 대기
        getchar();
    }

    // 최종 결과 출력
    printf("\n\n총 5문제 중 %d문제를 맞췄습니다.\n", correctAnswers);

    return 0;
}