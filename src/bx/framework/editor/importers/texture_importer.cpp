#include "bx/framework/editor/importers/texture_importer.hpp"

#include <bx/platform/file.hpp>
#include <bx/engine/resource.hpp>
#include <bx/containers/list.hpp>
#include <bx/containers/hash_map.hpp>
#include <bx/platform/graphics.hpp>

#include <bx/framework/resources/texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_image_resize2.h>

#include <cstring>
#include <fstream>
#include <sstream>

template <typename T>
static Resource<T> ImportResource(const String& filename, const T& data)
{
    auto res = Resource<T>(Resource<T>::MakeHandle(filename), data);
    res.Save(filename);
    return res;
}

bool TextureImporter::Import(const char* ext, const char* filename)
{
    Texture texture;

    stbi_set_flip_vertically_on_load(true);
    auto pData = stbi_load(File::GetPath(filename).c_str(), &texture.width, &texture.height, &texture.channels, 4);
    if (pData == nullptr)
        return false;

    texture.channels = 4;
    texture.depth = 1;

    texture.pixels.resize((i64)texture.width * (i64)texture.height * 4);
    memcpy(texture.pixels.data(), pData, texture.pixels.size());
    stbi_image_free(pData);

    auto res = ImportResource(File::RemoveExt(filename) + ".texture", texture);
    return res.IsValid();
}