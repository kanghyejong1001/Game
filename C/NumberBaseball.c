#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h> // rand 함수를 위한 헤더 파일
  
#include <time.h> // time 함수를 위한 헤더 파일

int main()

{
    // 변수 및 배열 선언

    int random_num[3]; // 랜덤으로 생성된 숫자를 저장할 int형 배열

    int user_num[3]; // 사용자의 입력을 저장할 int형 배열
    
    int i, j; // 반복문에서 사용할 변수

    int check; // 난수 중복 체크를 위한 변수

    int inning = 1; // 회차를 확인할 변수 9이닝까지 가능

    int strike; // 스트라이크의 수를 세기 위한 변수

    int ball; // 볼의 수를 세기 위한 변수


    // 난수 생성 및 중복 체크

    srand((unsigned)time(NULL)); // 랜덤 시드 설정

    for (i = 0; i < 3; i++) // 3개의 숫자 생성을 위한 반복

    {

        check = rand() % 10; // check에 0 ~ 9 랜덤 값을 저장

        random_num[i] = check; // check 값을 random_num에 저장
        
        for (j = 0; j < i; j++) // 현재 추가된 숫자의 개수만큼 반복

        {
            
            if (check == random_num[j] && i != j) // 현재 랜덤 생성된 숫자와 이미 만들어진 숫자와의 중복을 피하기 위한 검사

            { 
                
                random_num[i] = NULL; // 현재 담긴 값이 사용되지 않도록 NULL로 초기화

                i--; // 현재 순번의 숫자를 다시 생성하도록 i 값을 감소
            
            }
        }
    }

    // 숫자야구 시작

    printf("***** Play Number BaseBall!!! *****\n\n"); 

    while (1) // 무한 반복

    {

        printf("[Number Baseball %d inning]\n", inning);

        while (1) // 정상적인 숫자만 입력받기 위한 반복

        {

            printf("< Enter a number between 0 and 9 > ( ex) : 1 2 3 ) : ");

            scanf("%d %d %d", &user_num[0], &user_num[1], &user_num[2]); // 유저 숫자 입력

            if (user_num[0] < 0 || user_num[0] > 9 || user_num[1] < 0 || user_num[1] > 9 || user_num[2] < 0 || user_num[2] > 9)

            { // 입력한 숫자가 0 ~ 9 인지 검사

                printf("\n*** must enter a number between 0 and 9. ***\n\n\n");

                continue; // 다시 숫자 입력받기 위한 while문 반복
            }

            else if (user_num[0] == user_num[1] || user_num[0] == user_num[2] || user_num[1] == user_num[2])

            { // 입력한 숫자 중에 중복된 게 있으면 다시 입력받도록

                printf("\n*** must enter a number between 0 and 9 without duplication. *** \n\n\n");

                continue; // 다시 숫자 입력받기 위한 while문 반복
            }

            break; // 아무 문제 없을 경우 반복 종료
        }

        ball = 0; // 볼 개수 초기화

        strike = 0; // 스트라이크 개수 초기화

        for (i = 0; i < 3; i++) // random_num 1~3번째에 따라 각 user_num 1~3번째를 확인하기 위한 반복

        {

            for (j = 0; j < 3; j++)
            
            {
            
                if (random_num[i] == user_num[j]) // computerBall과 userBall의 값이 같다면

                {    
                    if (i == j) // 같은 위치일 경우

                    {

                        strike++; // 스트라이크 개수 증가

                    }

                    else // 다른 위치일 경우

                    {
                     
                        ball++; // 볼 개수 증가
                
                    }
                } 
            }
        }

        // 확인한 결과를 출력

        printf("\n[%d inning] Strike : %d, Ball : %d\n\n\n", inning, strike, ball);

        if (strike == 3) // 만약 스트라이크 개수가 3개이면 승리

        {

            printf("***** you win! < %d inning > *****\n\n", inning);

            break;
        }

        else if (inning == 9) // 만약 9회차인데도 승리하지 못하면 패배

        {

            printf("***** you lose... < Random Number : %d %d %d >*****\n\n", random_num[0], random_num[1], random_num[2]);

            break;
        }

        inning++;
    }

    return 0;
}