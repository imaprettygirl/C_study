#include <stdio.h>

int main(void)
{
    // �ּ� ctrl + /
    /*printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");*/

    // ++ �ܻ�
    /*int a = 10;
    printf("a�� %d\n",a);
    a++;
    printf("a�� %d\n",a);
    a++;
    printf("a�� %d\n",a);*/

    /*int b = 20;
    printf("b�� %d\n", ++b);    //  ++ ���� ���� �� ��� > 21
    printf("b�� %d\n", b++);    //  ���� �� ������ ++ ��� > 21
    printf("b�� %d\n", b);      //  ++ ���� > 22                */

    /*int i = 1;
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);
    printf("HEllo World %d\n", i++);*/

    // �ݺ���
    // for, while, do while

    // for (����; ����; ����) { }
    /*for (int i = 1; i <= 10; i++)
    {
        printf("Hello World %d\n", i);
    }*/

   // while
   // while (����) { }
   /*int i = 1;
    while (i <= 10)
    {
        printf("Hello World %d\n", i++);
    }*/

   // do while
   // do { } while (����);
   /*int i = 1;
   do{
    printf("Hello World %d\n", i++);
   } while (i <= 10);*/

    // ���� �ݺ���
    /*for (int i = 1; i <= 3; i++)
    {
        printf("ù ��° �ݺ��� : %d\n", i);

        for (int j = 1; j <= 5; j++)
        {
            printf("�� ��° �ݺ��� : %d\n",j);
        }
    }*/

   // ������
   /*for(int i = 2; i <= 9; i++)
   {
        printf("%d�� ���\n", i);
        for(int j = 1; j <= 9; j++)
        {
            printf("%d x %d = %d\n", i, j, i*j);
        }
   }*/

 
    //���ױ�
    /*
    *
    **
    ***
    ****
    *****
    */
   /*for(int i = 0; i < 5; i++)
   {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
   }*/


    /*
    *****
    ****
    ***
    **
    *
    */

   /*for(int i = 0; i < 5; i++)
   {
        for(int j = i; j < 5 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
   }*/

    /*
         *
        **
       ***
      ****
     *****
    */

   /*for(int i = 0; i < 5; i++)
   {
        for(int j = i; j < 5 - 1; j++)
        {
            printf(" ");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
   }*/

  // �Ƕ�̵带 �׾ƶ� ������Ʈ
  /*
    sssss*
    ssss***
       *****
      *******
     *********
    */
    int floor;
    printf("�� ������ �װڴ���?");
    scanf("%d",&floor);
    for(int i = 0; i < floor; i++)
    {
        for (int j = i; j < floor - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}