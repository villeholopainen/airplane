#ifndef TEXTURE_H
#define TEXTURE_H

//#include <GLFW/glfw3.h>
#include <string>
#include "SOIL.h"

class Texture
{
public:
    Texture();
    Texture(int id);
    Texture(const std::string &path);

    int getId() const;
    int getWidth() const;
    int getHeight() const;
private:
    bool getTextureParams();

    int m_id;
    int m_width;
    int m_height;
};

#endif // TEXTURE_H
