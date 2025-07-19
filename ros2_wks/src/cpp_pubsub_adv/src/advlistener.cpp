#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "cpp_pubsub_adv/msg/Status.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {

public:
    MinimalSubscriber()
    : Node("advanced_listener"){
        subscription_ = this->create_subscription<cpp_pubsub_adv::msg::Status>
            ("adv_topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

private:
    void topic_callback(const cpp_pubsub_adv::msg::Status::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(), "Recibido: '%s' (%ld)", msg->estado.c_str(), msg->code);
    }
    rclcpp::Subscription<cpp_pubsub_adv::msg::Status>::SharedPtr subscription_;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
} // 

