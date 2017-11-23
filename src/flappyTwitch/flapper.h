#ifndef FLAPPER_H
#define FLAPPER_H

#include "src/engine/graphics/sprite.h"
#include "src/engine/Physics/rigidbody.h"
#include "src/engine/engine.h"

class Flapper
{
public:
    Flapper();
    Flapper(Engine *engine, Sprite *sprite);

    void update();
    void render();

    Sprite &getSprite();
    Rigidbody &getRb();

private:
    Sprite *m_sprite;
    Rigidbody m_rb;
};

#endif // FLAPPER_H
