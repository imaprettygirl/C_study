#include <stdio.h>

// ���� ���� �Լ� ȥ�� ������

// �Լ� ����
void p(float result);

float add(float input1, float input2);
float sub(float input1, float input2);
float mul(float input1, float input2);
float div(float input1, float input2);

int main(void)
{
    float input1, input2;
    float result = 0;
    int calculate;

    printf("�Է°� 1 :");
    scanf("%f", &input1);
    result = input1;

    while(1)
    {
        printf("�Է°� 2 :");
        scanf("%f", &input2);
        
        printf("1. ���ϱ� 2. ���� 3. ���ϱ� 4. ������ 5. ���� : ");
        scanf("%d", &calculate);


        if ( calculate == 1)
        {
            result = add(result, input2);
            p(result);
        }
        else if ( calculate == 2)
        {
            result = sub(result, input2);
            p(result);
        }
        else if ( calculate == 3)
        {
            result = mul(result, input2);
            p(result);
        }
        else if ( calculate == 4)
        {
            if (input2 != 0)
            {
                result = div(result, input2);
                p(result);
            }
            else
            {
                printf("0���� ���� �� �����ϴ�\n");
            }
        }
        else
        {
            printf("�����մϴ�\n");
            break;
        }

    }


    return 0;
}

void p(float result)
{
    printf("���: %.5f\n", result);  // �Ǽ� ��� ��� (�Ҽ��� 5�ڸ�����)
}

float add(float input1, float input2)
{
    return input1 + input2;
}

float sub(float input1, float input2)
{
    return input1 - input2;
}

float mul(float input1, float input2)
{
    return input1 * input2;
}

float div(float input1, float input2)
{
    return input1 / input2;
}