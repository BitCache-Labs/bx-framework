#pragma once

#include <bx/engine/ecs.hpp>
#include <bx/math/math.hpp>

class Attributes : public Component<Attributes>
{
public:
	Attributes();

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Inspector;
};