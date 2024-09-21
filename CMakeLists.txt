cmake_minimum_required (VERSION 3.22)

project (bx-framework)

# Define options for physics backend
set(BX_PHYSICS_BACKEND "Bullet3" CACHE STRING "Choose the physics backend: Bullet3")
set_property(CACHE BX_PHYSICS_BACKEND PROPERTY STRINGS "Bullet3" "Custom")
message(STATUS "BX physics backend: ${BX_PHYSICS_BACKEND}")

# External libraries
add_subdirectory(extern)

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

	"src/bx/framework/framework.cpp"
	"src/bx/framework/gameobject.cpp"
)

# Create bx-framework lib
add_library(bx-framework STATIC ${BX_FRAMEWORK_SRCS})
target_include_directories(bx-framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(bx-framework PUBLIC bx-engine)

target_compile_definitions(bx-framework PRIVATE BX_FRAMEWORK_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

# Setup physics backend
if (BX_PHYSICS_BACKEND STREQUAL "Bullet3")
    message(STATUS "Using Bullet3 as the physics backend")
    target_compile_definitions(bx-framework PUBLIC BX_PHYSICS_BULLET_BACKEND)
    target_link_libraries(bx-framework-bullet3 PRIVATE bx-framework)
    target_link_libraries(bx-framework PUBLIC bx-framework-bullet3)

elseif (BX_PHYSICS_BACKEND STREQUAL "Custom")
    message(STATUS "Using a custom physics backend")
    target_compile_definitions(bx-framework PUBLIC BX_PHYSICS_CUSTOM_BACKEND)

else()
    message(FATAL_ERROR "Unknown physics backend: ${BX_PHYSICS_BACKEND}")
endif()

# Editor sources and libraries
if (BX_BUILD_EDITOR)
    target_sources(bx-framework PRIVATE
		"src/bx/framework/editor/gizmos/spline_gizmo.cpp"
		"src/bx/framework/editor/gizmos/transform_gizmo.cpp"

		"src/bx/framework/editor/importers/model_importer.cpp"
		"src/bx/framework/editor/importers/texture_importer.cpp"

		"src/bx/framework/editor/views/gameobject_view.cpp"
		"src/bx/framework/editor/views/inspector_view.cpp"
		"src/bx/framework/editor/views/scene_view.cpp"
	)
    target_link_libraries(bx-framework PUBLIC stb assimp ImGuizmo)
endif()