#pragma once

#include "glad.h"
typedef struct
{
    char *shader;
    char *fragment;
    void (*create_shaders)(void *);
    void (*update_shaders)(void *);
    void (*shader_constructor)();

    GLuint shader_program;
    GLuint vertex_shader;
    GLuint fragment_shader;
} Shader;

extern void create_shaders(Shader *shader); //parameters bruh
extern void update_shaders(Shader *shader);
extern Shader *shader_constructor();
