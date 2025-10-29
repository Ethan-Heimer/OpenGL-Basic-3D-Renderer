#define STB_IMAGE_IMPLEMENTATION
#include "renderer/texture.h"
#include "glad/glad.h"
#include "Image/stb_image.h"
#include "utils/color.h"
#include "utils/error.h"

using namespace Renderer;

Texture::Texture(std::string imagePath){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    //SET TEXTURE PROPERTIES
    //TEXTURE WRAP
    //SET S CORDINATE WRAP TO REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //SET T CORDINATE WRAP TO REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //TEXTURE RESIZING
    //SET TEXTURE MINIMIZE FILTER
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    //SET TEXTURE MAGNIFY FILTER
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);

    unsigned int channelType = GL_RGB;
    if(nrChannels == 4){
        channelType = GL_RGBA;
    }

    if (data){
        //the first channeltype arg represents how many color channels are in 
        //the texture
        
        //the second chenneltype arg represents the format of the channel data,
        //ex (RGBA VS BRGA)
        glTexImage2D(GL_TEXTURE_2D, 0, channelType, width, height, 0, channelType,
        GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        Utils::Errors::DisplayError("Texture Error", Utils::RED, "Failed To Load Texture");
    }

    stbi_image_free(data);
}

void Texture::Use(){
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::Delete(){
    if(deleted)
        return;

    glDeleteTextures(1, &texture);
    deleted = true;
}

Texture::~Texture(){
   Delete(); 
}
