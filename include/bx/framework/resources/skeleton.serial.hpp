#pragma once

#include "bx/framework/resources/skeleton.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/math/math.serial.hpp>
#include <bx/containers/string.serial.hpp>
#include <bx/containers/list.serial.hpp>
#include <bx/containers/hash_map.serial.hpp>
#include <bx/containers/tree.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template<class Archive>
void serialize(Archive& ar, Skeleton::Bone& data)
{
	ar(cereal::make_nvp("local", data.local));
	ar(cereal::make_nvp("offset", data.offset));
}

template <>
class Serial<Skeleton>
{
public:
	template<class Archive>
	static void Save(Archive& ar, const Skeleton& data)
	{
		ar(cereal::make_nvp("bones", data.m_bones));
		ar(cereal::make_nvp("boneMap", data.m_boneMap));
		ar(cereal::make_nvp("boneTree", data.m_boneTree));
	}

	template<class Archive>
	static void Load(Archive& ar, Skeleton& data)
	{
		ar(cereal::make_nvp("bones", data.m_bones));
		ar(cereal::make_nvp("boneMap", data.m_boneMap));
		ar(cereal::make_nvp("boneTree", data.m_boneTree));
	}
};
REGISTER_SERIAL(Skeleton);