#pragma once

#include "bx/framework/components/mesh_filter.hpp"

#include "bx/framework/resources/mesh.serial.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/containers/list.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template <>
struct Serial<MeshFilter>
{
	template <class Archive>
	static void Save(Archive& ar, MeshFilter const& data)
	{
		ar(cereal::make_nvp("meshes", data.m_meshes));
	}

	template <class Archive>
	static void Load(Archive& ar, MeshFilter& data)
	{
		ar(cereal::make_nvp("meshes", data.m_meshes));
	}
};

REGISTER_POLYMORPHIC_SERIAL(ComponentBase, MeshFilter)