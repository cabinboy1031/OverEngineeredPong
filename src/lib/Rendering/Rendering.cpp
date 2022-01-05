#include "Rendering.hpp"
#include <iostream>
#include <algorithm>

Violet::Drawable::Drawable(Renderer* renderer){
    if(renderer == nullptr){
        std::cerr << "ERROR: No valid renderer given." << std::endl;
        throw -1;
    }

    renderer->addDrawable(this);
}

void Violet::Renderer::addDrawable(Drawable *drawable){
    m_DrawableList.push_back(drawable);
}

void Violet::Renderer::removeDrawable(Drawable* drawable){
    auto found = std::find(m_DrawableList.begin(), m_DrawableList.end(), drawable);
    if(found != std::end(m_DrawableList)){
        m_DrawableList.erase(found);
    } else {
        std::cerr << "Game object " << drawable << " was not found in the renderQueue. Was it already removed?" << std::endl;
    }
}
