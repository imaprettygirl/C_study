#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("\n\n == ���� ���� ���� ���� == \n\n");
    int correctAnswers = 0; // ����ڰ� ���� ���� ����
    int answer;            // ����ڰ� �Է��� ��

    int prevOperation = -1; // ���� ������ ���� ����
    int operation;          // ���� ������ ���� ���� (0: ����, 1: ����, 2: ����, 3: ������)

    // 5���� ���� ����
    for (int i = 1; i <= 5; i++)
    {
        int num1 = rand() % 10 + 1; // 1~10 ������ ù ��° ����
        int num2 = rand() % 10 + 1; // 1~10 ������ �� ��° ����
        int calculatedAnswer;       // ����

        // ���� ���� ���� (������ �ٸ� ���� ���� ����)
        do {
            operation = rand() % 4; // 0~3 ������ ���� ����
        } while (operation == prevOperation);
        prevOperation = operation; // ���� ������ ���� �������� ����

        printf("\n%d��° ����: ", i);

        // ���� ���� �� ���� ���
        if (operation == 0) // ����
        {
            printf("%d + %d = ? ", num1, num2);
            calculatedAnswer = num1 + num2;
        }
        else if (operation == 1) // ����
        {
            printf("%d - %d = ? ", num1, num2);
            calculatedAnswer = num1 - num2;
        }
        else if (operation == 2) // ����
        {
            printf("%d * %d = ? ", num1, num2);
            calculatedAnswer = num1 * num2;
        }
        else // ������
        {
            num1 = (num1 / num2) * num2; // num1�� num2�� ����������� ����
            printf("%d / %d = ? ", num1, num2);
            calculatedAnswer = num1 / num2;
        }

        // ����� �Է� ó��
        scanf("%d", &answer);

        if (answer == calculatedAnswer)
        {
            printf(" >> �����Դϴ�!\n");
            correctAnswers++;
        }
        else
        {
            printf(" >> ��! ������ %d�Դϴ�.\n", calculatedAnswer);
        }

        printf("\n ����Ϸ��� �ƹ� Ű�� ��������\n");
        getchar(); // �Է� ���
        getchar();
    }

    // ���� ��� ���
    printf("\n\n�� 5���� �� %d������ ������ϴ�.\n", correctAnswers);

    return 0;
}