#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // 랜덤 시드 설정
    int correctAnswer = 0;   // 이번 게임에 맞힌 문제 개수
    int userAnswer;          // 사용자 입력
    int calculatedAnswer;    // 정답 계산
    int operation;           // 현재 연산 (0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈)
    int prevOperation = -1;  // 이전 연산 초기화 (-1)

    printf("\n\n == 랜덤 연산 퀴즈 게임 == \n\n");

    // 5번의 문제 출력
    for (int i = 0; i < 5; i++)
    {
        int num1 = rand() % 10 + 1; // 첫 번째 숫자 (1~10)
        int num2 = rand() % 10 + 1; // 두 번째 숫자 (1~10)

        // 연산 중복 방지: do-while문 사용
        do
        {
            operation = rand() % 4; // 연산 선택 (0~3)
        } while (operation == prevOperation);
        prevOperation = operation; // 현재 연산을 이전 연산으로 저장

        // 문제 출제
        if (operation == 0) // 덧셈
        {
            printf("%d 번째 문제 : %d + %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 + num2;
        }
        else if (operation == 1) // 뺄셈
        {
            printf("%d 번째 문제 : %d - %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 - num2;
        }
        else if (operation == 2) // 곱셈
        {
            printf("%d 번째 문제 : %d * %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 * num2;
        }
        else // 나눗셈
        {
            num1 = num2 * (rand() % 10 + 1); // num2의 배수로 num1 설정
            printf("%d 번째 문제 : %d / %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 / num2;
        }

        // 사용자 입력
        scanf("%d", &userAnswer);
        getchar(); // 입력 버퍼 비우기

        // 정답 확인
        if (userAnswer == calculatedAnswer)
        {
            printf("정답입니다! \n\n");
            correctAnswer++;
        }
        else
        {
            printf("틀렸습니다! 정답은 %d입니다 \n\n", calculatedAnswer);
        }

        printf("\n 계속하려면 아무 키나 누르세요...\n");
        getchar(); // 입력 대기
    }

    // 최종 결과 출력
    printf("\n\n 총 5문제 중 %d 문제를 맞췄습니다! \n", correctAnswer);

    return 0;
}
