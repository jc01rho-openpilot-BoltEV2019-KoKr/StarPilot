#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1326346818289980211);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7721308480372758585);
void car_H_mod_fun(double *state, double *out_8221305666287256291);
void car_f_fun(double *state, double dt, double *out_4355494038563606728);
void car_F_fun(double *state, double dt, double *out_8878866990102607558);
void car_h_25(double *state, double *unused, double *out_7662070615539319427);
void car_H_25(double *state, double *unused, double *out_6916966556095284671);
void car_h_24(double *state, double *unused, double *out_552573547376297234);
void car_H_24(double *state, double *unused, double *out_5718391886591489980);
void car_h_30(double *state, double *unused, double *out_9064035073689776395);
void car_H_30(double *state, double *unused, double *out_2389270225967676473);
void car_h_26(double *state, double *unused, double *out_1162711888116392193);
void car_H_26(double *state, double *unused, double *out_3175463237221228447);
void car_h_27(double *state, double *unused, double *out_4113321920138957337);
void car_H_27(double *state, double *unused, double *out_4612864297151619690);
void car_h_29(double *state, double *unused, double *out_7215941399213971055);
void car_H_29(double *state, double *unused, double *out_2899501570282068657);
void car_h_28(double *state, double *unused, double *out_1529407950941999498);
void car_H_28(double *state, double *unused, double *out_2182897446787461917);
void car_h_31(double *state, double *unused, double *out_5470065409481246982);
void car_H_31(double *state, double *unused, double *out_6947612517972245099);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}