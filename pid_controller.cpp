/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {
}

PID::~PID() {}


void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini,int num_steps) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  kp=Kpi;
  kd=Kdi;
  ki=Kii;
  p_error=0;
  i_error=0;
  d_error=0;
  minLim=output_lim_mini;
  maxLim=output_lim_maxi;

  best_err = maxLim;

}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   
 if(dt>0){
   d_error=(cte - p_error)/dt;
 }
  else{
   d_error=0;
  }
  p_error=cte;
  i_error+=cte*dt;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
    control = d_error * kd + p_error * (kp) + i_error * (ki) ;

    return control;
}



double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  dt = new_delta_time;
}