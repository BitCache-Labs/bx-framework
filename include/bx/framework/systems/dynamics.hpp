#pragma once

#include <bx/engine/core/ecs.hpp>
#include <bx/engine/modules/physics.hpp>

class Dynamics : public System
{
private:
	void Initialize() override;
	void Shutdown() override;

	void Update() override;
	void Render() override;
};