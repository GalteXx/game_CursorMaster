#include "All.h"
#include "tower.h"
#include "UI.h"
#include "hole.h"
int m::x;
int m::y;
int Enemy::speed;
int tower::hp;//why do i have to do this...


void tower_col(Enemy &en, tower tow, bool &lose, SDL2SoundEffects &se)
{
    //int xpoint = 1;
    //int ypoint = 1;
    //
    //if (en.x + en.size >= tow.x - tow.size && en.x - en.size <= tow.x + tow.size)//if lefter
    //    xpoint--;
    //else if (en.x + en.size >= tow.x - tow.size && en.x - en.size >= tow.x + tow.size)//if righter
    //    xpoint--;
    //if (en.y + en.size >= tow.y - tow.size && en.y - en.size <= tow.y + tow.size)//if above
    //    ypoint--;
    //else if (en.y - en.size <= tow.y + tow.size && en.y + en.size > tow.y - tow.size)//if under
    //if (ypoint == 0 && xpoint == 0)
            //tower::hp--;*/
    if (en.x >= tow.x - tow.size / 2 && en.x <= tow.x + tow.size / 2 && en.y >= tow.y - tow.size / 2 && en.y <= tow.y + tow.size / 2)
    {
        int a = 50, b = 750;
        tower::hp--;
        if (tower::hp == 0)
            lose = 1;
        en.x = rand() % (b - a + 1) + a;
        en.y = rand() % (b - a + 1) + a;
        se.playSoundEffect("C:\\SDL Game Assets\\TOWER.wav");
    }
}

void hole_col(hole hol, Enemy &en, int &p)
{
    if (en.x >= hol.x - hol.sizex  && en.x <= hol.x + hol.sizex  && en.y >= hol.y - hol.sizey  && en.y <= hol.y + hol.sizey )
    {
        int a = 100, b = 700;
        en.x = rand() % (b - a + 1) + a;
        en.y = rand() % (b - a + 1) + a;
        p += 50;
    }
}


int main(int argc, char* args[])
{
    SDL_Window* wind;
    SDL_Renderer* rende;
    tower tow;
    tower::hp = 3;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    bool GameRunning = true, Menu = true, ChooseDifficulty = true, lose = false, check_texture = 1, gamePlay = 1;
    setlocale(LC_ALL, "Russian");
    cout << "����� ������ �������. ��������� ���, ����� �� ���� �� ��������� �� ������." << endl;
    cout << "������� �������������� ��� ��������, � ��� ����� ���������� ������." << endl;
    cout << "���� ����� ��������� �� ������ 3 ����, �� ���� ���������." << endl;

    int p = -50; // points
    vector <Enemy> arr;
    for (int i = 0; i < 10; i++)
    {
        Enemy en;
        arr.push_back(en);
    }
    vector <hole> hol;
    hole h;
    int a = 600, b = 700;
    h.x = 200;
    h.y = 600;
    hol.push_back(h);
    h.x = 600;
    h.y = 200;
    hol.push_back(h);
    /*a = 100, b = 200;
    h.x = rand() % (200 - 100 + 1) + 100;
    h.y = rand() % (600 - 200 + 1) + 200;
    hol.push_back(h);*/
    for (int i = 0; i < arr.size(); i++)
    {
        int a = 100, b = 700;
        int x = rand() % (b - a + 1) + a;
        int y = rand() % (b - a + 1) + a;
        arr[i].x = x;
        arr[i].y = y;
    }
    SDL2SoundEffects se;
    while(GameRunning)
    {
        while (Menu)
        {
            clear(rende);
            drawTexture(100, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\LOGO.bmp")), rende);
            drawTexture(200, 300, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\START.bmp")), rende);
            drawTexture(200, 550, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
            SDL_Event e;
            SDL_PollEvent (&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 300 && y <= 450)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    Menu = 0;
                }
                if (x <= 600 && x >= 200 && y >= 550 && y <= 700)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    SDL_Delay(300);
                    SDL_Quit();
                }
            }
            present(rende);
        }
        while (ChooseDifficulty)
        {
            clear(rende);
            drawTexture(200, 75, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EASY.bmp")), rende);
            drawTexture(200, 325, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\MEDIUM.bmp")), rende);
            drawTexture(200, 575, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\HARD.bmp")), rende);
            SDL_Event e;
            SDL_PollEvent(&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 75 && y <= 225)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 30;
                }
                if (x <= 600 && x >= 200 && y >= 325 && y <= 475)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 22;
                }
                if (x <= 600 && x >= 200 && y >= 575 && y <= 725)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 10;
                }
            }
            present(rende);
            gamePlay = 1;
        }

        while (gamePlay)
        {
            clear(rende);
            SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
            points(p, rende);
            SDL_Delay(Enemy::speed);
            for (int i = 0; i < arr.size(); i++)
            {
              arr[i].updt(rende, p);
              tower_col(arr[i], tow, lose, se);
              for (int j = 0; j < hol.size(); j++)
              {
                  hol[j].update(rende);
                  hole_col(hol[j], arr[i], p);
              }
            }
            tow.updt(rende);
            UI::update(rende);
            present(rende);
            if (lose == 1)
            {
                p = 0;
                lose = 1;
                while (lose)
                {
                    clear(rende);
                    drawTexture(200, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\GAMEOVER.bmp")), rende);
                    drawTexture(200, 250, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\RETRY.bmp")), rende);
                    drawTexture(200, 425, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\CHANGEDIFFICULTY.bmp")), rende);
                    drawTexture(200, 600, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
                    SDL_Event e;
                    SDL_PollEvent(&e);
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        if (x <= 600 && x >= 200 && y >= 250 && y <= 400) // RETRY
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            lose = 0;
                            tower::hp = 3;
                            gamePlay = 1;
                            for (int i = 0; i < arr.size(); i++)
                            {
                                int a = 100, b = 700;
                                x = rand() % (b - a + 1) + a;
                                y = rand() % (b - a + 1) + a;
                                arr[i].x = x;
                                arr[i].y = y;
                            }
                        }
                        if (x <= 600 && x >= 200 && y >= 425 && y <= 575) // CHANGE DIFFICULTY
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            lose = 0;
                            gamePlay = 0;
                            tower::hp = 3;
                            ChooseDifficulty = 1;
                            for (int i = 0; i < arr.size(); i++)
                            {
                                tower::hp = 3;
                                int a = 100, b = 700;
                                x = rand() % (b - a + 1) + a;
                                y = rand() % (b - a + 1) + a;
                                arr[i].x = x;
                                arr[i].y = y;
                            }
                        }
                        if (x <= 600 && x >= 200 && y >= 600 && y <= 750) // EXIT
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            SDL_Delay(300);
                            SDL_Quit();
                        }
                    }
                    present(rende);
                }
            }
        }

    }
    SDL_Quit();
    return 0;
}
