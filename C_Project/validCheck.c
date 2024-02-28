#include "member.h"

int lenCheck(char* putId, char* putPw)
{
    if (strcmp(putId, "0") == 0) // 0 ������ ��������
        return 2;
    if (strlen(putId) > 0 && strlen(putId) > 10) // ID ���� �˻� ����
    {
        printf("\n                                                              >>> ����� �� ���� ���̵��Դϴ�.\n\n");
        return 1;
    }
    if (strlen(putPw) > 0 && (strlen(putPw) == 0 || strlen(putPw) > 5)) // PW ���� �˻� ����
    {
        printf("                                                              >>> ����� �� ���� ��й�ȣ�Դϴ�.\n\n");
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
            printf("                                                          >>> �̹� ��� ���� ���̵��Դϴ�.\n\n");
            return 1; // �ߺ� �߰� �� 1 ��ȯ
        }
    }
    return 0; // �ߺ� ����, ��� ����
}