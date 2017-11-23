#include "flapper.h"

Flapper::Flapper()
{

}

Flapper::Flapper(Engine* engine, Sprite *sprite)
{
    m_sprite = sprite;
    m_rb.initialize(engine,
                    0.9f,
                    -2,
                    sprite->getPos(),
                    sprite->getRot(),
                    sprite->getScale(),
                    sprite->getSize());
}

void Flapper::update()
{
    m_sprite->update();
    m_rb.update();
}

void Flapper::render()
{
    m_sprite->render();
    m_rb.render(Vector3(0, 0, 0));
}

Sprite& Flapper::getSprite()
{
    return *m_sprite;
}

Rigidbody& Flapper::getRb()
{
    return m_rb;
}
