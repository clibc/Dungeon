#version 330 core

out vec3 color;

uniform vec3 u_Color;

void main(){
	color = u_Color;
	//color = vec3(1,0,0);
}