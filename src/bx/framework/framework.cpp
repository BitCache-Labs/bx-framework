#include "bx/framework/framework.hpp"

#include "bx/framework/gameobject.hpp"
#include "bx/framework/modules/physics.hpp"

#ifdef BX_EDITOR_BUILD
#include "bx/framework/editor/views/scene_view.hpp"
#include "bx/framework/editor/views/inspector_view.hpp"
#endif

bool Framework::Initialize()
{
	return true;
}

void Framework::Shutdown()
{
}

void Framework::Reload()
{
}

void Framework::Tick()
{
}