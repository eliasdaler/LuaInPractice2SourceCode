#pragma once

#include <string>
#include "Component.h"

class GraphicsComponent : public Component {
public:
    GraphicsComponent(luabridge::LuaRef& componentTable);

    void setFilename(const std::string& filename) {
        this->filename = filename;
    }
    
    std::string getFilename() const {
        return filename;
    }
private:
    std::string filename;
};