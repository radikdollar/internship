// Улыбка -> сердечко -> грустный смайлик

#include <FastLED.h>

#define LED_PIN     6   // data in (пин к которому подключена матрица)
#define WIDTH       8
#define HEIGHT      8
#define NUM_LEDS    (WIDTH * HEIGHT)
#define BRIGHTNESS  40

CRGB leds[NUM_LEDS];

// Картинки задаём как массив 8x8 из 0 и 1: 1 - светодиод горит, 0 - выключен
const byte smileImg[HEIGHT][WIDTH] = {
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,1,0,0,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0}
};

const byte heartImg[HEIGHT][WIDTH] = {
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0}
};

const byte sadImg[HEIGHT][WIDTH] = {
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,1,0,0,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,1,0,0,1,1,0},
  {0,0,1,1,1,1,0,0}
};

// Переводит координаты (x, y) клетки матрицы в номер светодиода в массиве leds[].
// разворачивает змейку внутри себя, поэтому индекс считается просто построчно.
int XY(int x, int y) {
  return y * WIDTH + x;
}

// Рисует массив заданным цветом
void drawImage(const byte img[HEIGHT][WIDTH], CRGB color) {
  FastLED.clear();
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (img[y][x] == 1) {
        leds[XY(x, y)] = color;
      }
    }
  }
  FastLED.show();
}

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  drawImage(smileImg, CRGB::Yellow);
  delay(1500);

  drawImage(heartImg, CRGB::Red);
  delay(1500);

  drawImage(sadImg, CRGB::Blue);
  delay(1500);
}
