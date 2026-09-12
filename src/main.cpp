#include <iostream>

#include <GLFW/glfw3.h>

int main() {
    std::cout << "Legion Control Panel\n";

    if (!glfwInit()) {
        std::cerr << "Failed to init glfw\n";
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(
        800,
        600,
        "Legion Control Panel",
        nullptr,
        nullptr
    );

    if (!window) {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f( 0.0f,  0.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( 0.0f,  1.0f);

        glEnd();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

