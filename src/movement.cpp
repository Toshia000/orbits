#include "movement.h"
#include <bn_keypad.h>
#include <bn_display.h>

// Bounds for the movement
static constexpr int UPPER_BOUND = -bn::display::height() / 2;
static constexpr int LOWER_BOUND = bn::display::height() / 2;
static constexpr int LEFT_BOUND = -bn::display::width() / 2;
static constexpr int RIGHT_BOUND = bn::display::width() / 2;

/**
 * Moves sprite up/down/left/right based on the d-pad being held.
 * 
 * Dimensions are moved independently, meaning that diagonal motion is faster than moving in one
 * dimension.
 * 
 * @param sprite the sprite to move
 * @param speed the speed at which to move the sprite in each dimension
 */
void dPadMoveSprite(bn::sprite_ptr& sprite, bn::fixed speed) {
    bn::fixed dx = 0;
    bn::fixed dy = 0;

    if(bn::keypad::left_held() && sprite.x() >= LEFT_BOUND) {
        dx -= speed;
    }
    if(bn::keypad::right_held() && sprite.x() <= RIGHT_BOUND) {
        dx += speed;
    }
    if(bn::keypad::up_held() && sprite.y() >= UPPER_BOUND) {
        dy -= speed;
    }
    if(bn::keypad::down_held() && sprite.y() <= LOWER_BOUND) {
        dy += speed;
    }

    sprite.set_position(sprite.position() + bn::fixed_point(dx, dy));
};