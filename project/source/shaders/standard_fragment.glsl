#version 330 core

in vec2 UVCord;
out vec4 FragColor;

uniform sampler2D mainTexture;
uniform mat4 transform;

void main(){
    FragColor = texture(mainTexture, UVCord);
}
