#include "model.h"

#include <ge211.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace ge211;
using namespace std;

Color const color_green = Color::medium_green();
Color const color_red   = Color::medium_red();

// UI Object

Dimensions const square_dimension{15,15};

struct Game : Abstract_game
{
    ///
    /// Member functions
    ///

    // Controller
    void on_key(Key key) override;
    void on_mouse_move(Position mouse) override;

    // View
    void draw(Sprite_set& sprites) override;
    Dimensions initial_window_dimensions() const override;

    ///
    /// Member variables
    ///

    // Model
    Model model;

    // View
    Circle_sprite circle_red{circle_radius, color_red};
    Circle_sprite circle_green{circle_radius, color_green};
    Rectangle_sprite square_sprite{square_dimension, color_green};
};

int main()
{
    Game{}.run();
}

Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(Sprite_set& sprites)
{    
    sprites.add_sprite(square_sprite, model.square_position);
    switch (model.state)
    {
        case Collision_state::touching:
            sprites.add_sprite(circle_red, model.circle_position);
            break;
        case Collision_state::not_touching:
            sprites.add_sprite(circle_green, model.circle_position);
            break;
    }
}

void Game::on_key(Key key)
{
    if (key==Key::left()) {
        model.move_circle_left();
    } else if (key==Key::right()) {
        model.move_circle_right();
    }
}

void Game::on_mouse_move(Position mouse)
{
    model.move_square_to(mouse);
}


