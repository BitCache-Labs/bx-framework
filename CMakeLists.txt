cmake_minimum_required (VERSION 3.22)

project (bx-framwork)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Define options for physics backend
set (BX_PHYSICS_BACKEND "Bullet" CACHE STRING "Choose the physics backend: Bullet")
set_property (CACHE BX_PHYSICS_BACKEND PROPERTY STRINGS "Bullet" "Custom")
message ("BX physics backend: ${BX_PHYSICS_BACKEND}")

if (BX_PHYSICS_BACKEND STREQUAL "Bullet")
    message(STATUS "Using Bullet as the physics backend")
    add_compile_definitions (BX_PHYSICS_BULLET_BACKEND)

elseif (BX_PHYSICS_BACKEND STREQUAL "Custom")
    message(STATUS "Using a custom physics backend")
    add_compile_definitions (BX_PHYSICS_CUSTOM_BACKEND)

else ()
    message(FATAL_ERROR "Unknown physics backend: ${WINDOW_BACKEND}")
endif ()



# External libraries
add_subdirectory (extern)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)



# Setup bx-framework library
set (BX_FRAMEWORK_SRCS
	"src/bx/framework/components/animator.cpp"
	"src/bx/framework/components/attributes.cpp"
	"src/bx/framework/components/audio_listener.cpp"
	"src/bx/framework/components/audio_source.cpp"
	"src/bx/framework/components/camera.cpp"
	"src/bx/framework/components/character_controller.cpp"
	"src/bx/framework/components/collider.cpp"
	"src/bx/framework/components/light.cpp"
	"src/bx/framework/components/mesh_filter.cpp"
	"src/bx/framework/components/mesh_renderer.cpp"
	"src/bx/framework/components/rigidbody.cpp"
	"src/bx/framework/components/spline.cpp"
	"src/bx/framework/components/transform.cpp"
	"src/bx/framework/resources/animation.cpp"
	"src/bx/framework/resources/material.cpp"
	"src/bx/framework/resources/mesh.cpp"
	"src/bx/framework/resources/shader.cpp"
	"src/bx/framework/resources/skeleton.cpp"
	"src/bx/framework/resources/texture.cpp"
	"src/bx/framework/systems/renderer.cpp"
	"src/bx/framework/systems/dynamics.cpp"
	"src/bx/framework/systems/acoustics.cpp"
	"src/bx/framework/gameobject.cpp"
)

set (BX_FRAMEWORK_LIBS bx)

# Setup editor sources
if (BX_BUILD_EDITOR)
	set (BX_FRAMEWORK_SRCS ${BX_FRAMEWORK_SRCS}
		#"src/bx/editor/core/asset_importer.cpp"
		#"src/bx/editor/core/assets.cpp"
		#"src/bx/editor/core/command.cpp"
		#"src/bx/editor/core/selection.cpp"
		#"src/bx/editor/core/toolbar.cpp"
		#"src/bx/editor/core/view.cpp"
		#
		#"src/bx/editor/gizmos/spline_gizmo.cpp"
		#"src/bx/editor/gizmos/transform_gizmo.cpp"
		#
		#"src/bx/editor/views/assets_view.cpp"
		#"src/bx/editor/views/console_view.cpp"
		#"src/bx/editor/views/data_view.cpp"
		#"src/bx/editor/views/entity_view.cpp"
		#"src/bx/editor/views/gameobject_view.cpp"
		#"src/bx/editor/views/inspector_view.cpp"
		#"src/bx/editor/views/profiler_view.cpp"
		#"src/bx/editor/views/scene_view.cpp"
		#"src/bx/editor/views/settings_view.cpp"
	)

	set (BX_FRAMEWORK_LIBS ${BX_FRAMEWORK_LIBS} stb assimp ImGuizmo) #implot)

	# Add editor runtime
	set (BX_FRAMEWORK_SRCS ${BX_FRAMEWORK_SRCS} "src/bx/framework/editor/editor_runtime.cpp")

else ()
	
	# Add game runtime
	set (BX_FRAMEWORK_SRCS ${BX_FRAMEWORK_SRCS} "src/bx/framework/game_runtime.cpp")
endif ()

# Create bx lib
add_library (bx-framework STATIC ${BX_FRAMEWORK_SRCS})
target_link_libraries (bx-framework ${BX_FRAMEWORK_LIBS})
target_include_directories (bx-framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)