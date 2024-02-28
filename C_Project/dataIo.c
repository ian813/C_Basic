#include "member.h"

extern MBS member;

void dataLoad() {
    FILE* fp = fopen("member.dat", "rb");
    if (fp == NULL) {
        printf("                                                  >>> ȸ�������� �����ϴ�. \n\n");
        return;
    }

    fread(&member.mcount, sizeof(int), 1, fp);
    fread(member.id, sizeof(member.id[0]), member.mcount, fp);
    fread(member.pw, sizeof(member.pw[0]), member.mcount, fp);

    fclose(fp);
//    printf("ȸ������ �ε� ����.\n");
}

void datasave()
{
    FILE* fp;

    if (!member.mcount) // ������ �Է� �Ǽ� Ȯ��
    {
        printf("                                          >>> ȸ�������� �Էµ��� �ʾҽ��ϴ�. \n\n");
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

    printf("ȸ������ ����. \n");

}