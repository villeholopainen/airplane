#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

class Mouse
{
public:
    static void MousePosCallback(GLFWwindow *window,
                          double x,
                          double y);
    static void mouseButtonCallback(GLFWwindow *window,
                             int button,
                             int action,
                             int mods);
    static double GetMouseX();
    static double GetMouseY();
    static bool ButtonDown(int button);
    static bool ButtonUp(int button);
    static bool Button(int button);

private:
    static double m_x;
    static double m_y;
    static bool buttons[];
    static bool buttonsDown[];
    static bool buttonsUp[];
    static int m_mousebutton;
};

#endif // MOUSE_H
