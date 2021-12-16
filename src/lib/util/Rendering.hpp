#ifndef VIOLET_RENDERING_HPP
#define VIOLET_RENDERING_HPP


namespace Violet {
    class Actor;
    class RenderComponent {
        public:
            RenderComponent() = default;
            RenderComponent(const RenderComponent&) = default;
            RenderComponent(RenderComponent&&) = default;
            virtual ~RenderComponent() {}

            virtual void update(Actor& actor) = 0;
            virtual void draw() = 0;
    };

    class NullRenderComponent: public RenderComponent {
        public:
            virtual void update(Actor& actor) override {}
            virtual void draw() override {}
    };
}
#endif // VIOLET_RENDERING_HPP
