#pragma once

#include "bx/framework/resources/material.hpp"

#include "bx/framework/resources/shader.serial.hpp"
#include "bx/framework/resources/texture.serial.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>
#include <bx/core/containers/string.serial.hpp>
#include <bx/core/containers/list.serial.hpp>
#include <bx/core/containers/hash_map.serial.hpp>
#include <bx/core/containers/tree.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template <>
class Serial<Material>
{
public:
	template<class Archive>
	static void Save(Archive& ar, const Material& data)
	{
		ar(cereal::make_nvp("shader", data.m_shader));
		ar(cereal::make_nvp("textures", data.m_textures));
	}

	template<class Archive>
	static void Load(Archive& ar, Material& data)
	{
		ar(cereal::make_nvp("shader", data.m_shader));
		ar(cereal::make_nvp("textures", data.m_textures));
	}
};
REGISTER_SERIAL(Material);