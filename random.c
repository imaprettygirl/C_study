#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void)
{
    //srand(time(NULL)); // 난수 초기화
    // int 변수명 = rand() % 어떤 수
    //int num = rand() % 3 + 1; // 1-3

    /* printf("난수 초기화 이전..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", rand() %10);
    }
    
    srand(time(NULL));// 난수 초기화
    printf("\n\n난수 초기화 이후..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", rand() %10);
    }*/

    // 가위 0 바위 1 보 2
    /* srand(time(NULL));
    int i = rand() % 3; // 0 - 2 반환
    if (i == 0)
    {
        printf("가위\n");
    }
    else if (i == 1)
    {
        printf("바위\n");
    }
    else if (i == 2)
    {
        printf("보\n");
    }
    else
    {
        printf("몰라요\n");
    } */

    // switch(값) { case 0 : printf("\n"); break; default : printf("\n"); break;}
    /* srand(time(NULL)); // 난수 초기화
    int i = rand() % 3; // 0 - 2 반환
    switch(i)
    {
        case 0 : printf("가위\n"); break; //
        case 1 : printf("바위\n"); break; //
        case 2 : printf("보\n"); break; //
        default : printf("몰라요\n"); break; //
    } */
    
    /* int age = 15;
    switch(age)
    {
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13: printf("초등학생입니다\n"); break;
        case 14: 
        case 15:
        case 16: printf("중학생입니다\n"); break;
        case 17:
        case 18:
        case 19: printf("고등학생입니다\n"); break;
        default: printf("학생이 아닌가봐요\n"); break;

    } */

    // Up and Down
    srand(time(NULL));
    int num = rand() % 100 + 1; // 1 - 100사이 랜덤 수
    printf("숫자 : %d\n", num);
    int answer = 0; // 정답
    int chance = 5; // 기회
    while (chance > 0)
    {
        printf("남은 기회 %d 번 \n", chance);
        printf("숫자를 맞춰보세요 (1~100) : ");
        scanf("%d", &answer);

        if( answer > num)
        {
            printf("DOWN : ↓\n\n");
        }
        else if( answer < num)
        {
            printf("UP : ↑\n\n");
        }
        else if ( answer == num)
        {
            printf("정답입니다 !\n\n");
            break;
        }
        else
        {
            printf("알 수 없는 오류가 발생했습니다\n");
        }
        
        chance--;
        
        if (chance == 0)
        {
            printf("모든 기회를 다 사용하셨네요. 아쉽게 실패하셨습니다.\n");
            break;
        }
    }
   
    return 0;
}