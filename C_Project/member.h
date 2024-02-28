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

void dataLoad(); // 데이터 받아올 함수
void datasave(); // 데이터 저장할 함수

int login(char* id, char* pw); // 로그인 함수
void signUpAndLogin(); // 로그인 함수

int registerMember(); // 회원가입 함수

// 회원가입 검사 함수들
int lenCheck(char* putId, char* putPw);
int overlap(char* putId, int mcount, MBS* member);

#endif 
