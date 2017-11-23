#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "src/engine/engine.h"
#include "src/engine/graphics/texture.h"
#include "src/engine/Math/vector3.h"

class Sprite
{
public:
    Sprite(Engine *engine);
    Sprite(Engine *engine, const std::string &imagePath);
    Sprite(Engine *engine,
           const std::string &imagePath,
           Vector3 v);
    void update();
    void render();

    void speedTo(float x);
    void speedBy(float x);

    void moveTo(Vector3 v);
    void moveBy(Vector3 v);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void rotateTo(float x);
    void rotateBy(float x);

    void setScale(float x);
    void setScale(Vector3 v);

    Vector3 *getPos();
    float *getRot();
    Vector3 *getScale();
    Vector3 *getSize();

private:
    Engine *m_engine;
    Texture m_texture;

    float m_speed;
    float m_rot;

    Vector3 m_pos;
    Vector3 m_scale;
    Vector3 m_size;

    void initialize(Engine *engine, Texture texture, Vector3 v, float rot, float speed, Vector3 scale, Vector3 size);
};

#endif // SPRITE_H
