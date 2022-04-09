#include <vulkan/vulkan.h>
//#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <VulkanBase.hpp>

using namespace std;
VulkanBase base(true);

class Vulkan_template{
    public:
        void run(){
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();         
        }
    private:

        void initWindow(){       
            base.initWindow();
        }
        void initVulkan(){  
            VkResult err = base.createInstance(true);
        }
        void mainLoop(){
            while(!glfwWindowShouldClose(base.getWindow())){
                glfwPollEvents();    
            }
        }
        void cleanup(){

        }
};

int main(){
    Vulkan_template app;

    try{
            app.run();        
    }catch (const std::exception& e){
        std::cerr <<e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
