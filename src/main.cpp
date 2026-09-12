#include <iostream>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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

    // Initialize ImGui
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    (void)io;

    // Platform backend
    ImGui_ImplGlfw_InitForOpenGL(
        window,
        true
    );

    // Renderer backend
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(io.DisplaySize);

        ImGui::Begin(
            "Lenovo Legion Control Panel",
            nullptr,
            ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove
        );
    
        ImGui::Text("System Status");

        static bool enabled = false;

        ImGui::Checkbox("Conservation Mode", &enabled);

        static int chargeLimit = 60;
        static int currChargeLimit = 60;

        ImGui::SliderInt("Charge Limit", &chargeLimit, 20, 100);
        ImGui::Text("Selected Limit: %d%%", chargeLimit);
        ImGui::Text("Current Limit: %d%%", currChargeLimit);

        if (ImGui::Button("Apply")) {
            std::cout << "Set charge limit: " << chargeLimit << '\n';
            currChargeLimit = chargeLimit;
        }

        ImGui::Text("Mouse Position: %.0f, %.0f", io.MousePos.x, io.MousePos.y);

        ImGui::End();

        ImGui::Render();

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }


    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

