#pragma once

#include "bx/framework/components/spline.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/math/math.serial.hpp>

template <>
struct Serial<Spline>
{
	template <class Archive>
	static void Save(Archive& ar, Spline const& data)
	{
	}

	template <class Archive>
	static void Load(Archive& ar, Spline& data)
	{
	}
};

REGISTER_POLYMORPHIC_SERIAL(ComponentBase, Spline)