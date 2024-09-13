if (BX_PHYSICS_BACKEND STREQUAL "Bullet3")
endif ()

if (BX_BUILD_EDITOR)
	# STB lib
	add_library (stb INTERFACE)
	set_property(TARGET stb APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/stb)

	# Assimp
	add_subdirectory (assimp)

#	# ImPlot lib
#	add_library (implot STATIC "implot/implot.cpp" "implot/implot_demo.cpp" "implot/implot_items.cpp")
#	target_link_libraries (implot imgui)
#	target_include_directories (implot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/implot)

	# ImGuizmo lib
	add_library (ImGuizmo STATIC "ImGuizmo/GraphEditor.cpp" "ImGuizmo/ImCurveEdit.cpp" "ImGuizmo/ImGradient.cpp" "ImGuizmo/ImGuizmo.cpp" "ImGuizmo/ImSequencer.cpp")
	target_link_libraries (ImGuizmo imgui)
	target_include_directories (ImGuizmo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImGuizmo)
endif ()