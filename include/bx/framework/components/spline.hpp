#pragma once

#include <bx/math/math.hpp>

#include <bx/engine/ecs.hpp>

class Spline : public Component<Spline>
{
public:
	Spline();

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Inspector;
};