#include <pluginlib/class_list_macros.h>


#include "gripper_transmission.h"
#include "gripper_transmission_loader.h"

using namespace Sting;

Transmission_Ptr Gripper_Transmission_Loader::loadTransmission(XmlRpc::XmlRpcValue& config)
{
    double reduction = config["reduction"];
    double joint_offset = 0.0;
    if (config.hasMember("joint_offset"))
    {
        joint_offset = config["joint_offset"];
    }

    return std::make_shared<Gripper_Transmission>(reduction, joint_offset);
}

PLUGINLIB_EXPORT_CLASS(Sting::Gripper_Transmission_Loader, Transmission_Loader_Plugin)