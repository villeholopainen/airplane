#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "src/engine/engine.h"
#include "src/engine/Math/vector3.h"

class Rigidbody
{
public:
    Rigidbody();

    void initialize(Engine *engine,
                    float friction,
                    float gravity,
                    Vector3 *pos,
                    float *rot,
                    Vector3 *scale,
                    Vector3 *size);
    void update();
    void render(Vector3 c);

    void addForce(Vector3 f);

private:
    Engine *m_engine;
    Vector3 *m_pos;
    float *m_rot;
    Vector3 *m_scale;
    Vector3 *m_size;

    float m_gravity;
    float m_friction;
    Vector3 m_vel;
};

#endif // RIGIDBODY_H
