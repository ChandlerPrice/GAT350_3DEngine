#pragma once
#include "Program.h"
#include "Texture.h"

namespace nc
{
	struct Material
	{
	public:
		Material(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, float shine) :
			ambient{ ambient },
			diffuse{ diffuse },
			specular{ specular },
			shine{ shine }
			{}

		void Bind();
		void SetProgram(Program& program);
		void AddTexture(const Texture& texture) { textures.push_back(texture); }

	public:
		glm::vec3 ambient = glm::vec3(0);
		glm::vec3 diffuse = glm::vec3(1);
		glm::vec3 specular = glm::vec3(1);
		float shine = 100.0f;

		std::vector<Texture> textures;
	};
}

