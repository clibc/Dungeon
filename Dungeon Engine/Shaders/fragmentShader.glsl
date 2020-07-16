#version 330 core

out vec4 color;
in vec2 TexCoord;

uniform vec3 u_Color;
uniform sampler2D ourTexture;


void main(){
	color = texture(ourTexture, TexCoord);
}