#include "texture.h"
#include <iostream>

Texture::Texture()
{
    m_id = -1;
}

Texture::Texture(int id)
{
    m_id = id;
}

Texture::Texture(const std::string &path)
{
    m_id = SOIL_load_OGL_texture(path.c_str(),
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_MULTIPLY_ALPHA|SOIL_FLAG_INVERT_Y);
    std::cout << "loading texture returned: " << std::to_string(m_id) << std::endl;
    if (!getTextureParams()) {
        std::cout << "Error loading image: " << path << std::endl;
    }
}

bool Texture::getTextureParams()
{
    if (m_id > 0) {
        int mipLevel = 0;
        glBindTexture(GL_TEXTURE_2D, m_id);
        glGetTexLevelParameteriv(GL_TEXTURE_2D,
                                 mipLevel,
                                 GL_TEXTURE_WIDTH,
                                 &m_width);
        glGetTexLevelParameteriv(GL_TEXTURE_2D,
                                 mipLevel,
                                 GL_TEXTURE_HEIGHT,
                                 &m_height);
        return true;
    }
    return false;
}

int Texture::getId() const
{
    return m_id;
}

int Texture::getWidth() const
{
    return m_width;
}

int Texture::getHeight() const
{
    return m_height;
}
