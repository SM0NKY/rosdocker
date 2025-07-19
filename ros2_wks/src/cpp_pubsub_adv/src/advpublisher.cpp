#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "cpp_pubsub_adv/msg/Status.hpp"

#include <chrono>
#include <sstream>

using namespace std::chrono_literals;

class AdvancedPublisher : public rclcpp::Node{
public:
    AdvancedPublisher() : Node ("advanced_publisher"), count_(0){
        publisher_ = this->create_publisher<cpp_pubsub_adv::msg::Status>("adv_topic", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&AdvancedPublisher::timer_callback, this));
    }
private:
    void timer_callback(){
        auto message = cpp_pubsub_adv::msg::Status();
        message.estado = "Todo bien por el momento";
        message.code = count_++;
        RCLCPP_INFO(this->get_logger(), "Publicando: '%s' (%d)", message.estado.c_str(), message.code);
        publisher_->publish(message);
    
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<cpp_pubsub_adv::msg::Status>::SharedPtr publisher_;
    size_t count_;
};


int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AdvancedPublisher>());
    rclcpp::shutdown();
    return 0;
}
    
