#include <bx/engine/runtime.hpp>

#include <bx/core/memory.hpp>
#include <bx/core/log.hpp>
#include <bx/core/time.hpp>
#include <bx/core/profiler.hpp>

#include <bx/platform/file.hpp>
#include <bx/platform/input.hpp>
#include <bx/platform/window.hpp>
#include <bx/platform/graphics.hpp>
#include <bx/platform/audio.hpp>
#include <bx/platform/imgui.hpp>

#include <bx/engine/data.hpp>
#include <bx/engine/module.hpp>
#include <bx/engine/ecs.hpp>
#include <bx/engine/resource.hpp>
#include <bx/engine/application.hpp>
#include <bx/engine/script.hpp>

#include <bx/framework/gameobject.hpp>
#include <bx/framework/modules/physics.hpp>

static bool s_running = true;

int main(int argc, char** argv)
{
	return Runtime::Launch(argc, argv);
}

bool Runtime::IsRunning()
{
	return s_running && Window::IsOpen();
}

void Runtime::Close()
{
	s_running = false;
}

void Runtime::Reload()
{
	Module::Reload();
}

int Runtime::Launch(int argc, char** argv)
{
	if (!Initialize())
		return EXIT_FAILURE;

	Window::SetCursorMode(CursorMode::DISABLED);

	const String& mainScene = Data::GetString("Main Scene", "[assets]/main.scene", DataTarget::GAME);
	Scene::Load(mainScene);

	while (IsRunning())
	{
		PROFILE_SECTION("Runtime");

		Profiler::Update();
		Script::CollectGarbage();
		Time::Update();
		Window::PollEvents();
		Input::Poll();

		SystemManager::Update();
		Scene::GetCurrent().Update();
		Script::Update();
		
		Graphics::NewFrame();
		ImGuiImpl::NewFrame();

		SystemManager::Render();
		Script::Render();

		ImGuiImpl::EndFrame();
		Graphics::EndFrame();

		Window::Display();
	}

	Shutdown();
	return EXIT_SUCCESS;
}

bool Runtime::Initialize()
{
	// Initialze core
#ifdef MEMORY_CUSTOM_CONTAINERS
	Memory::Initialize();
#endif

	Time::Initialize();
	File::Initialize();
	Data::Initialize();
	ResourceManager::Initialize();

	// Register modules
	Module::Register<Script>(0);
	Module::Register<Window>(1);
	Module::Register<Input>(2);
	Module::Register<Graphics>(3);
	Module::Register<ImGuiImpl>(4);
	Module::Register<Physics>(5);
	Module::Register<Audio>(6);
	Module::Register<GameObject>(7);

	// Initialize application
	if (!Application::Initialize())
	{
		BX_LOGE("Failed to initialize application!");
		return false;
	}

	// Initialize modules
	Module::Initialize();

	return true;
}

void Runtime::Shutdown()
{
	Module::Shutdown();

	Application::Shutdown();

	ResourceManager::Shutdown();
	Data::Shutdown();
	//File::Shutdown();
	//Time::Shutdown();

#ifdef MEMORY_CUSTOM_CONTAINERS
	Memory::Shutdown();
#endif
}