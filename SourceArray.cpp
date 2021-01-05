#include <unistd.h>
#include "SourceArray.h"

SourceArray::SourceArray(RenderWindow &win) {
    srand(time(NULL));
    flag = RANDOM;
    size = 100;
    value = new struct Arr[size];
    weight = win.getSize().x / size - 1;
    if (weight < 1) {
        throw;
    }
    initUspeed();
    fill();
}

SourceArray::SourceArray(RenderWindow &win, int size) {
    srand(time(NULL));
    flag = RANDOM;
    this->size = size;
    value = new struct Arr[size];
    weight = 2;
    initUspeed();
    fill();
}

SourceArray::SourceArray(RenderWindow &win, int size, enum FLAG flag) {
    srand(time(NULL));
    this->flag = flag;
    this->size = size;
    value = new struct Arr[size];
    weight = 2;
    initUspeed();
    fill();
}

void SourceArray::initUspeed() {
    if (size <= 30) {
        uspeed = 100000;
    } else if (size > 30){
        uspeed = 100000 / pow(10, log10(size));
    } else if (size > 999) {
        return;
    }
}

void SourceArray::fill() {
    switch (flag) {
        case RANDOM:
            for (int i = 0; i < size; i++) {
                value[i].y = rand() % 800;
            }
            break;
        case ASC:
            for (int i = 0; i < size; i++) {
                value[i].y = i + 1;
            }
            break;
        case DEC:
            for (int i = 0; i < size; i++) {
                value[i].y = 800 - i + 1;
            }
            break;
    }
    for (int i = 0; i < size; i++) {
        value[i].x = i * (weight + 1);
        value[i].rectangle.setPosition((float) value[i].x, 800 - value[i].y);
        value[i].rectangle.setSize(Vector2f(weight, value[i].y));
        value[i].rectangle.setFillColor(Color::Blue);
    }
}

void SourceArray::draw(RenderWindow &win) {
    win.clear();
    for (int i = 0; i < size; i++) {
        win.draw(value[i].rectangle);
    }
    win.display();
    usleep(uspeed);
}

int SourceArray::getSize() {
    return size;
}

SourceArray::Arr SourceArray::getValue(int i) {
    return value[i];
}

void SourceArray::setValue(int i, SourceArray::Arr element) {
    value[i].y = element.y;
    value[i].rectangle.setSize(Vector2f(weight, value[i].y));
    value[i].rectangle.setPosition((float)value[i].x, 800 - value[i].y);
}

void SourceArray::setColor(int i, Color color) {
    value[i].rectangle.setFillColor(color);
}

int SourceArray::getUspeed() {
    return uspeed;
}

void SourceArray::setUspeed(long uspeed) {
    this->uspeed = uspeed;
}