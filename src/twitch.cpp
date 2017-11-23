#include <iostream>
#include "src/engine/engine.h"
#include "src/engine/graphics/sprite.h"
#include "src/engine/IO/mouse.h"
#include "src/engine/IO/keyboard.h"
#include "src/engine/Math/vector3.h"
#include "src/flappytwitch/flapper.h"

int main()
{
	std::cout << "Engine executed" << std::endl;

    Engine engine;
    engine.setScreenHeight(768);
    engine.setScreenWidth(1024);
    if (!engine.initialize("Twitch")) {
        std::cout << "Error in initialization" << std::endl;
        return 1;
    }

    std::string imagePath = "D:/temp/shipit/Twitch/src/assets/art/Biplane.png";
    Sprite sprite(&engine,
                  imagePath,
                  Vector3(100, 100, 0)
                  );
    sprite.setScale(0.25f);

    Flapper player(&engine, &sprite);

    bool run = true;
    int lastMouseBtnPressed = GLFW_MOUSE_BUTTON_LEFT;

    while (run) {
        engine.update();
        player.update();

        //sprite.moveTo((float)Mouse::GetMouseX(),
        //              (float)Mouse::GetMouseY());
        if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
            player.getSprite().rotateBy(100);
            lastMouseBtnPressed = GLFW_MOUSE_BUTTON_LEFT;
        }
        if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
            player.getSprite().rotateBy(-100);
            lastMouseBtnPressed = GLFW_MOUSE_BUTTON_RIGHT;
        }
        if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE)) {
            if (lastMouseBtnPressed == GLFW_MOUSE_BUTTON_RIGHT) {
                player.getSprite().rotateBy(-100);
            } else {
                player.getSprite().rotateBy(100);
            }
        }

        if (Keyboard::key(GLFW_KEY_W)) {
            player.getRb().addForce(Vector3(0, 20, 0));
            player.getSprite().rotateBy(20);
        }
        if (Keyboard::key(GLFW_KEY_S)) {
            player.getRb().addForce(Vector3(0, -20, 0));
            player.getSprite().rotateBy(-10);
        }
        if (Keyboard::key(GLFW_KEY_A)) {
            player.getRb().addForce(Vector3(-200, 0, 0));
        }
        if (Keyboard::key(GLFW_KEY_D)) {
            player.getRb().addForce(Vector3(200, 0, 0));
        }
        if (Keyboard::key(GLFW_KEY_ESCAPE)) {
            run = false;
        }

        engine.beginRender();
        player.render();
        engine.endRender();
    }
*/
    return 0;
}
