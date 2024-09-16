#pragma once

#include "bx/framework/components/transform.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>
#include <bx/core/containers/string.serial.hpp>

template <>
struct Serial<Transform>
{
	template <class Archive>
	static void Save(Archive& ar, Transform const& data)
	{
		ar(cereal::make_nvp("position", data.m_position));
		ar(cereal::make_nvp("rotation", data.m_rotation));
		ar(cereal::make_nvp("scale", data.m_scale));
	}

	template <class Archive>
	static void Load(Archive& ar, Transform& data)
	{
		ar(cereal::make_nvp("position", data.m_position));
		ar(cereal::make_nvp("rotation", data.m_rotation));
		ar(cereal::make_nvp("scale", data.m_scale));
		data.Update();
	}
};

REGISTER_POLYMORPHIC_SERIAL(ComponentBase, Transform)