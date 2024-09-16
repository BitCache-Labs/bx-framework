#pragma once

#include "bx/framework/resources/texture.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>
#include <bx/core/containers/string.serial.hpp>
#include <bx/core/containers/list.serial.hpp>
#include <bx/core/containers/hash_map.serial.hpp>
#include <bx/core/containers/tree.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template <>
class Serial<Texture>
{
public:
	template<class Archive>
	static void Save(Archive& ar, const Texture& data)
	{
		ar(cereal::make_nvp("channels", data.channels));
		ar(cereal::make_nvp("width", data.width));
		ar(cereal::make_nvp("height", data.height));
		ar(cereal::make_nvp("depth", data.depth));
		ar(cereal::make_nvp("pixels", data.pixels));
	}

	template<class Archive>
	static void Load(Archive& ar, Texture& data)
	{
		ar(cereal::make_nvp("channels", data.channels));
		ar(cereal::make_nvp("width", data.width));
		ar(cereal::make_nvp("height", data.height));
		ar(cereal::make_nvp("depth", data.depth));
		ar(cereal::make_nvp("pixels", data.pixels));
	}
};
REGISTER_SERIAL(Texture);
