#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
//#include "glfw-3.2.1/include/GLFW/glfw3.h"

#include <string>

class Engine
{
public:
    Engine();
    ~Engine();

    bool initialize(const std::string &windowTitle);
    void update();
    void beginRender();
    void endRender();

    void setScreenWidth(int width);
    int getScreenWidth() const;

    void setScreenHeight(int height);
    int setScreenWidth();

    void setDeltaTime(float dt);
    float getDeltaTime();
private:
    int m_width;
    int m_height;
    GLFWwindow *m_window;
    float m_dt;
    float m_lastTime;
};

#endif
