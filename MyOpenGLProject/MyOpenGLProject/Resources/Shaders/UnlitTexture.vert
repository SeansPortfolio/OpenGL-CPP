#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 TexCoord;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec2 outTexCoord;

void main()
{
   outTexCoord = TexCoord;
   gl_Position = Projection * View * Model * vec4(aPos, 1.0);
}