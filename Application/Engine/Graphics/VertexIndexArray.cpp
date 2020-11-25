#include "pch.h"
#include "VertexIndexArray.h"

bool nc::VertexIndexArray::Create(const std::string& name, void* null)
{
	VertexArray::Create(name, null);
	return true;
}

void nc::VertexIndexArray::Destroy()
{
	VertexArray::Destroy();

	glDeleteBuffers(1, &m_ibo);

}

void nc::VertexIndexArray::CreateIndexBuffer(GLenum indexType, GLsizei count, void* data)
{
	// set m_indexType to indexType
	m_indexType = indexType;
	// set m_indexCount to count
	m_indexCount = count;

	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	size_t indexSize = (m_indexType == GL_UNSIGNED_SHORT) ? sizeof(GLushort) : sizeof(GLuint);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * indexSize, data, GL_STATIC_DRAW);
}

void nc::VertexIndexArray::Draw(GLenum primitiveType)
{
	glBindVertexArray(m_vao);
	glDrawElements(primitiveType, m_indexCount, m_indexType, 0);
}


