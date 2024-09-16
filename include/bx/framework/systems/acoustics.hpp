#pragma once

#include <bx/engine/ecs.hpp>

class Acoustics : public System
{
private:
	void Initialize() override;
	void Shutdown() override;

	void Update() override;
	void Render() override;
};