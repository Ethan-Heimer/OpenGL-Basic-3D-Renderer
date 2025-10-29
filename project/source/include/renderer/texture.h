#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace Renderer{
    using TextureID = unsigned int;
    class Texture{
        public:
            Texture(std::string imagePath);
            ~Texture();

            void Use();
            void Delete();

        private:
            TextureID texture;
            bool deleted = false;
    };
}

#endif
