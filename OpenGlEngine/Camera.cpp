#include "Camera.h"



Camera::Camera(float x, float y, float z)
{
	Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	View = glm::lookAt(
		glm::vec3(x, y, z), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
}


Camera::~Camera()
{
}

glm::mat4 Camera::getMVP() {
	return Projection * View * Model;
}

glm::mat4 Camera::getPV() {
	return Projection*View;
}