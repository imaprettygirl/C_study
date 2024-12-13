#include <stdio.h>

// 연속 계산기 함수 혼자 만들어보기

// 함수 선언
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

    printf("입력값 1 :");
    scanf("%f", &input1);
    result = input1;

    while(1)
    {
        printf("입력값 2 :");
        scanf("%f", &input2);
        
        printf("1. 더하기 2. 빼기 3. 곱하기 4. 나누기 5. 종료 : ");
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
                printf("0으로 나눌 수 없습니다\n");
            }
        }
        else
        {
            printf("종료합니다\n");
            break;
        }

    }


    return 0;
}

void p(float result)
{
    printf("결과: %.5f\n", result);  // 실수 결과 출력 (소수점 5자리까지)
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