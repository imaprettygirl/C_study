#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void)
{
    //srand(time(NULL)); // ���� �ʱ�ȭ
    // int ������ = rand() % � ��
    //int num = rand() % 3 + 1; // 1-3

    /* printf("���� �ʱ�ȭ ����..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", rand() %10);
    }
    
    srand(time(NULL));// ���� �ʱ�ȭ
    printf("\n\n���� �ʱ�ȭ ����..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", rand() %10);
    }*/

    // ���� 0 ���� 1 �� 2
    /* srand(time(NULL));
    int i = rand() % 3; // 0 - 2 ��ȯ
    if (i == 0)
    {
        printf("����\n");
    }
    else if (i == 1)
    {
        printf("����\n");
    }
    else if (i == 2)
    {
        printf("��\n");
    }
    else
    {
        printf("�����\n");
    } */

    // switch(��) { case 0 : printf("\n"); break; default : printf("\n"); break;}
    /* srand(time(NULL)); // ���� �ʱ�ȭ
    int i = rand() % 3; // 0 - 2 ��ȯ
    switch(i)
    {
        case 0 : printf("����\n"); break; //
        case 1 : printf("����\n"); break; //
        case 2 : printf("��\n"); break; //
        default : printf("�����\n"); break; //
    } */
    
    /* int age = 15;
    switch(age)
    {
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13: printf("�ʵ��л��Դϴ�\n"); break;
        case 14: 
        case 15:
        case 16: printf("���л��Դϴ�\n"); break;
        case 17:
        case 18:
        case 19: printf("����л��Դϴ�\n"); break;
        default: printf("�л��� �ƴѰ�����\n"); break;

    } */

    // Up and Down
    srand(time(NULL));
    int num = rand() % 100 + 1; // 1 - 100���� ���� ��
    printf("���� : %d\n", num);
    int answer = 0; // ����
    int chance = 5; // ��ȸ
    while (chance > 0)
    {
        printf("���� ��ȸ %d �� \n", chance);
        printf("���ڸ� ���纸���� (1~100) : ");
        scanf("%d", &answer);

        if( answer > num)
        {
            printf("DOWN : ��\n\n");
        }
        else if( answer < num)
        {
            printf("UP : ��\n\n");
        }
        else if ( answer == num)
        {
            printf("�����Դϴ� !\n\n");
            break;
        }
        else
        {
            printf("�� �� ���� ������ �߻��߽��ϴ�\n");
        }
        
        chance--;
        
        if (chance == 0)
        {
            printf("��� ��ȸ�� �� ����ϼ̳׿�. �ƽ��� �����ϼ̽��ϴ�.\n");
            break;
        }
    }
   
    return 0;
}