#ifndef ZIKOICHI_KUN_API_HPP_
#define ZIKOICHI_KUN_API_HPP_
namespace zk_api {
  inline void setup(void){
    pinMode(T4,OUTPUT); // CW.CCW-1 FR
    pinMode(T5,OUTPUT); // CW.CCW-2 FL
    pinMode(T6,OUTPUT); // CW.CCW-3 RL
    pinMode(T7,OUTPUT); // CW.CCW-4 RR
    // ledcAttach(16, 1000, 8);
    // ledcAttach(17, 1000, 8);
    // ledcAttach(18, 1000, 8);
    // ledcAttach(19, 1000, 8);
  }

  inline void front_right_pwm(int value){
    ledcWrite(16,value);
  }
  inline void front_left_pwm(int value){
    ledcWrite(17,value);
  }
  inline void rear_left_pwm(int value){
    ledcWrite(18,value);
  }
  inline void rear_right_pwm(int value){
    ledcWrite(19,value);
  }

  inline void front_right_cw_ccw(bool status){
    digitalWrite(T4,status);
  }
  inline void front_left_cw_ccw(bool status){
    digitalWrite(T5,status);
  }
  inline void rear_left_cw_ccw(bool status){
    digitalWrite(T6,status);
  }
  inline void rear_right_cw_ccw(bool status){
    digitalWrite(T7,status);
  }

  inline void control_front_right(int power){
    if(power > 255){power = 255;}
    if(power < -255){power = -255;}

    front_right_pwm(abs(power));
    
    if(power > 0){
      front_right_cw_ccw(HIGH);
    }else{
      front_right_cw_ccw(LOW);
    }
  }
  inline void control_front_left(int power){
    if(power > 255){power = 255;}
    if(power < -255){power = -255;}

    front_left_pwm(abs(power));
    
    if(power > 0){
      front_left_cw_ccw(HIGH);
    }else{
      front_left_cw_ccw(LOW);
    }
  }
  inline void control_rear_left(int power){
    if(power > 255){power = 255;}
    if(power < -255){power = -255;}

    rear_left_pwm(abs(power));
    
    if(power > 0){
      rear_left_cw_ccw(HIGH);
    }else{
      rear_left_cw_ccw(LOW);
    }
  }
  inline void control_rear_right(int power){
    if(power > 255){power = 255;}
    if(power < -255){power = -255;}

    rear_right_pwm(abs(power));
    
    if(power > 0){
      rear_right_cw_ccw(HIGH);
    }else{
      rear_right_cw_ccw(LOW);
    }
  }

  inline void xyz_control(float x, float y, float z, float power){
    int vec_fr =  (int)(power * ( 0.707106781 * x - 0.707106781 * y + 0.5 * z));
    int vec_fl =  (int)(power * (-0.707106781 * x - 0.707106781 * y + 0.5 * z));
    int vec_rl =  (int)(power * (-0.707106781 * x + 0.707106781 * y + 0.5 * z));
    int vec_rr =  (int)(power * ( 0.707106781 * x + 0.707106781 * y + 0.5 * z));

    vec_fr *= power;
    vec_fl *= power;
    vec_rl *= power;
    vec_rr *= power;

    if(vec_fr > 255){vec_fr = 255;}
    if(vec_fl > 255){vec_fl = 255;}
    if(vec_rl > 255){vec_rl = 255;}
    if(vec_rr > 255){vec_rr = 255;}

    if(vec_fr < -255){vec_fr = -255;}
    if(vec_fl < -255){vec_fl = -255;}
    if(vec_rl < -255){vec_rl = -255;}
    if(vec_rr < -255){vec_rr = -255;}

    control_front_right(vec_fr);
    control_front_left(vec_fl);
    control_rear_left(vec_rl);
    control_rear_right(vec_rr);
  }

}
#endif