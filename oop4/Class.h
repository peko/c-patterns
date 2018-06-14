#pragma once

struct AClass {
	void* (*create )(void );
	void  (*init   )(void*);
	void  (*deinit )(void*);
	void  (*release)(void*);
};
