#version 120
attribute vec3 inPosition;
attribute vec3 inNormal;
attribute vec2 inTexcoord;

varying vec2 texCoord;
varying vec3 outNormal;

varying vec3 lightDir;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * vec4(inPosition.xyz,1);
    gl_TexCoord[0].st = inTexcoord;
    texCoord = inTexcoord;
    outNormal = normalize(gl_NormalMatrix * inNormal);
    lightDir = normalize(vec3(gl_LightSource[0].position));
}
