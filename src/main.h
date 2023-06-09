#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define global_variable static
#define local_persist static
#define internal static

#define ATLAS_COLS 16

#define SCREEN_COLS 90
#define SCREEN_ROWS 50
#define SCREEN_TILE_SIZE 16

#define MAP_COLS 150
#define MAP_ROWS 150

typedef GLuint TexID;
typedef GLuint ShaderID;
typedef GLuint VaoID;
typedef GLuint VboID;

typedef unsigned char Glyph;

#include "util.c"
#include "resource.c"
#include "render.c"

#endif
