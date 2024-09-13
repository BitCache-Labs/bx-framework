#pragma once

#include "bx/framework/resources/shader.hpp"
#include "bx/framework/resources/texture.hpp"

#include <bx/core/math/math.hpp>
#include <bx/core/containers/string.hpp>
#include <bx/core/containers/list.hpp>

#include <bx/platform/graphics.hpp>

#include <bx/engine/resource.hpp>

class Material
{
public:
	inline const Resource<Shader>& GetShader() const { return m_shader; }
	inline void SetShader(Resource<Shader> shader) { m_shader = shader; BuildPipeline(); }

	inline const Vec4& GetColor() const { return m_color; }
	inline void SetColor(const Vec4& color) { m_color = color; }

	inline Resource<Texture>& GetTexture(const String& name) { return m_textures[name]; }
	inline void RemoveTexture(const String& name) { m_textures.erase(m_textures.find(name)); }
	inline const HashMap<String, Resource<Texture>>& GetTextures() const { return m_textures; }

	inline GraphicsHandle GetPipeline() const { return m_pipeline; }
	inline GraphicsHandle GetResources() const { return m_resources; }

private:
	void BuildPipeline();

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Resource;

	template <typename T>
	friend class Inspector;

private:
	GraphicsHandle m_pipeline = INVALID_GRAPHICS_HANDLE;
	GraphicsHandle m_resources = INVALID_GRAPHICS_HANDLE;

	Resource<Shader> m_shader;

	Vec4 m_color = Vec4(1, 1, 1, 1);
	HashMap<String, Resource<Texture>> m_textures;
};