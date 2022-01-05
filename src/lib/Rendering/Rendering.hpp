#ifndef VIOLET_RENDERING_HPP
#define VIOLET_RENDERING_HPP
#include <vector>
#include "raylib.h"

namespace Violet {
    class Renderer;

    class Drawable {
        public:
            Drawable() = default;
            Drawable(Renderer* renderer);
            virtual ~Drawable() {};
            virtual void submit(Transform& transform) = 0;
            virtual void draw() = 0;
    };

    class Renderer {
        public:
            void addDrawable(Drawable* drawable);
            void removeDrawable(Drawable* drawable);

            virtual void BeginRender();
            virtual void draw();
            virtual void EndRender();
        private:
            std::vector<Drawable*> m_DrawableList;
    };
}
#endif // VIOLET_RENDERING_HPP
