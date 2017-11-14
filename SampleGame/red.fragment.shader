#version 330 core

//in vec4 gl_FragCoord;
out vec3 color;

void main(){
	vec2 resolution = vec2(800, 600);
	vec2 position = ( gl_FragCoord.xy / resolution.xy );

	color = vec3(position.x, position.y, 0);
	//gl_FragColor = vec4(normalize(color), 1.0 );
}