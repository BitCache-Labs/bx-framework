#pragma once

#include <bx/engine/ecs.hpp>
#include <bx/math/math.hpp>

class AudioSource : public Component<AudioSource>
{
public:
	AudioSource();

private:
	template <typename T>
	friend class Serial;

	template <typename T>
	friend class Inspector;
};