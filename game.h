#ifndef OBJECTS
#define OBJECTS

#include <vector>
#include <iostream>

class rover {
    int x;
    int y;
public:
    int speed;
    int direction;
};

class planet {
public:
    int size_x;
    int size_y;
    std::string name;

};

struct ground {
    int x;
    int y;
public:
    std::string description;
};

class rock {
    int x;
    int y;
public:
    std::vector<std::string> descriptions;
};

class mineral {
    int x;
    int y;
public:
    std::vector<std::string> descriptions;
};

class map {
    const static int x = 200;
    const static int y = 200;
    int time;
public:
    int temperature[x][y];
    int gravity[x][y];
};

// functions

void create_map(planet *gamePlanet, int seed, int x, int y, std::string name);

void gen_name(int seed, std::string *name_string);

void delay();

std::string intToString(int i);

// extern variables


#endif // OBJECTS

