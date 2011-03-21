#ifndef _LUASHIP_H
#define _LUASHIP_H

#include "LuaObject.h"
#include "Ship.h"

class LuaShip : public LuaObject {
public:
	LuaShip(Ship *s) : LuaObject(s, s_type) {}

	static void RegisterClass();

private:
	static const char *s_type;
};


#endif
