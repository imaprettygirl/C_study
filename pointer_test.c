#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;  // 레벨
int hp[6];  // 체력
int *cursor;

void initData();          // 게임 초기화 함수
void printfHP();          // 체력을 출력하는 함수
void decreaseHP(long);    // 체력을 감소시키는 함수
void feedFish(int *, int); // 물고기에게 먹이를 주는 함수
void powerupFish(int num); // 선택한 물고기만 레벨업 시키는 함수
int checkFishAlive();     // 물고기가 죽었는지 확인하는 함수

int main(void)
{
    int num;             // 먹이 줄 물고기 번호
    int action;          // 사용자 선택
    long startTime = 0;  // 게임 시작시간
    long totalElapsedTime = 0; // 총 경과시간
    long prevElapsedTime = 0;  // 직전 경과시간

    initData();          // 게임 초기화 함수

    startTime = clock(); // 프로그램 실행 이후 현재까지 흐른 시간 저장
    cursor = hp;         // 포인터 변수에 체력 배열

    while (1)
    {
        printfHP(); // 체력 출력 함수 호출
        printf("몇 번 물고기를 선택하시겠습니까? (1~6) ");
        scanf("%d", &num); // 물고기 번호 입력

        if (num < 1 || num > 6) // 입력값 범위 확인
        {
            printf("\n입력값이 잘못됐습니다! 1~6 사이의 값을 입력하세요.\n");
            continue;
        }

        printf("어떤 행동을 하시겠습니까? \n1. 먹이주기 \n2. 파워업\n입력: ");
        scanf_s("%d", &action);

        if (action < 1 || action > 2) // 입력값 범위 확인
        {
            printf("\n잘못된 선택입니다! 1 또는 2를 입력하세요.\n");
            continue;
        }

        // 총 경과 시간 계산
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 초 단위로 표시
        printf("총 경과 시간: %ld 초\n", totalElapsedTime);

        // 체력 감소
        long elapsedTime = totalElapsedTime - prevElapsedTime;
        decreaseHP(elapsedTime);

        // 사용자 행동 처리
        if (action == 1) // 먹이주기
        {
            feedFish(cursor, num);
        }
        else if (action == 2) // 파워업
        {
            powerupFish(num); // 선택한 물고기만 파워업
        }

        // 레벨업 확인 (레벨업은 20초마다 수행)
        if (totalElapsedTime / 20 > level - 1)
        {
            level++; // 레벨업
            printf("*** 축하합니다! %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);
            if (level == 5) // 최고 레벨 확인 후 게임 종료
            {
                printf("\n\n축하합니다! 최고 레벨을 달성했습니다. 게임을 종료합니다.\n\n");
                exit(0);
            }
        }

        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0)
        {
            printf("모든 물고기가 죽었습니다. ㅠㅠ\n\n");
            exit(0);
        }

        prevElapsedTime = totalElapsedTime; // 경과 시간 업데이트
    }

    return 0;
}

// 게임 초기화 함수
void initData()
{
    level = 1; // 레벨 초기화 (레벨 범위 1~5)
    for (int i = 0; i < 6; i++)
    {
        hp[i] = 100; // 물고기 체력 초기화 (체력 100)
    }
}

// 체력 출력 함수
void printfHP()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%3d ", hp[i]); // 체력 출력
    }
    printf("\n");
}

// 체력을 감소시키는 함수
void decreaseHP(long elapsedTime)
{
    for (int i = 0; i < 6; i++)
    {
        hp[i] -= (level * 3 * (int)elapsedTime); // 감소하는 체력 계산
        if (hp[i] < 0)
        {
            hp[i] = 0; // 체력이 음수가 되지 않도록 조정
        }
    }
}

// 물고기에게 먹이를 주는 함수
void feedFish(int *cursor, int num)
{
    if (cursor[num - 1] <= 0) // 체력이 0 이하인 경우
    {
        printf("%d번 물고기는 이미 죽어서 먹이를 줄 수 없습니다.\n", num);
    }
    else
    {
        cursor[num - 1] += 10; // 체력 +10
        if (cursor[num - 1] > 100) // 체력이 100을 넘지 않도록 조정
        {
            cursor[num - 1] = 100;
            printf("%d번 물고기의 체력이 최대입니다!\n", num);
        }
        else
        {
            printf("%d번 물고기에게 먹이를 줍니다 (+10 체력).\n", num);
        }
    }
}

// 물고기를 레벨업 시키는 함수 (선택한 물고기만)
void powerupFish(int num)
{
    if (hp[num - 1] <= 0) // 선택한 물고기가 죽었다면
    {
        printf("%d번 물고기는 이미 죽었기 때문에 파워업을 할 수 없습니다.\n", num);
    }
    else
    {
        hp[num - 1] += 20; // 체력 +20
        if (hp[num - 1] > 100) // 체력이 100을 넘지 않도록 조정
            hp[num - 1] = 100;
        printf("%d번 물고기의 체력이 회복되었습니다! (+20 체력)\n", num);
    }
}

// 물고기가 죽었는지 확인하는 함수
int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        if (hp[i] > 0)
            return 1; // 참
    }
    return 0; // 거짓
}
