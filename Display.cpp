#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Display.h"

Display::Display(int width, int height) : display(width, height) {}

void Display::reset() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void Display::clearLine(int line) {
  int y = line * 8;

  for (int x = 0; x < 128; x++) {
    display.setCursor(x, y);
    display.setTextColor(SSD1306_BLACK);
    display.print(F("M"));
  }

  display.display();
  display.setTextColor(SSD1306_WHITE);
}

void Display::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    return;
  }

  reset();
}

void Display::print(String text) {
  reset();
  display.println(text);
  display.display();
}

void Display::printTo(String text, int line) {
  clearLine(line);
  display.setCursor(0, line * 8);
  display.println(text);
  display.display();
}

void Display::printLine(String text) {
  static int y = 0;

  if (y >= display.height()) {
    y = 0;
    display.clearDisplay();
  }

  display.setCursor(0, y);
  display.println(text);
  display.display();

  y += 8;
}