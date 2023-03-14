#include "main.h"

global_variable int _new_key;

void _key_callback(
    GLFWwindow *window,
    int key,
    int scancode,
    int action,
    int mode
)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    else if (key >= 0 && key < 1024)
    {
        if (action == GLFW_REPEAT || action == GLFW_PRESS)
        {
            _new_key = key;
        }
    }
}

int main()
{
    render_prepare_render_data(SCREEN_COLS, SCREEN_ROWS, ATLAS_COLS, SCREEN_TILE_SIZE);
    
    GLFWwindow *window = render_init_window(_key_callback);
    
    render_load_resources();
    render_init_vao();
    render_prepare_shader();
    render_prepare_render();

    _new_key = GLFW_KEY_UNKNOWN;

    float delta_time = 0.0f;
    float last_frame = 0.0f;

    float delta_sum = {0};
    int frame_count = 30;
    while(!glfwWindowShouldClose(window))
    {
        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

        if (frame_count <= 0)
        {
            if (0) printf(" `````````````````````````````` Avg delay: %f ms\n", delta_sum / 30.0f * 1000.0f);
            delta_sum = 0.0f;
            frame_count = 30;
        }

        delta_sum += delta_time;
        frame_count--;

        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render_render_tile(GLM_VEC2_ZERO, 'A', GLM_VEC3_ONE, GLM_VEC3_ZERO, false);

        glfwSwapBuffers(window);
    }

    render_clean_render();

    glfwTerminate();
    return 0;
}
