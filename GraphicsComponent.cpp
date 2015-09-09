#include "GraphicsComponent.h"
#include <LuaBridge.h>
#include <iostream>

GraphicsComponent::GraphicsComponent(luabridge::LuaRef& componentTable) {
    using namespace luabridge;
    auto filenameRef = componentTable["filename"];
    if (filenameRef.isString()) {
        filename = filenameRef.cast<std::string>();
    } else {
        std::cout << "Error, GraphicsComponent.filename is not a string!" << std::endl;
    }
}