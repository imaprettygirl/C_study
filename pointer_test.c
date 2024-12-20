#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;  // ����
int hp[6];  // ü��
int *cursor;

void initData();          // ���� �ʱ�ȭ �Լ�
void printfHP();          // ü���� ����ϴ� �Լ�
void decreaseHP(long);    // ü���� ���ҽ�Ű�� �Լ�
void feedFish(int *, int); // ����⿡�� ���̸� �ִ� �Լ�
void powerupFish(int num); // ������ ����⸸ ������ ��Ű�� �Լ�
int checkFishAlive();     // ����Ⱑ �׾����� Ȯ���ϴ� �Լ�

int main(void)
{
    int num;             // ���� �� ����� ��ȣ
    int action;          // ����� ����
    long startTime = 0;  // ���� ���۽ð�
    long totalElapsedTime = 0; // �� ����ð�
    long prevElapsedTime = 0;  // ���� ����ð�

    initData();          // ���� �ʱ�ȭ �Լ�

    startTime = clock(); // ���α׷� ���� ���� ������� �帥 �ð� ����
    cursor = hp;         // ������ ������ ü�� �迭

    while (1)
    {
        printfHP(); // ü�� ��� �Լ� ȣ��
        printf("�� �� ����⸦ �����Ͻðڽ��ϱ�? (1~6) ");
        scanf("%d", &num); // ����� ��ȣ �Է�

        if (num < 1 || num > 6) // �Է°� ���� Ȯ��
        {
            printf("\n�Է°��� �߸��ƽ��ϴ�! 1~6 ������ ���� �Է��ϼ���.\n");
            continue;
        }

        printf("� �ൿ�� �Ͻðڽ��ϱ�? \n1. �����ֱ� \n2. �Ŀ���\n�Է�: ");
        scanf_s("%d", &action);

        if (action < 1 || action > 2) // �Է°� ���� Ȯ��
        {
            printf("\n�߸��� �����Դϴ�! 1 �Ǵ� 2�� �Է��ϼ���.\n");
            continue;
        }

        // �� ��� �ð� ���
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // �� ������ ǥ��
        printf("�� ��� �ð�: %ld ��\n", totalElapsedTime);

        // ü�� ����
        long elapsedTime = totalElapsedTime - prevElapsedTime;
        decreaseHP(elapsedTime);

        // ����� �ൿ ó��
        if (action == 1) // �����ֱ�
        {
            feedFish(cursor, num);
        }
        else if (action == 2) // �Ŀ���
        {
            powerupFish(num); // ������ ����⸸ �Ŀ���
        }

        // ������ Ȯ�� (�������� 20�ʸ��� ����)
        if (totalElapsedTime / 20 > level - 1)
        {
            level++; // ������
            printf("*** �����մϴ�! %d�������� %d������ �ö����ϴ�. ***\n\n", level - 1, level);
            if (level == 5) // �ְ� ���� Ȯ�� �� ���� ����
            {
                printf("\n\n�����մϴ�! �ְ� ������ �޼��߽��ϴ�. ������ �����մϴ�.\n\n");
                exit(0);
            }
        }

        // ��� ����Ⱑ �׾����� Ȯ��
        if (checkFishAlive() == 0)
        {
            printf("��� ����Ⱑ �׾����ϴ�. �Ф�\n\n");
            exit(0);
        }

        prevElapsedTime = totalElapsedTime; // ��� �ð� ������Ʈ
    }

    return 0;
}

// ���� �ʱ�ȭ �Լ�
void initData()
{
    level = 1; // ���� �ʱ�ȭ (���� ���� 1~5)
    for (int i = 0; i < 6; i++)
    {
        hp[i] = 100; // ����� ü�� �ʱ�ȭ (ü�� 100)
    }
}

// ü�� ��� �Լ�
void printfHP()
{
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%3d ", hp[i]); // ü�� ���
    }
    printf("\n");
}

// ü���� ���ҽ�Ű�� �Լ�
void decreaseHP(long elapsedTime)
{
    for (int i = 0; i < 6; i++)
    {
        hp[i] -= (level * 3 * (int)elapsedTime); // �����ϴ� ü�� ���
        if (hp[i] < 0)
        {
            hp[i] = 0; // ü���� ������ ���� �ʵ��� ����
        }
    }
}

// ����⿡�� ���̸� �ִ� �Լ�
void feedFish(int *cursor, int num)
{
    if (cursor[num - 1] <= 0) // ü���� 0 ������ ���
    {
        printf("%d�� ������ �̹� �׾ ���̸� �� �� �����ϴ�.\n", num);
    }
    else
    {
        cursor[num - 1] += 10; // ü�� +10
        if (cursor[num - 1] > 100) // ü���� 100�� ���� �ʵ��� ����
        {
            cursor[num - 1] = 100;
            printf("%d�� ������� ü���� �ִ��Դϴ�!\n", num);
        }
        else
        {
            printf("%d�� ����⿡�� ���̸� �ݴϴ� (+10 ü��).\n", num);
        }
    }
}

// ����⸦ ������ ��Ű�� �Լ� (������ ����⸸)
void powerupFish(int num)
{
    if (hp[num - 1] <= 0) // ������ ����Ⱑ �׾��ٸ�
    {
        printf("%d�� ������ �̹� �׾��� ������ �Ŀ����� �� �� �����ϴ�.\n", num);
    }
    else
    {
        hp[num - 1] += 20; // ü�� +20
        if (hp[num - 1] > 100) // ü���� 100�� ���� �ʵ��� ����
            hp[num - 1] = 100;
        printf("%d�� ������� ü���� ȸ���Ǿ����ϴ�! (+20 ü��)\n", num);
    }
}

// ����Ⱑ �׾����� Ȯ���ϴ� �Լ�
int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        if (hp[i] > 0)
            return 1; // ��
    }
    return 0; // ����
}
