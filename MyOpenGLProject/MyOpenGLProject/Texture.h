#pragma once

#include "GL/glew.h"

class Texture
{
public:
	Texture();

	bool Create(int width, int height, int nrChannels, unsigned char* data);

	void Bind(unsigned int index);

	void Unbind();

private:

	int Width;

	int Height;

	int Channels;

	unsigned int TextureID;

	unsigned char* data;

};

