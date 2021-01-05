#include <SFML/Graphics.hpp>
#include "SourceArray.h"
#include <unistd.h>
using namespace sf;

void sort(SourceArray arr, RenderWindow &win);
void recolor(SourceArray arr, int i, int num, Color color);
void endColor(SourceArray arr, RenderWindow &win);

int main() {
    RenderWindow window(VideoMode(1900, 800), "");

    SourceArray recs(window);

    sort(recs, window);

    endColor(recs, window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed
                || event.type == Event::KeyPressed
                || event.type == Event::MouseButtonPressed) {
                window.close();
            }
        }
    }

    return 0;
}

void sort(SourceArray arr, RenderWindow &win) {
    for (int i = 0; i < arr.getSize() - 1; i++) {
        int min = arr.getValue(i).y;
        int num = i;
        for (int j = i + 1; j < arr.getSize(); j++) {
            if (min > arr.getValue(j).y) {
                min = arr.getValue(j).y;
                num = j;
                arr.setColor(j, Color::Red);
            } else {
                arr.setColor(j, Color::Green);
            }
            arr.draw(win);
            arr.setColor(j, Color::Blue);
        }

        SourceArray::Arr tmp = arr.getValue(num);
        arr.setValue(num, arr.getValue(i));
        arr.setValue(i, tmp);

        recolor(arr, i, num, Color::Magenta);
        arr.draw(win);
        recolor(arr, i, num, Color::Blue);
    }
}

void recolor(SourceArray arr, int i, int num, Color color) {
    arr.setColor(i, color);
    arr.setColor(num, color);
}

void endColor(SourceArray arr, RenderWindow &win) {
    for (int i = 0; i < arr.getSize(); i++) {
        arr.setColor(i, Color::White);
        arr.draw(win);
    }
}