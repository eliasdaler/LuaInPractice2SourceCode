#pragma once

#include <string>
#include "Component.h"

class NpcComponent : public Component {
public:
    NpcComponent(luabridge::LuaRef& componentTable);

    void setPhrase(const std::string& phrase) {
        this->phrase = phrase;
    }

    std::string getPhrase() const {
        return phrase;
    }
private:
    std::string phrase;
};