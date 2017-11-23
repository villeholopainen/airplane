#include "engine.h"
#include "src/engine/IO/mouse.h"
#include "src/engine/IO/keyboard.h"
#include <iostream>

Engine::Engine()
{
    m_window = nullptr;
}

Engine::~Engine()
{
    glfwDestroyWindow(m_window);
}

bool Engine::initialize(const std::string &windowTitle)
{
    if (!glfwInit()) {
        std::cout << "Error initializing glfw" << std::endl;
        return false;
    }

    m_window = glfwCreateWindow(m_width,
                                m_height,
                                windowTitle.c_str(),
                                NULL,
                                NULL);
    if (m_window == nullptr) {
        std::cout << "Error creating window" << std::endl;
        return false;
    }

    //opengl setup
    glfwMakeContextCurrent(m_window);
    int width, height;
    glfwGetFramebufferSize(m_window, &width, &height);
    glfwSwapInterval(1);

    glfwSetCursorPosCallback(m_window, Mouse::MousePosCallback);
    glfwSetMouseButtonCallback(m_window, Mouse::mouseButtonCallback);
    glfwSetKeyCallback(m_window, Keyboard::keyCallback);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - m_width / 2);
    int yPos = (mode->height - m_height / 2);
    glfwSetWindowPos(m_window, xPos, yPos);

    // GL Setup
    // Viewport (Camera)
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);

    // Alpha Blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_lastTime = (float)glfwGetTime();

    return true;
}

void Engine::update()
{
    double now = (float)glfwGetTime();
    m_dt = (now - m_lastTime);
    m_lastTime = now;

    glfwPollEvents();
}

void Engine::beginRender()
{
    glClearColor(0, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

}

void Engine::endRender()
{
    glfwSwapBuffers(m_window);
}

void Engine::setScreenWidth(int width)
{
    m_width = width;
}

int Engine::getScreenWidth() const
{
    return m_width;
}

void Engine::setScreenHeight(int height)
{
    m_height = height;
}

int Engine::setScreenWidth()
{
    return m_height;
}

void Engine::setDeltaTime(float dt)
{
    m_dt = dt;
}

float Engine::getDeltaTime()
{
    return m_dt;
}
