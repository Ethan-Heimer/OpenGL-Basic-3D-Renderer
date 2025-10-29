#ifndef COLOR_H
#define COLOR_H

namespace Utils{
    enum TextColor{
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        PURPLE,
        CYAN,
        WHITE
    };

    class Color{
        public:
            static const char* TextColor(TextColor color);
            
        private:
            static const char* ASNIColorCodes[];
    };
}

#endif
