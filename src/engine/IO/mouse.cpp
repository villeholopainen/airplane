#include "mouse.h"
#include <iostream>
#include <string>

double Mouse::m_x = 0;
double Mouse::m_y = 0;
int Mouse::m_mousebutton = 0;
bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow *window, double x, double y)
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    m_x = x;
    m_y = height - y;
}

void Mouse::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button < 0) {
        return;
    }

    if (action != GLFW_RELEASE && buttons[button] == false) {
        buttonsDown[button] = true;
        buttonsUp[button] = false;
    }

    if (action != GLFW_RELEASE && buttons[button] == true) {
        buttonsDown[button] = false;
        buttonsUp[button] = true;
    }

    buttons[button] = action != GLFW_RELEASE;
}

double Mouse::GetMouseX()
{
    return m_x;
}

double Mouse::GetMouseY()
{
    return m_y;
}

bool Mouse::ButtonDown(int button)
{
    bool x = buttonsDown[button];
    buttonsDown[button] = false;
    return x;
}

bool Mouse::ButtonUp(int button)
{
    if (button != m_mousebutton) {
        std::cout << "button changed to: " << std::to_string(m_mousebutton) << std::endl;
        m_mousebutton = button;
    }
    bool x = buttonsUp[button];
    buttonsUp[button] = false;
    return x;
}

bool Mouse::Button(int button)
{
    return buttons[button];
}
