#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4497386892446686963);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4020535164465364860);
void pose_H_mod_fun(double *state, double *out_163641472803010022);
void pose_f_fun(double *state, double dt, double *out_7113476067971581844);
void pose_F_fun(double *state, double dt, double *out_4806322824000620331);
void pose_h_4(double *state, double *unused, double *out_2146936515699344985);
void pose_H_4(double *state, double *unused, double *out_9176625892716694514);
void pose_h_10(double *state, double *unused, double *out_7324595289411116285);
void pose_H_10(double *state, double *unused, double *out_6720236421065597274);
void pose_h_13(double *state, double *unused, double *out_3077593966437383014);
void pose_H_13(double *state, double *unused, double *out_6057844355660524301);
void pose_h_14(double *state, double *unused, double *out_5838993491781915029);
void pose_H_14(double *state, double *unused, double *out_5306877324653372573);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}