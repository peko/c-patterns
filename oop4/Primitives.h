#pragma once

typedef struct vec2 vec2; 
struct vec2 {
	float x,y;
};

typedef struct vec3 vec3; 
struct vec3 {
    union {
		struct vec2;
		struct vec2 v2;
    };
    float z;
};
