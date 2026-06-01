#pragma once

#include <array>

struct Triangle {
	std::array<float, 9> vertices = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f
	}; // 0 depth
};