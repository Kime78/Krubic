#include "shaders.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void create_shader(Shader *new)
{
    FILE *shader_source = fopen("./base.vert", "r");
    FILE *fragment_source = fopen("./base.frag", "r");

    fread(new->shader, 1, 1000, shader_source); //TODO get rid of new->shader and just replace it with a GLchar* shader
    fread(new->fragment, 1, 1000, fragment_source);

    fclose(shader_source);
    fclose(fragment_source);

    new->shader_program = glCreateProgram();

    // Create and compile the vertex shader
    new->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(new->vertex_shader, 1, &new->shader, NULL);
    glCompileShader(new->vertex_shader);

    // Create and compile the fragment shader
    new->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(new->fragment_shader, 1, &new->fragment, NULL);
    glCompileShader(new->fragment_shader);

    // Link the vertex and fragment shader into a shader program
    glAttachShader(new->shader_program, new->vertex_shader);
    glAttachShader(new->shader_program, new->fragment_shader);
    glBindFragDataLocation(new->shader_program, 0, "outColor");
    glLinkProgram(new->shader_program);
    glUseProgram(new->shader_program); //1282

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(new->shader_program, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);

    GLint colAttrib = glGetAttribLocation(new->shader_program, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
}

void update_shader()
{
}

Shader *shader_constructor()
{
    Shader *new = malloc(sizeof(Shader));

    new->create_shaders = &create_shader;
    new->update_shaders = &update_shader;

    (*new->create_shaders)(new);

    return new;
}