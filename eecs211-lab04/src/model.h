#pragma once

#include <ge211.h>

ge211::Dimensions const scene_dimensions{1024, 768};
int const circle_radius = 30;

// MODEL DATA DEFINITIONS
struct Model
{
    ge211::Position circle_position{scene_dimensions.width/2, scene_dimensions .height/2};
    ge211::Position square_position{scene_dimensions.width/2, scene_dimensions.height/2};

    enum State{red,green} circle_state = red;

    void update(double dt);
    void move_left ();
    void move_right ();
};
