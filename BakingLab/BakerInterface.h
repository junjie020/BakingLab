//use for exprot interface
#pragma once

typedef void* BakerHandle;

#include <cstdint>
#include <vector>
#include <string>

#include "../SampleFramework11/v1.02/SF11_Math.h"

using namespace SampleFramework11;

enum LightType {
    LT_Directional,
    LT_PointLight,
    LT_AreaLight,
};

struct Light {
    Float3 dir;
    Float3 pos;
    Float3 color;
    float intensity;
    float size;
    LightType type;
};

struct MaterialData{
    std::string diffuse;
    std::string normal;
    std::string roughness;
    std::string metallic;
};

enum BufferType {
    BT_None = 0,
    BT_Byte,
    BT_Uint16,
    BT_Uint32,
    BT_Float,
};

struct BufferData{
    const char* data;
    uint32_t offset;
    uint32_t stride;
    BufferType type;
};

struct MeshData {
    Float4x4 worldmat;
    Float4x4 normalmat;
    BufferData positions;
    BufferData normals;
    BufferData tangents;
    BufferData bitangents;
    BufferData texcoords0;
    BufferData texcoords1;
    BufferData indices;

    uint32_t vertexCount;
    uint32_t indexCount;
    uint32_t materialidx;
};

struct Scene {
    std::vector<Light>          lights;
    std::vector<MeshData>       models;
    std::vector<MaterialData>   materials;
};

struct Lightmap{
    std::vector<Float4>   data;
    uint16_t size;
};

struct BakeResult {
    std::vector<Lightmap> lightmaps;
};

extern BakerHandle CreateBaker(const Scene* scene);
extern void Bake(BakerHandle handle, BakeResult *result);
extern void DestroyBaker(BakerHandle handle);