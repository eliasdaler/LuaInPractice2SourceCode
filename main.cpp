#include <iostream>
#include <string>
#include "LuaHelperFunctions.h"

#include "GraphicsComponent.h"
#include "NpcComponent.h"
#include "Entity.h"

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

#include <LuaBridge.h>


template <typename T>
void addComponent(Entity* e, luabridge::LuaRef& componentTable) {
    e->addComponent(std::type_index(typeid(T)), new T(componentTable));
}

Entity* loadEntity(lua_State* L, const std::string& type) {
    using namespace luabridge;
    auto e = new Entity();
    e->setType(type);
    auto v = luah::getTableKeys(L, type);
    LuaRef entityTable = getGlobal(L, type.c_str());
    for (auto& componentName : v) {
        if (componentName == "GraphicsComponent") {
            LuaRef gcTable = entityTable["GraphicsComponent"];
            addComponent<GraphicsComponent>(e, gcTable);
        } else if (componentName == "NpcComponent") {
            LuaRef npccTable = entityTable["NpcComponent"];
            addComponent<NpcComponent>(e, npccTable);
        }

        std::cout << "Added " << componentName << " to " << type << std::endl;
    }
    return e;
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    luah::loadScript(L, "ghost.lua");
    luah::loadGetKeysFunction(L);

    auto e = loadEntity(L, "ghost");
    auto npcc = e->get<NpcComponent>();
    std::cout << e->getType() << " says: " << npcc->getPhrase() << std::endl;

    lua_close(L);
    delete e;
}