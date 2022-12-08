#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h> // rand �Լ��� ���� ��� ����
  
#include <time.h> // time �Լ��� ���� ��� ����

int main()

{
    // ���� �� �迭 ����

    int random_num[3]; // �������� ������ ���ڸ� ������ int�� �迭

    int user_num[3]; // ������� �Է��� ������ int�� �迭
    
    int i, j; // �ݺ������� ����� ����

    int check; // ���� �ߺ� üũ�� ���� ����

    int inning = 1; // ȸ���� Ȯ���� ���� 9�̴ױ��� ����

    int strike; // ��Ʈ����ũ�� ���� ���� ���� ����

    int ball; // ���� ���� ���� ���� ����


    // ���� ���� �� �ߺ� üũ

    srand((unsigned)time(NULL)); // ���� �õ� ����

    for (i = 0; i < 3; i++) // 3���� ���� ������ ���� �ݺ�

    {

        check = rand() % 10; // check�� 0 ~ 9 ���� ���� ����

        random_num[i] = check; // check ���� random_num�� ����
        
        for (j = 0; j < i; j++) // ���� �߰��� ������ ������ŭ �ݺ�

        {
            
            if (check == random_num[j] && i != j) // ���� ���� ������ ���ڿ� �̹� ������� ���ڿ��� �ߺ��� ���ϱ� ���� �˻�

            { 
                
                random_num[i] = NULL; // ���� ��� ���� ������ �ʵ��� NULL�� �ʱ�ȭ

                i--; // ���� ������ ���ڸ� �ٽ� �����ϵ��� i ���� ����
            
            }
        }
    }

    // ���ھ߱� ����

    printf("***** Play Number BaseBall!!! *****\n\n"); 

    while (1) // ���� �ݺ�

    {

        printf("[Number Baseball %d inning]\n", inning);

        while (1) // �������� ���ڸ� �Է¹ޱ� ���� �ݺ�

        {

            printf("< Enter a number between 0 and 9 > ( ex) : 1 2 3 ) : ");

            scanf("%d %d %d", &user_num[0], &user_num[1], &user_num[2]); // ���� ���� �Է�

            if (user_num[0] < 0 || user_num[0] > 9 || user_num[1] < 0 || user_num[1] > 9 || user_num[2] < 0 || user_num[2] > 9)

            { // �Է��� ���ڰ� 0 ~ 9 ���� �˻�

                printf("\n*** must enter a number between 0 and 9. ***\n\n\n");

                continue; // �ٽ� ���� �Է¹ޱ� ���� while�� �ݺ�
            }

            else if (user_num[0] == user_num[1] || user_num[0] == user_num[2] || user_num[1] == user_num[2])

            { // �Է��� ���� �߿� �ߺ��� �� ������ �ٽ� �Է¹޵���

                printf("\n*** must enter a number between 0 and 9 without duplication. *** \n\n\n");

                continue; // �ٽ� ���� �Է¹ޱ� ���� while�� �ݺ�
            }

            break; // �ƹ� ���� ���� ��� �ݺ� ����
        }

        ball = 0; // �� ���� �ʱ�ȭ

        strike = 0; // ��Ʈ����ũ ���� �ʱ�ȭ

        for (i = 0; i < 3; i++) // random_num 1~3��°�� ���� �� user_num 1~3��°�� Ȯ���ϱ� ���� �ݺ�

        {

            for (j = 0; j < 3; j++)
            
            {
            
                if (random_num[i] == user_num[j]) // computerBall�� userBall�� ���� ���ٸ�

                {    
                    if (i == j) // ���� ��ġ�� ���

                    {

                        strike++; // ��Ʈ����ũ ���� ����

                    }

                    else // �ٸ� ��ġ�� ���

                    {
                     
                        ball++; // �� ���� ����
                
                    }
                } 
            }
        }

        // Ȯ���� ����� ���

        printf("\n[%d inning] Strike : %d, Ball : %d\n\n\n", inning, strike, ball);

        if (strike == 3) // ���� ��Ʈ����ũ ������ 3���̸� �¸�

        {

            printf("***** you win! < %d inning > *****\n\n", inning);

            break;
        }

        else if (inning == 9) // ���� 9ȸ���ε��� �¸����� ���ϸ� �й�

        {

            printf("***** you lose... < Random Number : %d %d %d >*****\n\n", random_num[0], random_num[1], random_num[2]);

            break;
        }

        inning++;
    }

    return 0;
}