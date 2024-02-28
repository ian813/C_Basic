#include "member.h"

int lenCheck(char* putId, char* putPw)
{
    if (strcmp(putId, "0") == 0) // 0 누르면 이전으로
        return 2;
    if (strlen(putId) > 0 && strlen(putId) > 10) // ID 길이 검사 수정
    {
        printf("\n                                                              >>> 사용할 수 없는 아이디입니다.\n\n");
        return 1;
    }
    if (strlen(putPw) > 0 && (strlen(putPw) == 0 || strlen(putPw) > 5)) // PW 길이 검사 수정
    {
        printf("                                                              >>> 사용할 수 없는 비밀번호입니다.\n\n");
        return 1;
    }
    return 0;
}

int overlap(char* putId, int mcount, MBS* member)
{
    for (int i = 0; i < mcount; i++)
    {
        if (strcmp(putId, member->id[i]) == 0)
        {
            printf("                                                          >>> 이미 사용 중인 아이디입니다.\n\n");
            return 1; // 중복 발견 시 1 반환
        }
    }
    return 0; // 중복 없음, 계속 진행
}