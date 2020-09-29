#pragma once

#include <glm/glm.hpp>

typedef glm::vec3 color3;

struct Light
{
public:
	glm::vec3 m_position;
	color3 m_color;

	Light(const glm::vec3 &position, const color3 &color) : m_position(position), m_color(color) {}

	Ray getRayFrom(const glm::vec3 &position) {
		return Ray(position, (m_position - position) );
	}
};