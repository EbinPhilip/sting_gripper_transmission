#ifndef __STING_GRIPPER_TRANSMISSION_H__
#define __STING_GRIPPER_TRANSMISSION_H__

#include <transmission_interface/simple_transmission.h>

namespace Sting
{
    class Gripper_Transmission : public transmission_interface::SimpleTransmission
    {
    public:
        Gripper_Transmission(const double reduction, const double joint_offset = 0.0)
            : SimpleTransmission(reduction, joint_offset)
        {
        }

        inline void actuatorToJointEffort(const transmission_interface::ActuatorData &act_data,
                                          transmission_interface::JointData &jnt_data) override
        {
            assert(numActuators() == act_data.effort.size() && numJoints() == jnt_data.effort.size());
            assert(act_data.effort[0] && jnt_data.effort[0]);

            *jnt_data.effort[0] = *act_data.effort[0];
        }

        inline void jointToActuatorVelocity(const transmission_interface::JointData &jnt_data,
                                            transmission_interface::ActuatorData &act_data) override
        {
            assert(numActuators() == act_data.velocity.size() && numJoints() == jnt_data.velocity.size());
            assert(act_data.velocity[0] && jnt_data.velocity[0]);

            *act_data.velocity[0] = *jnt_data.velocity[0];
        }
    };
}

#endif