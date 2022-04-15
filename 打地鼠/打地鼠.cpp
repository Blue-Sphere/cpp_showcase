#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
void game_start();

void game_start()
{
    unsigned short int score = 0;
    while (score <= 10)
    {
        static char hole[3][3];
        time_t t1, t2;
        unsigned short int hit;
        srand((unsigned)time(NULL));
        short int ans = rand() % (9 - 1 + 1) + 1;
        unsigned short int count = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hole[i][j] = ' ';
                if (count == ans)
                    hole[i][j] = 'O';
                count++;
            }
        }
        printf("分數：%d\n", score);
        printf("==========\n");
        for (int k = 0; k <= 2; k++)
        {
            printf("|%c|%c|%c|\n", hole[k][0], hole[k][1], hole[k][2]);
            printf("==========\n");
        }
        time(&t1);
        time(t2);
        while (kbhit() == 0)
        {
            //卡在這裡！
        }
        hit = kbhit();
        Sleep(500);
        printf("%d %d", ans, hit - '0');
        if (hit - '0' == ans)
            score++;
        system("cls");
    }
}

int main()
{
    short int choice;
    printf("歡迎來到打地鼠遊戲，請選擇 1>進入打地鼠遊戲 0>離開");
    scanf("%d", &choice);
    if (choice == 1)
        game_start();
    return 0;
}