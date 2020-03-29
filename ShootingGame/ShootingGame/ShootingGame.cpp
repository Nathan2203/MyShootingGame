// ShootingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <thread>
#include <tchar.h>
#include <ctime>
#include <random>
#include <conio.h>
#include "ShootingGame.h"
using namespace std;

void Opening() {
    cout << "=============== WELCOME ====================" << endl;
    cout << "||           DUEL SHOOTING GAME           ||" << endl;
    cout << "=============================================" << endl;
    cout << "May the toughest survive this battle..";
    Sleep(5000);
    system("cls");
}

string InfoP1(string& player1) {
    cout << "================ P1 INFO =================" << endl;
    cout << " Player 1 input your name: ";
    cin >> player1;
    system("cls");
    return player1;
}

string InfoP2(string& player2) {
    cout << "================ P2 INFO =================" << endl;
    cout << " Player 2 input your name: ";
    cin >> player2;
    system("cls");
    return player2;
}

int SelectGun1(int& gunP1, string& player1) {

    cout << "================ Gun Type =================" << endl;
    cout << "||  Heavy Canon     ||     Chain Gun     ||" << endl;
    cout << "||  Damage: 50      ||     Damage: 35    ||" << endl;
    cout << "||  Accuracy: 50    ||     Accuracy: 65  ||" << endl;
    cout << "===========================================" << endl;
    cout << player1 << " choose your weapon (1 | 2): ";
    cin >> gunP1;
    system("cls");
    return gunP1;
}

int SelectGun2(int& gunP2, string& player2) {

    cout << "================ Gun Type ====================" << endl;
    cout << "|| 1) Heavy Canon     ||   2) Chain Gun     ||" << endl;
    cout << "||    Damage: 50      ||      Damage: 35    ||" << endl;
    cout << "||    Accuracy: 50    ||      Accuracy: 65  ||" << endl;
    cout << "==============================================" << endl;
    cout << player2 << " choose your weapon (1 | 2): ";
    cin >> gunP2;
    system("cls");
    return gunP2;
}

int GunP1(int& gunP1, int& damageP1, int& accP1) {
    if (gunP1 == 1)
    {
        cout << "You choose Heavy Canon." << endl;
        cout << "Heavy but massive damage...";
        damageP1 = 50;
        accP1 = 50;
        Sleep(3000);
        system("cls");
        return damageP1;
        return accP1;
    }
    else {
        cout << "You choose Chain Gun." << endl;
        cout << "Mid-range weapon that never miss...";
        damageP1 = 35;
        accP1 = 65;
        Sleep(3000);
        system("cls");
        return damageP1;
        return accP1;
    }
}

int GunP2(int& gunP2, int& damageP2, int& accP2) {
    if (gunP2 == 1)
    {
        cout << "You choose Heavy Canon." << endl;
        cout << "Heavy but massive damage...";
        damageP2 = 50;
        accP2 = 50;
        Sleep(3000);
        system("cls");
        return damageP2;
        return accP2;
    }
    else {
        cout << "You choose Chain Gun." << endl;
        cout << "Mid-range weapon that never miss...";
        damageP2 = 35;
        accP2 = 65;
        Sleep(3000);
        system("cls");
        return damageP2;
        return accP2;
    }
}

int PlayerTurn(int& firstTurn) {
    cout << "Now we will randomize the draw to know who's turn right now." << endl;
    cout << "If the draw shows 1, then player 1 starts first." << endl;
    cout << "If the draw shows 2, then player 2 starts first." << endl;
    cout << "The one who will go first is..." << endl;
    Sleep(3000);
    if (true)
    {
        mt19937 generator;
        generator.seed(time(0));

        uniform_int_distribution<uint32_t> turn(1, 2);

        int random = turn(generator);

        if (random == 1)
        {
            cout << "Player 1 go first." << endl;
            firstTurn = 1;
            system("pause");
            system("cls");
            return firstTurn;
        }
        else {
            cout << "Player 2 go first." << endl;
            firstTurn = 2;
            system("pause");
            system("cls");
            return firstTurn;
        }
    }
}

int GenerateNum(int& random) {
    mt19937 generator;
    generator.seed(time(0));

    uniform_int_distribution<uint32_t> attack(1, 100);

    random = attack(generator);
    
    return random;
}

int Battle(int& firstTurn, int& random, string& player1, int& hp1, int& damageP1, int& accP1, string& player2, int& hp2, int& damageP2, int& accP2) {
    cout << "----------- LET THE BATTLE BEGIN !!! -----------"<< endl;
    if (firstTurn == 1)
    {
        while (hp1 > 0 && hp2 > 0) {
            cout << "Player 1: " << player1 << endl;
            cout << "Press 'SPACE' to shoot." << endl;
            _getch();
            if (true)
            {
                cout << "BAAAMMM!!!" << endl;
                GenerateNum(random);
                cout << "Player 2 DEFEND <>" << endl;
                if (random < accP2)
                {
                    cout << "DUARR !!! Player 2 deal damage." << endl;
                    hp2 = hp2 - damageP1;
                    if (hp2 < 0)
                    {
                        hp2 = 0;
                        cout << "HP Player 2: " << hp2 << endl;
                    }
                    else
                        cout << "HP Player 2: " << hp2 << endl;
                    
                    Sleep(3000);
                }
                else
                {
                    cout << "MISSED !! Player 2 doesn't deal any damage." << endl;
                    cout << "HP Player 2: " << hp2 << endl;
                    Sleep(3000);
                }
            }
            system("cls");

            cout << "Player 2: " << player2 << endl;
            cout << "Press 'SPACE' to shoot." << endl;
            _getch();
            if (true)
            {
                cout << "BAAAMMM!!!" << endl;
                GenerateNum(random);
                cout << "Player 1 DEFEND <>" << endl;
                if (random < accP1)
                {
                    cout << "DUARR !!! Player 1 deal damage." << endl;
                    hp1 = hp1 - damageP2;
                    if (hp1 < 0)
                    {
                        hp1 = 0;
                        cout << "HP Player 1: " << hp1 << endl;
                    }
                    else
                        cout << "HP Player 1: " << hp1 << endl;
                    Sleep(3000);
                }
                else
                {
                    cout << "MISSED !! Player 1 doesn't deal any damage." << endl;
                    cout << "HP Player 1: " << hp1 << endl;
                    Sleep(3000);
                }
            }
            system("cls");
        }
    }

    else
    {
        while (hp1 > 0 && hp2 > 0) {
            cout << "Player 2: " << player2 << endl;
            cout << "Press 'SPACE' to shoot." << endl;
            _getch();
            if (true)
            {
                cout << "BAAAMMM!!!" << endl;
                GenerateNum(random);
                cout << "Player 1 DEFEND <>" << endl;
                if (random < accP1)
                {
                    cout << "DUARR !!! Player 1 deal damage." << endl;
                    hp1 = hp1 - damageP2;
                    if (hp1 < 0)
                    {
                        hp1 = 0;
                        cout << "HP Player 1: " << hp1 << endl;
                    }
                    else
                        cout << "HP Player 1: " << hp1 << endl;
                    Sleep(3000);
                }
                else
                {
                    cout << "MISSED !! Player 1 doesn't deal any damage." << endl;
                    cout << "HP Player 1: " << hp1 << endl;
                    Sleep(3000);
                }
            }
            system("cls");

            cout << "Player 1: " << player1 << endl;
            cout << "Press 'SPACE' to shoot." << endl;
            _getch();
            if (true)
            {
                cout << "BAAAMMM!!!" << endl;
                GenerateNum(random);
                cout << "Player 2 DEFEND <>" << endl;
                if (random < accP2)
                {
                    cout << "DUARR !!! Player 2 deal damage." << endl;
                    hp2 = hp2 - damageP1;
                    if (hp2 < 0)
                    {
                        hp2 = 0;
                        cout << "HP Player 2: " << hp2 << endl;
                    }
                    else
                        cout << "HP Player 2: " << hp2 << endl;
                    Sleep(3000);
                }
                else
                {
                    cout << "MISSED !! Player 1 doesn't deal any damage." << endl;
                    cout << "HP Player 2: " << hp2 << endl;
                    Sleep(3000);
                }
            }
            system("cls");
        }
        
    }
    return hp1;
    return hp2;
}

int CheckHP(int& hp1, int& hp2, string& player1, string& player2, int& score1, int& score2) 
{
    if (hp1 == 0)
    {
        cout << "============= Congratulation!!! =============" << endl;
        cout << "Player1: " << player1 << " win!!!" << endl;
        score1 ++;
    }
    else {
        cout << "============= Congratulation!!! =============" << endl;
        cout << "Player2: " << player2 << " win!!!" << endl;
        score2++;
    }
    return score1, score2;
}

void ScoreBoard(int& score1, int& score2, string& player1, string& player2) {
    cout << "==============================" << endl;
    cout << "||        SCORE BOARD       ||" << endl;
    cout << "==============================" << endl;
    cout << " Player 1: " << player1 << endl;
    cout << " Score: " << score1 << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << " Player 2: " << player2 << endl;
    cout << " Score: " << score2 << endl;
    cout << "==============================" << endl;
    Sleep(5000);
    system("cls");
}


int main() {

    string p1, p2, decision;
    int hp1, hp2, gunP1, gunP2, damageP1, accP1, damageP2, accP2, score1, score2, firstTurn, random;
    
    score1 = 0;
    score2 = 0;
    
    while (true)
    {
        hp1 = 100;
        hp2 = 100;
        Opening();
        InfoP1(p1);
        InfoP2(p2);
        SelectGun1(gunP1, p1);
        GunP1(gunP1, damageP1, accP1);
        SelectGun2(gunP2, p2);
        GunP2(gunP2, damageP2, accP2);
        Sleep(1000);
        PlayerTurn(firstTurn);
        Battle(firstTurn, random, p1, hp1, damageP1, accP1, p2, hp2, damageP2, accP2);
        CheckHP(hp1, hp2, p1, p2, score1, score2);
        ScoreBoard(score1, score2, p1, p2);

        cout << "Dou you want to play again [Y/ N]? ";
        cin >> decision;
        if (decision == "Y") {
            system("cls");
            continue;
        }
        else
            break;
    }

    return 0;
}