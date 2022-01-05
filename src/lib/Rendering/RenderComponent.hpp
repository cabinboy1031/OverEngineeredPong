#ifndef VIOLET_RENDERCOMPONENT_HPP
#define VIOLET_RENDERCOMPONENT_HPP
#include "../Component.hpp"
#include "Rendering.hpp"

namespace Violet {
    class Actor;
    class RenderComponent: public Violet::Component {
        public:
            RenderComponent() = default;
            RenderComponent(Drawable* drawable);
            virtual ~RenderComponent() {}

            virtual void update(Actor& actor) override;
            inline virtual void draw() { m_ComponentDrawable->draw(); }
        private:
            Drawable* m_ComponentDrawable;
    };

    class NullRenderComponent: public RenderComponent {
        public:
            virtual void update(Actor& actor) override {}
    };
}
#endif // VIOLET_RENDERING_HPP
