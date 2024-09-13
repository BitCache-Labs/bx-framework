#pragma once

#include <bx/engine/ecs.hpp>
#include <bx/core/math/math.hpp>

class AudioListener : public Component<AudioListener>
{
public:
	AudioListener();

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Inspector;
};