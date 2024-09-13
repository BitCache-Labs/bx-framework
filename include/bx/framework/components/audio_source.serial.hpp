#pragma once

#include "bx/framework/components/audio_source.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>

template <>
struct Serial<AudioSource>
{
	template <class Archive>
	static void Save(Archive& ar, AudioSource const& data)
	{
	}

	template <class Archive>
	static void Load(Archive& ar, AudioSource& data)
	{
	}
};

REGISTER_POLYMORPHIC_SERIAL(ComponentBase, AudioSource)