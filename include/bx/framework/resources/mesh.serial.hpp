#pragma once

#include "bx/framework/resources/mesh.hpp"

#include <bx/core/serial.serial.hpp>
#include <bx/core/math/math.serial.hpp>
#include <bx/core/containers/string.serial.hpp>
#include <bx/core/containers/list.serial.hpp>
#include <bx/core/containers/hash_map.serial.hpp>
#include <bx/core/containers/tree.serial.hpp>

#include <bx/engine/resource.serial.hpp>

template <>
class Serial<Mesh>
{
public:
	template<class Archive>
	static void Save(Archive& ar, const Mesh& data)
	{
		ar(cereal::make_nvp("transform", data.m_transform));
		ar(cereal::make_nvp("vertices", data.m_vertices));
		ar(cereal::make_nvp("colors", data.m_colors));
		ar(cereal::make_nvp("normals", data.m_normals));
		ar(cereal::make_nvp("tangents", data.m_tangents));
		ar(cereal::make_nvp("uvs", data.m_uvs));
		ar(cereal::make_nvp("bones", data.m_bones));
		ar(cereal::make_nvp("weights", data.m_weights));
		ar(cereal::make_nvp("triangles", data.m_triangles));
	}

	template<class Archive>
	static void Load(Archive& ar, Mesh& data)
	{
		ar(cereal::make_nvp("transform", data.m_transform));
		ar(cereal::make_nvp("vertices", data.m_vertices));
		ar(cereal::make_nvp("colors", data.m_colors));
		ar(cereal::make_nvp("normals", data.m_normals));
		ar(cereal::make_nvp("tangents", data.m_tangents));
		ar(cereal::make_nvp("uvs", data.m_uvs));
		ar(cereal::make_nvp("bones", data.m_bones));
		ar(cereal::make_nvp("weights", data.m_weights));
		ar(cereal::make_nvp("triangles", data.m_triangles));
	}
};
REGISTER_SERIAL(Mesh);