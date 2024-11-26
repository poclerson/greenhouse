#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

class Display {
  public:
    Display(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
    void begin();
    void reset();
    void clearLine(int line);
    void print(String text);
    void printLine(String text);
    void printTo(String text, int line);
    Adafruit_SSD1306 display;
};

#endif