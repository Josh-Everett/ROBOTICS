#include <kipr/botball.h>
void drive_forward();
void back_up();
void turn_left();
void turn_right();
void check_dist();

//drive straght for whenever the road is clear
void drive_forward(){
   motor(0, 50);
   motor(1, 50);
   msleep(500);
}
//drive reverse for 1 second
void back_up(){
    motor(0, -50);
    motor(1, -50);
    msleep(500);
}
//turn sharp left 
void turn_sharpLeft(){
    motor(0, 50);
    motor(1, -50);
    msleep(500);
}  

//turn slight left 
void turn_slightLeft(){
    motor(0, 50);
    motor(1, 10);
    msleep(500); 

}

//turn sharp right 
void turn_sharpRight(){
    motor(0, -50);
    motor(1, 50);
    msleep(500);

}
//turn slight right 
void turn_slightRight(){
    motor(0, 10);
    motor(1, 50);
    msleep(500);  
}

void DUMP(){
    set_servo_position(3,2040);
    msleep(500);
    set_servo_position(3,500);
    return;
}
void PLOW(){
    set_servo_position(4, 2040);
    msleep(500);
    set_servo_position(4,500);
    return;

}

int main()
{    
    while(1) {
        enable_servos();
        PLOW();
        DUMP();
        disable_servos();
        ao();
    }
       
  
   	ao(); //stop all motors
    return 0; //end program
}
