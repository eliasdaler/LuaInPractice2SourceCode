#pragma once

#include <vector>

struct lua_State;

namespace luah {
    bool loadScript(lua_State* L, const std::string& filename);
    void lua_gettostack(lua_State* L, const std::string& variableName);
    void loadGetKeysFunction(lua_State* L);
    std::vector<std::string> getTableKeys(lua_State* L, const std::string& name);
}
