#include "game.h"
#include <sstream>
#include <QTime>
#include <QCoreApplication>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

float Interpolate(float x0, float x1, float alpha)
{
   return x0 * (1 - alpha) + alpha * x1;
}

void create_map(planet *gamePlanet, int seed, int x, int y, std::string name) {
    gamePlanet->name = name;

    // create topography
    // initialize some map thing for testing
    int planetWidth = gamePlanet->size_x;
    int planetHeight = gamePlanet->size_y;
    // Perlin Noise?
    int octaves = 6;
    float octave[octaves][planetWidth][planetHeight];
    //initialize Random map
    for(int i = 0; i< planetWidth; i++){
        for(int j = 0; j < planetHeight; j++){
            gamePlanet->map[i][j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        }
    }
    for(int i = 0; i < octaves; i++){
        float period = pow(2,(i+1));
        float frequency = 1/period;

        for (int j = 0; j < planetWidth; j++){
            //sampling indices
            int sample_j0 = int(j / period) * period;
            int sample_j1 = int(sample_j0 + period) % (planetWidth); //wrap around???
            float horizontal_blend = float(j - sample_j0) * frequency;

            for (int k = 0; k < planetHeight; k++){
                //sampling indices
                int sample_k0 = int(k / period) * period;
                int sample_k1 = static_cast <int> (sample_k0 + period) % planetHeight; //wrap around???
                float vertical_blend = float(k - sample_k0) * frequency;

                //blend top two corners
                float top = Interpolate(gamePlanet->map[sample_j0][sample_k0],gamePlanet->map[sample_j1][sample_k0],horizontal_blend);

                //blend bottom two corners
                float bottom = Interpolate(gamePlanet->map[sample_j0][sample_k1],gamePlanet->map[sample_j1][sample_k1],horizontal_blend);

                octave[i][j][k] = Interpolate(top,bottom,vertical_blend);

            }
        }

    }

    // blend octaves
    for(int i = 0; i < planetWidth; i++){
        for(int j = 0; j < planetHeight; j++){
            for(int k = 0; k < octaves; k++){
                gamePlanet->map[i][j] += octave[k][i][j] * pow(1,k);
            }
            gamePlanet->map[i][j]/=octaves + 1;

        }
    }


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

void delay(int time)
{
    QTime dieTime= QTime::currentTime().addSecs(time);
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
