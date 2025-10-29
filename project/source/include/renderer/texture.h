#ifndef TEXTURE_H
#define TEXTURE_H

namespace Renderer{
    using TextureID = unsigned int;
    class Texture{
        public:
            Texture();
            ~Texture();

        private:
            TextureID texture;
    };
}

#endif
