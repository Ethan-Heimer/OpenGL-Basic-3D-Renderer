#version 330 core

in vec2 UVCord;
uniform sampler2D mainTexture;

out vec4 FragColor;

void main(){
    FragColor = texture(mainTexture, UVCord);
}
