#pragma once

#include "ball.h"
#include "brick.h"
#include "globals.h"
#include "player.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <iostream>
#include <math.h>
#include <random>
#include <stdbool.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

struct PointModifier {
  int time = 2;
  int brick = 500;
  int level = 10000;
  int ball = -500;
};

class Game {
private:
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_FONT *font;
  bool redraw = false;
  bool running = true;
  bool paused = false;
  int level = 1;
  int score = 0;
  int life = 4;
  Ball *ball;
  Player *player;
  std::vector<Brick *> bricks;
  void init();
  void loop();
  void detectCollisions();
  void loadBricks();
  PointModifier* points = new PointModifier;

public:
  Game();
  ~Game();
};
