#include "game.h"
#include <sstream>
#include <QTime>
#include <QCoreApplication>
#include <string>
#include <time.h>
#include <stdlib.h>

void create_map(planet *gamePlanet, int seed, int x, int y, std::string name) {
    gamePlanet->name = name;
    gamePlanet->size_x = x;
    gamePlanet->size_y = y;
    // randomize planet surface

}


void gen_name(int seed, std::string *name) {
    char capital[] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    char middle_vocal[] = "aeiou";
    char middle_consonant[] = "bcdfghjklmnpqrstvw   ";


    srand(time(NULL)); // use current time as random seed
    int len_of_name = rand() % 10 + 5;
    int i = 0;
    int vocal = 1;

    while (i < len_of_name) {
        srand(rand());
        if (i == 0) {
            name->push_back(capital[(rand() % 24)]);
            i++;
        }
        else
        {
            if (rand() % 10 >= vocal) {
                name->push_back(middle_vocal[(rand() % 6)]);
                vocal+=4;
                i++;
            }
            else {
                name->push_back(middle_consonant[(rand() % 21)]);
                vocal-=4;
                i++;
            }
        }

    }

}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

std::string intToString(int i) {
    std::string tmp;
    std::stringstream strm;
    strm << i;
    tmp = strm.str();
    return tmp;
}
