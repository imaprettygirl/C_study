#include <stdio.h>

int main_condition(void)
{
    // ������ ź�ٰ� ���� �л�/�Ϲ������� ���� (�Ϲ��� 20��)
    // if (����) {  } else {    }
    /*int age = 25;
    if (age >= 20)
    {
        printf("�Ϲ����Դϴ�");
    }
    else
    {
        printf("�л��Դϴ�");
    }*/

    // �ʵ��л�(8-13) / ���л�(14-16) / ����л�(17-19)
    // if / else if / else
    /*int age = 20;
    if (age >= 8 && age <= 13)
    {
        printf("�ʵ��л��Դϴ�\n");
    }
    else if (age >= 14 && age <=16)
    {
        printf("���л��Դϴ�\n");
    }
    else if (age >= 17 && age <=19)
    {
        printf("����л��Դϴ�\n");
    }
    else
    {
        printf("�л��� �ƴѰ�����\n");
    }*/

   // break / continue
   // 1������ 30������ �ִ� �ݿ��� 1������ 5������ ������ǥ�� �մϴ�.
   /*for (int i = 1; i <= 30; i++)
   {
        if (i >= 6)
        {
            printf("������ �л��� ���� ������\n");
            break;
        }
        printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n",i);
   }*/

   // 1������ 30������ �ִ� �ݿ��� 7�� �л��� ���ļ� �Ἦ�Դϴ�.
   // 7���� �����ϰ� 6������ 10������ ��ǥ�Դϴ�.
   /* for (int i = 1; i <= 30; i++)
   {
        if (i >= 6 && i <= 10)
        {
            if(i == 7)
            {
                printf("%d�� �л��� �Ἦ�Դϴ�\n",i);
                continue;
            }
            printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n",i);
        }
   } */

  // &&(AND) ||(OR)
  /*int a = 10;
  int b = 11;
  int c = 13;
  int d = 13;
  if (a == b || c ==d)
  {
    printf("a �� b, Ȥ�� c �� d �� ���� �����ϴ�\n");
  }
  else
  {
    printf("���� ���� �ٸ��׿�\n");
  }*/

        return 0;
}