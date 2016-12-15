#pragma once
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

class Camera
{
public:
	Camera(float x, float y, float z);
	~Camera();

	glm::mat4 getMVP();
	glm::mat4 getPV();
private:
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection;
	// Camera matrix
	glm::mat4 View;
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
};