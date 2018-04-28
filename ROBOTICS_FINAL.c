#include <kipr/botball.h>

// GLOBALS

// objects are red 
// dumpsite is blue
// OBJECT_CH = 0 , DUMPSITE_CH = 1
int ch = 0, 

// MOTORS
int leftmtr = 1, rghtmtr = 0; 

// VELOCITIES
int high = 75, med = 50,  low = 25; // set wheel powers for arc radius
int reverse_high = 75, reverse_med = 50, reverse_low = 25;

// if we are not in reactive mode we are acting deliberitely
// REACTIVE_MODE means we are using wander modules with bump sensor to 
// avoid objects.
// Begin execution in reactive mode
bool REACTIVE_MODE = true;


/*						//
//						//
//		 GLOBAL 		//						
//		 MODULES		//
//						//
*/						//



/*						//
//						//
//		REACTIVE 		//						
//		 MODULES		//
//						//
*/						//

void wander(){

}
void bump_reactive(){

}

/*						//
//						//
//		DELIBERATIVE    //						
//		 MODULES		//
//						//
*/						//

void bump_deliberative(){

}

void lift_plow(){

}
void orient_dump(){

}
void lift_dump(){

}


/*						//
//						//
//		   MAIN 	 	//						
//		  PROGRAM	    //
//						//
*/						//

int main(){
	

	
	camera_open();
	while(1) { 
        if (!camera_update()){
        	printf("Camera update failed. Retrying.\n");
        	continue; // restart loop
        }
        
        if(get_object_count(ch) == 0) { // if object is not seen...
        	printf("no object found");
        	// change from spinning in place to wander
        	// add code for REACT bump to navigate around obstacles 
            motor(rghtmtr,-50);
			motor(leftmtr,50); // arc right
            msleep(100);
            ao(); 
        }
        
        else{ // if object is seen...
			if(get_object_center_column(ch,0) < 65) { // if object is on left...
				motor(leftmtr,low);
				motor(rghtmtr,high); // arc left
			}
			else if(get_object_center_column(ch,0) > 95) {// if object is on right...
				motor(rghtmtr,low);
				motor(leftmtr,high); // arc right
			}			
            else {               
           		//go straight
            	motor(rghtmtr, high);
				motor(leftmtr, high); 
				msleep(200);              
            	
            }
            msleep(5);
        }
	}  // end while loop

    camera_close();
	ao(); // stop because button pressed
	printf("done\n");
	return 0;
}
