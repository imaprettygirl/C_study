#include <stdio.h>
#include <string.h>

int main(void)
{
    // 정수형 변수에 대한 예제
    /*int age = 12;
    printf("%d\n",age);
    age = 13;
    printf("%d\n",age);*/

    // 실수형 변수에 대한 예제
    /*float f = 46.5f;
    printf("%f\n",f);
    printf("%.2f\n"0,f);
    double d = 4.428;
    printf("%lf\n",d);
    printf("%.2lf\n",d);*/

    // 상수에 대한 예제
    /*const int YEAR = 2000; // 상수
    printf("태어난 년도 : %d\n", YEAR);*/

    // printf
    // 연산
    /*int add = 3 + 7; // 10
    printf("3 + 7 = %d\n", add);
    printf("%d x %d = %d\n", 30, 79, 30*79);*/

    // scanf
    // 키보드 입력을 받아서 저장
    /*int input;
    printf("값을 입력하세요: ");
    scanf("%d", &input); // vscode에서는 scanf_s 사용불가
    printf("입력값: %d\n", input);*/
    
    // 컴파일 오류남
    /*int one, two, three;
    printf("3개의 정수를 입력하세요 : ");
    scanf("%d %d %d", &one, &two, &three);
    printf("첫번째 값 : %d\n", one);
    printf("두번째 값 : %d\n", two);
    printf("세번째 값 : %d\n", three);*/

    // 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
    /*char c = 'A';
    printf("%c\n",c);*/ //문자

    // 컴파일 오류, 아무래도 scanf 에서 나오는 오류가 맞는 듯 하다
    /*char str[256];
    scanf_s("%s", str, sizeof(str));
    printf("%s\n", str);*/  // 문자열


    // 프로젝트
    // 경찰관이 범죄자의 정보를 입수 (조서 작성)
    // 이름? 나이? 몸무게? 키? 범죄명?
    char name[256];
    printf("이름이 뭐예요?");
    scanf("%255s",name);

    int age;
    printf("몇살이에요?");
    scanf("%d", &age);

    float weight;
    printf("몸무게는 몇 kg 이예요?");
    scanf("%f", &weight);

    double height;
    printf("키는 몇 cm 이예요?");
    scanf("%lf", &height);

    char what[256];
    printf("무슨 범죄를 저질렀어요?");
    scanf("%255s",what);

    // 조서 내용 출력
    printf("\n\n--- 범죄자 정보 ---\n\n");
    printf("이름    :   %s\n", name);
    printf("나이    :   %d\n", age);
    printf("몸무게  :   %.2f\n", weight);
    printf("키      :   %.2lf\n", height);
    printf("범죄    :   %s\n", what);

    return 0;
}