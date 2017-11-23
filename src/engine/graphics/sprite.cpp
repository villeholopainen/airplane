#include "sprite.h"

Sprite::Sprite(Engine *engine)
{
    initialize(engine,
               Texture(),
               Vector3(0),
               0,
               100,
               Vector3(1),
               Vector3(0));
}

Sprite::Sprite(Engine *engine, const std::string &imagePath)
{
    Texture t = Texture(imagePath);
    initialize(engine,
               t,
               Vector3(0),
               0,
               100,
               Vector3(1),
               Vector3(t.getWidth(), t.getHeight(), 1));
}

Sprite::Sprite(Engine *engine, const std::string &imagePath, Vector3 v)
{
    Texture t = Texture(imagePath);
    initialize(engine,
               t,
               v,
               0,
               100,
               Vector3(1),
               Vector3(t.getWidth(), t.getHeight(), 1));
}

void Sprite::initialize(Engine *engine,
                        Texture texture,
                        Vector3 v,
                        float rot,
                        float speed,
                        Vector3 scale,
                        Vector3 size)
{
    m_engine = engine;
    m_texture = texture;
    m_pos = v;
    m_rot = rot;
    m_speed = speed;
    m_scale = scale;
    m_size = size;
}

void Sprite::update()
{

}

void Sprite::render()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_texture.getId());
    glLoadIdentity();

    // Translate -> rotate -> scale
    glTranslatef(m_pos.m_x, m_pos.m_y, 0);
    glRotatef(m_rot, 0, 0, 1);
    glScalef(m_scale.m_x, m_scale.m_y, 1);

    // rendering
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);

    glTexCoord2i(0, 0); glVertex2f(0,                       0);
    glTexCoord2i(1, 0); glVertex2f(m_texture.getWidth(),    0);
    glTexCoord2i(1, 1); glVertex2f(m_texture.getWidth(),    m_texture.getHeight());
    glTexCoord2i(0, 1); glVertex2f(0,                       m_texture.getHeight());
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Sprite::speedTo(float x)
{
    m_speed = x;
}

void Sprite::speedBy(float x)
{
    m_speed += x;
}

void Sprite::moveTo(Vector3 v)
{
    m_pos = v;
}

void Sprite::moveBy(Vector3 v)
{
    m_pos = m_pos + (v * m_engine->getDeltaTime());
}

void Sprite::moveLeft()
{
    m_pos = m_pos - Vector3((m_speed * m_engine->getDeltaTime()), 0, 0);
}

void Sprite::moveRight()
{
    m_pos = m_pos + Vector3((m_speed * m_engine->getDeltaTime()), 0, 0);
}

void Sprite::moveUp()
{
    m_pos = m_pos + Vector3(0, (m_speed * m_engine->getDeltaTime()), 0);
}

void Sprite::moveDown()
{
    m_pos = m_pos - Vector3(0, (m_speed * m_engine->getDeltaTime()), 0);
}

void Sprite::rotateTo(float x)
{
    m_rot = x;
}

void Sprite::rotateBy(float x)
{
    m_rot += x * m_engine->getDeltaTime();
}

void Sprite::setScale(float x)
{
    m_scale = Vector3(x);
}

void Sprite::setScale(Vector3 v)
{
    m_scale = v;
}

Vector3 *Sprite::getPos()
{
    return &m_pos;
}

float *Sprite::getRot()
{
    return &m_rot;
}

Vector3 *Sprite::getScale()
{
    return &m_scale;
}

Vector3 *Sprite::getSize()
{
    return &m_size;
}
