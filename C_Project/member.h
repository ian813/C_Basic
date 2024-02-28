#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#ifndef _MEMBER_H
#define _MEMBER_H
#define MEMBER_NUM 100

typedef struct MEMBERSHIP {
    char id[MEMBER_NUM][20];
    char pw[MEMBER_NUM][20];
    int mcount;
} MBS;

MBS member;

void dataLoad(); // ������ �޾ƿ� �Լ�
void datasave(); // ������ ������ �Լ�

int login(char* id, char* pw); // �α��� �Լ�
void signUpAndLogin(); // �α��� �Լ�

int registerMember(); // ȸ������ �Լ�

// ȸ������ �˻� �Լ���
int lenCheck(char* putId, char* putPw);
int overlap(char* putId, int mcount, MBS* member);

#endif 
