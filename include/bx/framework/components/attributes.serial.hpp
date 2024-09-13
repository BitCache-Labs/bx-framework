#pragma once

#include "bx/framework/components/attributes.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>

template <>
struct Serial<Attributes>
{
	template <class Archive>
	static void Save(Archive& ar, Attributes const& data)
	{
	}

	template <class Archive>
	static void Load(Archive& ar, Attributes& data)
	{
	}
};

REGISTER_POLYMORPHIC_SERIAL(ComponentBase, Attributes)