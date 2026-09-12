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

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

