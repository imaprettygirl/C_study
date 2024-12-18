#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // ���� �õ� ����
    int correctAnswer = 0;   // �̹� ���ӿ� ���� ���� ����
    int userAnswer;          // ����� �Է�
    int calculatedAnswer;    // ���� ���
    int operation;           // ���� ���� (0: ����, 1: ����, 2: ����, 3: ������)
    int prevOperation = -1;  // ���� ���� �ʱ�ȭ (-1)

    printf("\n\n == ���� ���� ���� ���� == \n\n");

    // 5���� ���� ���
    for (int i = 0; i < 5; i++)
    {
        int num1 = rand() % 10 + 1; // ù ��° ���� (1~10)
        int num2 = rand() % 10 + 1; // �� ��° ���� (1~10)

        // ���� �ߺ� ����: do-while�� ���
        do
        {
            operation = rand() % 4; // ���� ���� (0~3)
        } while (operation == prevOperation);
        prevOperation = operation; // ���� ������ ���� �������� ����

        // ���� ����
        if (operation == 0) // ����
        {
            printf("%d ��° ���� : %d + %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 + num2;
        }
        else if (operation == 1) // ����
        {
            printf("%d ��° ���� : %d - %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 - num2;
        }
        else if (operation == 2) // ����
        {
            printf("%d ��° ���� : %d * %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 * num2;
        }
        else // ������
        {
            num1 = num2 * (rand() % 10 + 1); // num2�� ����� num1 ����
            printf("%d ��° ���� : %d / %d = ? \n", i + 1, num1, num2);
            calculatedAnswer = num1 / num2;
        }

        // ����� �Է�
        scanf("%d", &userAnswer);
        getchar(); // �Է� ���� ����

        // ���� Ȯ��
        if (userAnswer == calculatedAnswer)
        {
            printf("�����Դϴ�! \n\n");
            correctAnswer++;
        }
        else
        {
            printf("Ʋ�Ƚ��ϴ�! ������ %d�Դϴ� \n\n", calculatedAnswer);
        }

        printf("\n ����Ϸ��� �ƹ� Ű�� ��������...\n");
        getchar(); // �Է� ���
    }

    // ���� ��� ���
    printf("\n\n �� 5���� �� %d ������ ������ϴ�! \n", correctAnswer);

    return 0;
}
