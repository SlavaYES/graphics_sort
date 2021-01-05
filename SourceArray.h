#ifndef FIRST_TEST_SOURCEARRAY_H
#define FIRST_TEST_SOURCEARRAY_H
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

class SourceArray {
public:
    enum FLAG {
        RANDOM, ASC, DEC
    };
    struct Arr {
        int x, y;
        RectangleShape rectangle;
    };
private:
    Arr *value = nullptr;
    float weight;
    int size;
    enum FLAG flag;
    long uspeed;
public:
    SourceArray(RenderWindow &win);
    SourceArray(RenderWindow &win, int size);
    SourceArray(RenderWindow &win, int size, enum FLAG);
    void draw(RenderWindow &win);
    int getSize();
    Arr getValue(int i);
    void setValue(int i, Arr value);
    void setColor(int i, Color);
    int getUspeed();
    void setUspeed(long uspeed);
private:
    void fill();
    void initUspeed();
};
#endif