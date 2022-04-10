#include <vulkan/vulkan.h>
//#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <VulkanBase.hpp>

#define DEBUG
#define ENABLE_VALIDATION true 

using namespace std;

class Vulkan_template: public VulkanBase{
    public:
        void run(){
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();         
        }
        Vulkan_template() : VulkanBase(ENABLE_VALIDATION){ 
            title = "Vulkan Example - template";
            // camera.type = Camera::CameraType::lookat;
            // camera.setPosition(glm::vec3(0.0f, 0.0f, -2.5f));
            // camera.setRotation(glm::vec3(0.0f));
            // camera.setPerspective(60.0f, (float)width / (float)height, 1.0f, 256.0f);
        }
    private:
        void initVulkan(){ 
            VkResult err = createInstance(ENABLE_VALIDATION);

	        if (err!=VK_SUCCESS) {
		        cout<<("Could not create Vulkan instance");
	        }
        }
        void mainLoop(){
            while(!glfwWindowShouldClose(window)){
                glfwPollEvents();    
            }
        }
        void cleanup(){

        }
};

Vulkan_template *app = new Vulkan_template();

int main(){
    try{
            app->run();        
    }catch (const std::exception& e){
        std::cerr <<e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
