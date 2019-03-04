 #include"space_object.h"
 
Space_object::Space_object(Material material, Position position)
    : top_left_(position)
    , material_(material)
{
    
}
 
bool Space_object::is_space_junk() const
{
    return space_junk_;
}
Space_object::Material Space_object::material() const
{
    return material_;
}

Space_object::Position Space_object::position() const
{
    return top_left_;
}


Inertial_space_object::Inertial_space_object( Material material, Position position, Velocity velocity, Angular_velocity angular_velocity)
    : Space_object(material, position)
{
    
}

void Inertial_space_object::integrate(double dt)
{
    top_left_.x+=v_.width * dt;
    top_left_.y+=v_.height * dt;
    v_+=dv_;
}

void Inertial_space_object::set_angular_velocity(Angular_velocity vel)
{
    ddeg_=  vel;
}

Inertial_space_object::Acceleration Inertial_space_object::acceleration() const
{
    return dv_ ;
}
