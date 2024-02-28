//mainPage.c
#include "method.h"
#include "member.h"

int main() {

    int choice, status;
    system("title 다우인을 위한 아파트 매물 프로그램");
    //system("mode con: cols=100 lines=50");
    system("color F9");
  /*
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

  
    CONSOLE_FONT_INFOEX fontInfo;

    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    GetCurrentConsoleFontEx(hConsoleOutput, FALSE, &fontInfo);

    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = 18;
    wcscpy_s(fontInfo.FaceName, _countof(fontInfo.FaceName), L"D2Coding");




    // ASCII 아트 출력

    SetCurrentConsoleFontEx(hConsoleOutput, FALSE, &fontInfo);*/
    printf("\n");
    printf("          □□□□□□□□□♥□□□ □□□♥♥♥♥♥♥♥□□□ □□□□□□□□□♥□□ □□□□□♥♥♥□□□□□□\n");
    printf("          □♥♥♥♥♥♥□□♥□□□ □□♥♥♥□□□♥♥♥□□ □♥♥♥♥♥♥□□♥□□ □□□□♥♥♥♥♥□□□□□\n");
    printf("          □♥□□□□□□□♥□□□ □□♥♥□□□□□♥♥□□ □□□□□♥□□□♥□□ □□□♥♥♥♥♥♥♥□□□□\n");
    printf("          □♥□□□□□□□♥□□□ □□♥♥□□□□□♥♥□□ □□□□♥♥□□□♥□□ □□♥♥♥□□□♥♥♥□□□             ■■ \n");
    printf("          □♥□□□□□□□♥♥♥□ □□♥♥♥♥♥♥♥♥□□□ □□□□♥♥□□□♥□□ □□□□□□□□□□□□□□             ■■ \n");
    printf("          □♥□□□□□□□♥♥♥□ □□□♥♥♥♥♥♥□□□□ □□□□♥♥□□□♥□□ ♥♥♥♥♥♥♥♥♥♥♥♥♥♥       ▲■■■■■■■▲\n");
    printf("          □♥□□□□□□□♥□□□ □□□□□□□□□□□□□ □□□♥♥□□□□♥□□ □□□□□♥♥♥♥□□□□□      ▲■■■■■■■■■▲\n");
    printf("          □♥□□□□□♥□♥□□□ □♥♥♥♥♥♥♥♥♥♥♥□ □□♥♥♥□□□□♥□□ □□□♥♥♥♥♥♥♥♥□□□     ▲■■■■■■■■■■■▲\n");
    printf("          □♥♥♥♥♥♥♥□♥□□□ □□□□□♥□□□□□□□ □♥♥♥□□□□□♥□□ □□□□□□□□□♥♥□□□      ■■■■■■■■■■■\n");
    printf("          □□□□□□□□□♥□□□ □□□□□♥□□□□□□□ □♥♥□□□□□□♥□□ □□□♥♥♥♥♥♥♥♥□□□      ■■   ■■■■■■\n");
    printf("          □□□□□□□□□♥□□□ □□□□□♥□□□□□□□ □□□□□□□□□♥□□ □□□♥♥♥♥♥♥♥♥□□□ ■■■■■■■■■■■■■■■■■\n");



    printf("\n");
    printf("           아파트를 찾아줘 !\n");
    printf("                                * 다 우 복 덕 방 * \n\n");
    printf("  공덕 근처 아파트 매물 추천 프로그램, 다우복덕방! \n");
    printf("  업무 의욕을 증진시킬 수 있는 최적의 아파트를 다우복덕방이 찾아줄게요!\n");

    printf("\n------------------------------------- | 사 용 방 법 | ----------------------------------------\n\n");
    printf("   1. 안내문에 따라 지역, 예산, 면적(평수) 등 원하는 조건 입력                           \n");
    printf("   2. 조건에 따라 출력되는 매물 확인                                                   \n");
    printf("   3. 더욱 자세한 정보를 원한다면 상세정보 확인하기                                      \n\n");

    signUpAndLogin(); // 로그인 함수

    // 검색함수 호출 
    search();

    printf("                                                        >>> 프로그램이 종료되었습니다. \n\n\n");

    return 0;
}