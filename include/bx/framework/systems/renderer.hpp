#pragma once

#include <bx/math/math.hpp>
#include <bx/platform/graphics.hpp>
#include <bx/engine/ecs.hpp>

class Renderer : public System
{
public:
	void SetPipelineOverride(const GraphicsHandle pipeline);

	Vec4i GetLightIndices(const Vec3& pos);

	void UpdateAnimators();
	void UpdateCameras();
	void UpdateLights();

	void CollectDrawCommands();

	void DrawCommand(const GraphicsHandle pipeline, u32 numResourceBindings, const GraphicsHandle* pResourcesBindings, u32 numBuffers, const GraphicsHandle* pBuffers, const u64* offset, const GraphicsHandle indexBuffer, u32 count);
	void DrawCommands();

	void BindConstants(const Mat4& viewMtx, const Mat4& projMtx, const Mat4& viewProjMtx);

private:
	void Initialize() override;
	void Shutdown() override;

	void Update() override;
	void Render() override;

private:
	class Impl;
	Impl* m_impl = nullptr;
};