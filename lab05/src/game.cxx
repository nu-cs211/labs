#include "model.hxx"
#include <ge211.hxx>

static ge211::Color const small_color         = ge211::Color::medium_yellow();
static ge211::Color const large_normal_color  = ge211::Color::medium_green();
static ge211::Color const large_collide_color = ge211::Color::medium_red();

// UI object
struct Game : ge211::Abstract_game
{
    ///
    /// Member functions
    ///

    // Controller
    void on_key(ge211::Key) override;
    void on_mouse_move(ge211::Position) override;

    // View
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;

    ///
    /// Member variables
    ///

    // Model
    Model model_;

    // View
    ge211::Circle_sprite large_sprite_collide_{large_radius, large_collide_color};
    ge211::Circle_sprite large_sprite_normal_{large_radius, large_normal_color};
    ge211::Circle_sprite small_sprite_{small_radius, small_color};
};

int main()
{
    Game().run();
}

ge211::Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(ge211::Sprite_set& sprites)
{
    sprites.add_sprite(small_sprite_, model_.small_upper_left());

    switch (model_.get_state()) {
        case Collision_state::touching:
            sprites.add_sprite(large_sprite_collide_,
                               model_.large_upper_left());
            break;

        case Collision_state::not_touching:
            sprites.add_sprite(large_sprite_normal_,
                               model_.large_upper_left());
            break;
    }
}

void Game::on_key(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.move_large_circle_left();
    } else if (key == ge211::Key::right()) {
        model_.move_large_circle_right();
    } else if (key == ge211::Key::code('q')) {
        quit();
    }
}

void Game::on_mouse_move(ge211::Position mouse)
{
    model_.move_small_circle_to(mouse);
}