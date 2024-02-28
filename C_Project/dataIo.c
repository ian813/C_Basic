#include "member.h"

extern MBS member;

void dataLoad() {
    FILE* fp = fopen("member.dat", "rb");
    if (fp == NULL) {
        printf("                                                  >>> 회원정보가 없습니다. \n\n");
        return;
    }

    fread(&member.mcount, sizeof(int), 1, fp);
    fread(member.id, sizeof(member.id[0]), member.mcount, fp);
    fread(member.pw, sizeof(member.pw[0]), member.mcount, fp);

    fclose(fp);
//    printf("회원정보 로드 성공.\n");
}

void datasave()
{
    FILE* fp;

    if (!member.mcount) // 데이터 입력 건수 확인
    {
        printf("                                          >>> 회원정보가 입력되지 않았습니다. \n\n");
        return;
    }

    fp = fopen("member.dat", "wb");
    if (fp == NULL)
    {
        perror("member file Open error : ");
        exit(1);
    }

    fwrite(&member.mcount, sizeof(member.mcount), 1, fp);
    fwrite(member.id, sizeof(member.id[0]), member.mcount, fp);
    fwrite(member.pw, sizeof(member.pw[0]), member.mcount, fp);

    fclose(fp);

    printf("회원정보 저장. \n");

}