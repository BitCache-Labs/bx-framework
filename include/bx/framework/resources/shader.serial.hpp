#pragma once

#include "bx/framework/resources/shader.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/math/math.serial.hpp>
#include <bx/containers/string.serial.hpp>
#include <bx/containers/list.serial.hpp>
#include <bx/containers/hash_map.serial.hpp>
#include <bx/containers/tree.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template <>
class Serial<Shader>
{
public:
	template<class Archive>
	static void Save(Archive& ar, const Shader& data)
	{
		//ar(cereal::make_nvp("source", data.m_source));
	}

	template<class Archive>
	static void Load(Archive& ar, Shader& data)
	{
		//ar(cereal::make_nvp("source", data.m_source));
		//data.Build();
	}
};
REGISTER_SERIAL(Shader);