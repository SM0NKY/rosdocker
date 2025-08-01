#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include <chrono>

using namespace std::chrono_literals;

class JointStatePublisher : public rclcpp::Node{

public:
    JointStatePublisher() : Node("joint_state_publisher") {
        joint_state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
        timer_ = this->create_wall_timer(100ms, std::bind(&JointStatePublisher::publish_joint_state, this));
        position_ = 0.0;

private:
    void publish_joint_state(){
        auto msg = sensor_msgs::msg::JointState();
        msg.header.stamp = this->now();
        msg.name = {"joint1"};
        msg.position = {position_};
        position_ += 0.1;
    }
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double position_;
    }
}

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JointStatePublisher>());
    rclcpp::shutdown();
    return 0;
}