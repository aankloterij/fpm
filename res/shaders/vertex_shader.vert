#version 120

attribute vec4 gl_Vertex;

void main(void) {
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
