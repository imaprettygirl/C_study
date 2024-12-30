/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>

int printboard[4][5];       // 게임판 4*5 배열
int checkCoordinates[4][5]; // 같은 좌표 선택 여부
int targetsum;              // 목표 값 (두 숫자의 합)


void initData();       // 배열 초기화
void shuffleNumber();   // 배열 섞기
void printQuestion();   // 게임판 출력
int conv_pos_x(int x);  // x 좌표 변환
int conv_pos_y(int y);  // y 좌표 변환
int isGameFinished();   // 게임종료
void setRandomTargetSum(); // 목표 값 설정


int main_m_array_test(void)
{
    srand(time(NULL));  // 난수 초기화
    
    initData();
    shuffleNumber();        // 숫자 섞기
    setRandomTargetSum();   // 랜덤 목표 값 설정

    int failCount = 0; // 실패 횟수

    while(1)
    {
        int select1 = 0;   // 사용자가 선택한 첫번째 수
        int select2 = 0;   // 사용자가 선택한 두번째 수

        printQuestion();    // 게임판 출력
        printf("뒤집을 숫자를 고르세요( 1 ~ 10 사이) : ");
        scanf("%d %d", &select1, &select2);

        if (select1 == select2) // 같은 숫자를 선택했을 경우 무효
            continue;
        
        // 정수 좌표를 (x, y)로 변환
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);
        
        // 숫자 합이 목표 값인지 확인
        if (checkCoordinates[firstSelect_x][firstSelect_y] == 0
        && checkCoordinates[secondSelect_x][secondSelect_y] == 0)
        {
            int sum = printboard[firstSelect_x][firstSelect_y] + printboard[secondSelect_x][secondSelect_y];

            if ( sum == targetsum )
            {
                printf("정답입니다! : %d + %d = %d \n",
                printboard[firstSelect_x][firstSelect_y],
                printboard[secondSelect_x][secondSelect_y], targetsum);
                checkCoordinates[firstSelect_x][firstSelect_y] = 1;
                checkCoordinates[secondSelect_x][secondSelect_y] = 1;
            }
            else
            {
                printf("틀렸습니다! 다시 시도해보세요.\n");
                failCount++;    // 실패 횟수 증가
            }
        }
        else
        {
            printf("이미 뒤집힌 카드입니다. 다른 카드를 선택하세요!\n");
        }

        // 게임 종료 확인
        if (isGameFinished())
        {
            printf("게임 종료! 총 실패 횟수: %d\n", failCount);
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
            checkCoordinates[i][j] = 0;  // 모든 카드 처음에는 뒤집히지 않은 상태
        }
    }
}

void shuffleNumber()
{
    int numbers[20];    // 1 ~ 10 사이의 숫자가 2번 들어가는 배열열
    for (int i = 0; i < 10; i++)
    {
        numbers[i * 2] = i + 1;
        numbers[i * 2 + 1] = i + 1; // 같은 숫자 2번 배치
    }

    // 숫자 섞기
    for (int i = 0; i < 20; i++)
    {
        int randomIndex = rand() % 20;
        int temp = numbers[i];
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;        
    }

    // 섞은 숫자를 게임판에 배치
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
    return (num - 1) / 5;  // 1~5는 0, 6~10은 1
}

int conv_pos_y(int num)
{
    return (num - 1) % 5;  // 1~5는 0~4, 6~10은 0~4
}

void printQuestion()
{
    printf("\n===== 현재 게임판 =====\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkCoordinates[i][j] == 1)    // 이미 뒤집어진 카드
            {
                printf("%2d ", printboard[i][j]);  // 숫자가 맞춰졌으면 숫자 표시
            }
            else    // 아직 뒤집히지 않은 카드
            {
                printf("  * ");  // 아직 맞추지 못한 곳은 '*'로 표시
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
                return 0;   // 아직 게임이 종료되지 않음
        }
    }
    return 1;
}

void setRandomTargetSum()
{
    int possibleSums[19];  // 가능한 합의 배열 (2 ~ 20)

    int index = 0;
    for (int i = 1; i <= 10; i++)  // i는 1 ~ 10
    {
        for (int j = i; j <= 10; j++)  // j는 i ~ 10
        {
            possibleSums[index++] = i + j;
        }
    }

    // 가능한 합들 중 랜덤으로 선택
    targetsum = possibleSums[rand() % 19];
    printf("목표 값: %d\n", targetsum);
}
 */