#pragma once

#include <bx/math/math.hpp>
#include <bx/platform/graphics.hpp>

class Texture
{
public:
	i32 channels = 0;
	i32 width = 0;
	i32 height = 0;
	i32 depth = 0;
	List<u8> pixels;

	inline GraphicsHandle GetTexture() const { return m_texture; }

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Resource;

	GraphicsHandle m_texture = INVALID_GRAPHICS_HANDLE;
};