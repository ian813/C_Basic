//loginAndRegister.c
#include "member.h"

extern MBS member;

int login(char* id, char* pw) {
    for (int i = 0; i < member.mcount; i++) {
        if (strcmp(member.id[i], id) == 0 && strcmp(member.pw[i], pw) == 0) {
            return 1; // 로그인 성공
        }
    }
    return 0; // 로그인 실패
}


int registerMember() {
    char putId[20];
    char putPw[20];
    int again = 0;
    int stop = 1;

    printf("\n------------------------------------- | 회 원 가 입 | ----------------------------------------\n\n");

    dataLoad();
    while (stop)
    {
        printf("  ID (10자 이내, 뒤로가기는 0 입력): ");
        gets(putId);
        if (strcmp(putId, "0") == 0) {
            return 1;
        }

        again = lenCheck(putId, ""); // 비밀번호 길이는 여기서 검사하지 않음
        if (again == 1)
            continue;

        again = overlap(putId, member.mcount, &member);
        if (again == 1) // 중복된 ID가 있으면 계속
            continue;

        printf("  PASSWORD (5자 이내): ");
        gets(putPw);

        again = lenCheck("", putPw); // 여기서 비밀번호 길이 검사
        if (again == 1)
            continue;

        strcpy(member.id[member.mcount], putId); // 여기서 새 ID와 비밀번호 추가
        strcpy(member.pw[member.mcount], putPw);
        member.mcount++;
        stop = 0;
    }

    datasave();
    printf("                                                                       >>> 가입 완료! \n\n");
    return 0;
}


void signUpAndLogin() {
    dataLoad(); // 회원 정보 로드
    int attempts = 0;
    int choice, i;
    char tmp[100];

    while (1) { // 무한 루프로 변경하여 사용자가 올바른 선택을 할 때까지 반복
        do
        {
            printf("               |1| 로그인 |                             |2| 회원가입 | \n  입력:  ");
            gets(tmp);
            choice = atoi(tmp);

        } while ((choice == 0 && tmp[0] != '0') || (choice != 1 && choice != 2));

        if (choice == 1) {
            char inputId[20], inputPw[20];
            attempts = 0; // 로그인 시도 횟수 초기화
            printf("\n------------------------------------- | 로  그  인 | -----------------------------------------\n\n");




            while (attempts < 3) {
                printf("  ID (뒤로가기는 0 입력): ");
                gets(inputId);
                if (strcmp(inputId, "0") == 0)
                    break;
                printf("  PASSWORD: ");
                i = 0;
                while (1) {
                    inputPw[i] = getch();

                    if (inputPw[i] == '\r') {
                        inputPw[i] = '\n';
                        break;
                    }

                    putchar('*');
                    i++;
                }
                inputPw[i] = '\0'; // 맨 뒤에 널값 추가
                printf("\n");


                if (login(inputId, inputPw))
                {
                    printf("                                                              >>> 로그인 성공! (^0^)/ \n\n");
                    return; // 로그인 성공 후 함수 종료
                }
                else {
                    printf("                                              >>> ID 또는 비밀번호가 일치하지 않습니다. \n\n");

                    attempts++;
                }
            }

            if (attempts >= 3) {
                printf("                                          >>> 로그인 시도 3회 초과, 회원가입을 진행합니다. \n\n");
                registerMember(); // 자동으로 회원가입 함수 호출
                return; // 회원가입 후 함수 종료
            }
        }
        else if (choice == 2) {
            int result = registerMember(); // 회원가입 진행
            if (result == 1) {
                continue; // 회원가입 후 함수 종료
            }
            else if (result != 0 && result != 1)
            {
                printf("                                                    >>> 잘못된 선택입니다. 다시 선택해주세요.\n\n");
            }
        }
    }
}