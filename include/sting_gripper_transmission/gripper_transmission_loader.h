#ifndef __STING_GRIPPER_TRANSMISSION_LOADER_H__
#define __STING_GRIPPER_TRANSMISSION_LOADER_H__

#include <configurable_control_hw/Transmission_Loader_Plugin.h>

namespace Sting
{
    class Gripper_Transmission_Loader : public Transmission_Loader_Plugin
    {
        public:
        virtual Transmission_Ptr loadTransmission(XmlRpc::XmlRpcValue& config) override;
    };
}

#endif