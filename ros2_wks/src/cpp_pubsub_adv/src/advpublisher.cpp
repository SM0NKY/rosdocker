#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp" 
#include <chrono>
#include <sstream>

using namespace std::chrono_literals;

class AdvancedPublisher : public rclcpp::Node{
public:
    AdvancedPublisher() : Node ("advanced_publisher"), count_(0){
        publisher_ = this->create_publisher<std_msgs::msg::String>("advtopic", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&AdvancedPublisher::timer_callback, this));
    }
private:
    void timer_callback(){
        auto message = std_msgs::msg::String();
        std::ostringstream msg_stream;
        msg_stream << "Mensaje número: " << count_++;
        message.data = msg_stream.str();
        RCLCPP_INFO(this->get_logger(), "Publicando: '%s'", message.data.c_str());
        publisher_->publish(message);
    
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};


int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AdvancedPublisher>());
    rclcpp::shutdown();
    return 0;
}
    
