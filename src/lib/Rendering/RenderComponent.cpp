#include "RenderComponent.hpp"
#include "../Actor.hpp"

Violet::RenderComponent::RenderComponent(Drawable* drawable){
    this->m_ComponentDrawable = drawable;
}

void Violet::RenderComponent::update(Violet::Actor &actor){
    m_ComponentDrawable->submit(actor.getTransform());
}
