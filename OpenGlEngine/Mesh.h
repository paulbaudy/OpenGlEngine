#pragma once

#include "tiny_obj_loader.h"


#include "glm\glm.hpp"


#ifndef __gl_h_ 

// Include GLEW
#include "glew.h"
// Include GLFW
#include "glfw3.h"
#endif

class Mesh
{
public:
	Mesh(std::string obj_path);
	~Mesh();


	void render();
private:
	void fillBuffers();

	std::vector<glm::vec4> vertices;
	std::vector<glm::vec4> normals;
	std::vector<glm::vec2> uvs;

	// Load object with tinyobjloader
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;
	bool ret;

	// Render variables
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalsbuffer;
};

