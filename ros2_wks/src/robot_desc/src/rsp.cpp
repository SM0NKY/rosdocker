#include "rclcpp/rclcpp.hpp"
#include "robot_state_publisher/robot_state_publisher.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/join_state.hpp"
#include <memory>

class RobotStateNode : public rclcpp::Node {
public:
    RobotStateNode() : Node("robot_state_publisher_node"){
        std::string urdf_file;
        this->declare_paremeter("robot_description", urdf_file);
        this->get_parameter("robot_description", urdf_file);

        if (!model_.initString(urdf_file)){
            RCLCPP_ERROR(this->get_logger(), "Failed to load URDF model");
            return;
        }

        state_publisher_ = std::make_shared<robot_state_publisher::RobotStatePublisher>(model_);
        subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, [this](sensor_msgs::msg::JointState::UniquePtr msg){
            state_publisher_->publishTransforms(*msg, this->get_clock()->now());
        });

        
        
    }
private:
    urdf::Model model_;
    std::shared_ptr<robot_state_publisher::RobotStatePublisher> state_publisher_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
            
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotStateNode>());
    rclcpp::shutdown();
    return 0;
}
