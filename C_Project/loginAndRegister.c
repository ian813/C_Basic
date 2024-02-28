//loginAndRegister.c
#include "member.h"

extern MBS member;

int login(char* id, char* pw) {
    for (int i = 0; i < member.mcount; i++) {
        if (strcmp(member.id[i], id) == 0 && strcmp(member.pw[i], pw) == 0) {
            return 1; // �α��� ����
        }
    }
    return 0; // �α��� ����
}


int registerMember() {
    char putId[20];
    char putPw[20];
    int again = 0;
    int stop = 1;

    printf("\n------------------------------------- | ȸ �� �� �� | ----------------------------------------\n\n");

    dataLoad();
    while (stop)
    {
        printf("  ID (10�� �̳�, �ڷΰ���� 0 �Է�): ");
        gets(putId);
        if (strcmp(putId, "0") == 0) {
            return 1;
        }

        again = lenCheck(putId, ""); // ��й�ȣ ���̴� ���⼭ �˻����� ����
        if (again == 1)
            continue;

        again = overlap(putId, member.mcount, &member);
        if (again == 1) // �ߺ��� ID�� ������ ���
            continue;

        printf("  PASSWORD (5�� �̳�): ");
        gets(putPw);

        again = lenCheck("", putPw); // ���⼭ ��й�ȣ ���� �˻�
        if (again == 1)
            continue;

        strcpy(member.id[member.mcount], putId); // ���⼭ �� ID�� ��й�ȣ �߰�
        strcpy(member.pw[member.mcount], putPw);
        member.mcount++;
        stop = 0;
    }

    datasave();
    printf("                                                                       >>> ���� �Ϸ�! \n\n");
    return 0;
}


void signUpAndLogin() {
    dataLoad(); // ȸ�� ���� �ε�
    int attempts = 0;
    int choice, i;
    char tmp[100];

    while (1) { // ���� ������ �����Ͽ� ����ڰ� �ùٸ� ������ �� ������ �ݺ�
        do
        {
            printf("               |1| �α��� |                             |2| ȸ������ | \n  �Է�:  ");
            gets(tmp);
            choice = atoi(tmp);

        } while ((choice == 0 && tmp[0] != '0') || (choice != 1 && choice != 2));

        if (choice == 1) {
            char inputId[20], inputPw[20];
            attempts = 0; // �α��� �õ� Ƚ�� �ʱ�ȭ
            printf("\n------------------------------------- | ��  ��  �� | -----------------------------------------\n\n");




            while (attempts < 3) {
                printf("  ID (�ڷΰ���� 0 �Է�): ");
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
                inputPw[i] = '\0'; // �� �ڿ� �ΰ� �߰�
                printf("\n");


                if (login(inputId, inputPw))
                {
                    printf("                                                              >>> �α��� ����! (^0^)/ \n\n");
                    return; // �α��� ���� �� �Լ� ����
                }
                else {
                    printf("                                              >>> ID �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�. \n\n");

                    attempts++;
                }
            }

            if (attempts >= 3) {
                printf("                                          >>> �α��� �õ� 3ȸ �ʰ�, ȸ�������� �����մϴ�. \n\n");
                registerMember(); // �ڵ����� ȸ������ �Լ� ȣ��
                return; // ȸ������ �� �Լ� ����
            }
        }
        else if (choice == 2) {
            int result = registerMember(); // ȸ������ ����
            if (result == 1) {
                continue; // ȸ������ �� �Լ� ����
            }
            else if (result != 0 && result != 1)
            {
                printf("                                                    >>> �߸��� �����Դϴ�. �ٽ� �������ּ���.\n\n");
            }
        }
    }
}