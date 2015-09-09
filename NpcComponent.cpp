#include "NpcComponent.h"
#include <LuaBridge.h>
#include <iostream>

NpcComponent::NpcComponent(luabridge::LuaRef& NpcTable) {
    using namespace luabridge;
    auto phraseRef = NpcTable["phrase"];
    if (phraseRef.isString()) {
        phrase = phraseRef.cast<std::string>();
    } else {
        std::cout << "Error, NpcComponent.phrase is not a string!" << std::endl;
    }
}