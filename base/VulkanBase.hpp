#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <VulkanTool.hpp>

#include <vulkan/vulkan.h>

using namespace std;

class VulkanBase{
    private:
    protected:
        VkInstance instance;
        std::vector<std::string> supportedInstanceExtensions; //for save Instance EXT
        std::vector<const char*> enabledInstanceExtensions;
    public:
        GLFWwindow* window;
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;

        struct Settings {
            /** @brief Activates validation layers (and message output) when set to true */
            bool validation = false;
            /** @brief Set to true if fullscreen mode has been requested via command line */
            bool fullscreen = false;
            /** @brief Set to true if v-sync will be forced for the swapchain */
            bool vsync = false;
            /** @brief Enable UI overlay */
            bool overlay = true;
	    } settings;

        std::string title = "Vulkan Example";
	    std::string name = "VulkanExample";
        uint32_t apiVersion = VK_API_VERSION_1_0;

        void initWindow();
        VulkanBase(bool enableValidation);
        virtual ~VulkanBase();
        virtual VkResult createInstance(bool enableValidation);
};
