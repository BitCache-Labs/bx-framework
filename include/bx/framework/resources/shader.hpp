#pragma once

#include <bx/math/math.hpp>
#include <bx/containers/string.hpp>
#include <bx/containers/list.hpp>
#include <bx/platform/graphics.hpp>

class Shader
{
public:
	const String& GetSource() const { return m_source; }
	void SetSource(const String& src) { m_source = src; }

	GraphicsHandle GetVertex() const { return m_vertex; }
	GraphicsHandle GetPixel() const { return m_pixel; }

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Resource;

	List<String> m_includes;
	List<String> m_macros;
	String m_source;
	GraphicsHandle m_vertex = INVALID_GRAPHICS_HANDLE;
	GraphicsHandle m_pixel = INVALID_GRAPHICS_HANDLE;
};