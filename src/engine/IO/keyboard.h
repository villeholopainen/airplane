#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <GLFW/glfw3.h>

class Keyboard
{
public:
    static void keyCallback(GLFWwindow *window, int key, int scanmode, int action, int mods);
    static bool keyDown(int key);
    static bool keyUp(int key);
    static bool key(int key);
private:
    static bool keys[];
    static bool keysDown[];
    static bool keysUp[];
};

#endif // KEYBOARD_H
