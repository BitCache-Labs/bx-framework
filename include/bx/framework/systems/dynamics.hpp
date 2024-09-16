#pragma once

#include "bx/framework/modules/physics.hpp"

#include <bx/engine/ecs.hpp>

class Dynamics : public System
{
private:
	void Initialize() override;
	void Shutdown() override;

	void Update() override;
	void Render() override;
};