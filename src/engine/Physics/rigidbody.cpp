#include "rigidbody.h"

Rigidbody::Rigidbody()
{
    m_engine = 0;
    m_friction = 1;
    m_gravity = 0;
}

void Rigidbody::initialize(Engine *engine,
                           float friction,
                           float gravity,
                           Vector3 *pos,
                           float *rot,
                           Vector3 *scale, Vector3 *size)
{
    m_engine = engine;
    m_friction = friction;
    m_gravity = gravity;
    m_pos = pos;
    m_rot = rot;
    m_scale = scale;
    m_size = size;
}

void Rigidbody::update()
{
    m_vel.m_x *= m_friction;
    m_vel.m_y += m_gravity;

    *m_pos = *m_pos + (m_vel * m_engine->getDeltaTime());
}

void Rigidbody::render(Vector3 c)
{
    glLoadIdentity();
    glTranslatef(m_pos->m_x, m_pos->m_y, m_pos->m_z);
    glRotatef(*m_rot, 0, 0, 1);
    glScalef(m_scale->m_x, m_scale->m_y, m_scale->m_z);

    glColor4f(c.m_x, c.m_y, c.m_z, 1);
    glBegin(GL_LINES);
    {
        glVertex2i(0,               0);
        glVertex2i(m_size->m_x,     0);
        glVertex2i(m_size->m_x,     m_size->m_y);
        glVertex2i(0,               m_size->m_y);
        glVertex2i(m_size->m_x,     m_size->m_y);
        glVertex2i(m_size->m_x,     0);
        glVertex2i(0,               0);
    }
    glEnd();
}

void Rigidbody::addForce(Vector3 f)
{
    m_vel = m_vel + f;
}
