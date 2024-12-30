/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>

int printboard[4][5];       // ������ 4*5 �迭
int checkCoordinates[4][5]; // ���� ��ǥ ���� ����
int targetsum;              // ��ǥ �� (�� ������ ��)


void initData();       // �迭 �ʱ�ȭ
void shuffleNumber();   // �迭 ����
void printQuestion();   // ������ ���
int conv_pos_x(int x);  // x ��ǥ ��ȯ
int conv_pos_y(int y);  // y ��ǥ ��ȯ
int isGameFinished();   // ��������
void setRandomTargetSum(); // ��ǥ �� ����


int main_m_array_test(void)
{
    srand(time(NULL));  // ���� �ʱ�ȭ
    
    initData();
    shuffleNumber();        // ���� ����
    setRandomTargetSum();   // ���� ��ǥ �� ����

    int failCount = 0; // ���� Ƚ��

    while(1)
    {
        int select1 = 0;   // ����ڰ� ������ ù��° ��
        int select2 = 0;   // ����ڰ� ������ �ι�° ��

        printQuestion();    // ������ ���
        printf("������ ���ڸ� ������( 1 ~ 10 ����) : ");
        scanf("%d %d", &select1, &select2);

        if (select1 == select2) // ���� ���ڸ� �������� ��� ��ȿ
            continue;
        
        // ���� ��ǥ�� (x, y)�� ��ȯ
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);
        
        // ���� ���� ��ǥ ������ Ȯ��
        if (checkCoordinates[firstSelect_x][firstSelect_y] == 0
        && checkCoordinates[secondSelect_x][secondSelect_y] == 0)
        {
            int sum = printboard[firstSelect_x][firstSelect_y] + printboard[secondSelect_x][secondSelect_y];

            if ( sum == targetsum )
            {
                printf("�����Դϴ�! : %d + %d = %d \n",
                printboard[firstSelect_x][firstSelect_y],
                printboard[secondSelect_x][secondSelect_y], targetsum);
                checkCoordinates[firstSelect_x][firstSelect_y] = 1;
                checkCoordinates[secondSelect_x][secondSelect_y] = 1;
            }
            else
            {
                printf("Ʋ�Ƚ��ϴ�! �ٽ� �õ��غ�����.\n");
                failCount++;    // ���� Ƚ�� ����
            }
        }
        else
        {
            printf("�̹� ������ ī���Դϴ�. �ٸ� ī�带 �����ϼ���!\n");
        }

        // ���� ���� Ȯ��
        if (isGameFinished())
        {
            printf("���� ����! �� ���� Ƚ��: %d\n", failCount);
            break;
        }
    }
        


    return 0;
}

void initData()
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printboard[i][j] = -1;
            checkCoordinates[i][j] = 0;  // ��� ī�� ó������ �������� ���� ����
        }
    }
}

void shuffleNumber()
{
    int numbers[20];    // 1 ~ 10 ������ ���ڰ� 2�� ���� �迭��
    for (int i = 0; i < 10; i++)
    {
        numbers[i * 2] = i + 1;
        numbers[i * 2 + 1] = i + 1; // ���� ���� 2�� ��ġ
    }

    // ���� ����
    for (int i = 0; i < 20; i++)
    {
        int randomIndex = rand() % 20;
        int temp = numbers[i];
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;        
    }

    // ���� ���ڸ� �����ǿ� ��ġ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printboard[i][j] = numbers[i * 5 + j];
        }
    }
}

int conv_pos_x(int num)
{
    return (num - 1) / 5;  // 1~5�� 0, 6~10�� 1
}

int conv_pos_y(int num)
{
    return (num - 1) % 5;  // 1~5�� 0~4, 6~10�� 0~4
}

void printQuestion()
{
    printf("\n===== ���� ������ =====\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkCoordinates[i][j] == 1)    // �̹� �������� ī��
            {
                printf("%2d ", printboard[i][j]);  // ���ڰ� ���������� ���� ǥ��
            }
            else    // ���� �������� ���� ī��
            {
                printf("  * ");  // ���� ������ ���� ���� '*'�� ǥ��
            }
        }
        printf("\n");
    }
    printf("======================\n");
}

int isGameFinished()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(checkCoordinates[i][j] == 0)
                return 0;   // ���� ������ ������� ����
        }
    }
    return 1;
}

void setRandomTargetSum()
{
    int possibleSums[19];  // ������ ���� �迭 (2 ~ 20)

    int index = 0;
    for (int i = 1; i <= 10; i++)  // i�� 1 ~ 10
    {
        for (int j = i; j <= 10; j++)  // j�� i ~ 10
        {
            possibleSums[index++] = i + j;
        }
    }

    // ������ �յ� �� �������� ����
    targetsum = possibleSums[rand() % 19];
    printf("��ǥ ��: %d\n", targetsum);
}
 */