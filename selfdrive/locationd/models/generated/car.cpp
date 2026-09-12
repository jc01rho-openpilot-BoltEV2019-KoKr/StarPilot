#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1326346818289980211) {
   out_1326346818289980211[0] = delta_x[0] + nom_x[0];
   out_1326346818289980211[1] = delta_x[1] + nom_x[1];
   out_1326346818289980211[2] = delta_x[2] + nom_x[2];
   out_1326346818289980211[3] = delta_x[3] + nom_x[3];
   out_1326346818289980211[4] = delta_x[4] + nom_x[4];
   out_1326346818289980211[5] = delta_x[5] + nom_x[5];
   out_1326346818289980211[6] = delta_x[6] + nom_x[6];
   out_1326346818289980211[7] = delta_x[7] + nom_x[7];
   out_1326346818289980211[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7721308480372758585) {
   out_7721308480372758585[0] = -nom_x[0] + true_x[0];
   out_7721308480372758585[1] = -nom_x[1] + true_x[1];
   out_7721308480372758585[2] = -nom_x[2] + true_x[2];
   out_7721308480372758585[3] = -nom_x[3] + true_x[3];
   out_7721308480372758585[4] = -nom_x[4] + true_x[4];
   out_7721308480372758585[5] = -nom_x[5] + true_x[5];
   out_7721308480372758585[6] = -nom_x[6] + true_x[6];
   out_7721308480372758585[7] = -nom_x[7] + true_x[7];
   out_7721308480372758585[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8221305666287256291) {
   out_8221305666287256291[0] = 1.0;
   out_8221305666287256291[1] = 0.0;
   out_8221305666287256291[2] = 0.0;
   out_8221305666287256291[3] = 0.0;
   out_8221305666287256291[4] = 0.0;
   out_8221305666287256291[5] = 0.0;
   out_8221305666287256291[6] = 0.0;
   out_8221305666287256291[7] = 0.0;
   out_8221305666287256291[8] = 0.0;
   out_8221305666287256291[9] = 0.0;
   out_8221305666287256291[10] = 1.0;
   out_8221305666287256291[11] = 0.0;
   out_8221305666287256291[12] = 0.0;
   out_8221305666287256291[13] = 0.0;
   out_8221305666287256291[14] = 0.0;
   out_8221305666287256291[15] = 0.0;
   out_8221305666287256291[16] = 0.0;
   out_8221305666287256291[17] = 0.0;
   out_8221305666287256291[18] = 0.0;
   out_8221305666287256291[19] = 0.0;
   out_8221305666287256291[20] = 1.0;
   out_8221305666287256291[21] = 0.0;
   out_8221305666287256291[22] = 0.0;
   out_8221305666287256291[23] = 0.0;
   out_8221305666287256291[24] = 0.0;
   out_8221305666287256291[25] = 0.0;
   out_8221305666287256291[26] = 0.0;
   out_8221305666287256291[27] = 0.0;
   out_8221305666287256291[28] = 0.0;
   out_8221305666287256291[29] = 0.0;
   out_8221305666287256291[30] = 1.0;
   out_8221305666287256291[31] = 0.0;
   out_8221305666287256291[32] = 0.0;
   out_8221305666287256291[33] = 0.0;
   out_8221305666287256291[34] = 0.0;
   out_8221305666287256291[35] = 0.0;
   out_8221305666287256291[36] = 0.0;
   out_8221305666287256291[37] = 0.0;
   out_8221305666287256291[38] = 0.0;
   out_8221305666287256291[39] = 0.0;
   out_8221305666287256291[40] = 1.0;
   out_8221305666287256291[41] = 0.0;
   out_8221305666287256291[42] = 0.0;
   out_8221305666287256291[43] = 0.0;
   out_8221305666287256291[44] = 0.0;
   out_8221305666287256291[45] = 0.0;
   out_8221305666287256291[46] = 0.0;
   out_8221305666287256291[47] = 0.0;
   out_8221305666287256291[48] = 0.0;
   out_8221305666287256291[49] = 0.0;
   out_8221305666287256291[50] = 1.0;
   out_8221305666287256291[51] = 0.0;
   out_8221305666287256291[52] = 0.0;
   out_8221305666287256291[53] = 0.0;
   out_8221305666287256291[54] = 0.0;
   out_8221305666287256291[55] = 0.0;
   out_8221305666287256291[56] = 0.0;
   out_8221305666287256291[57] = 0.0;
   out_8221305666287256291[58] = 0.0;
   out_8221305666287256291[59] = 0.0;
   out_8221305666287256291[60] = 1.0;
   out_8221305666287256291[61] = 0.0;
   out_8221305666287256291[62] = 0.0;
   out_8221305666287256291[63] = 0.0;
   out_8221305666287256291[64] = 0.0;
   out_8221305666287256291[65] = 0.0;
   out_8221305666287256291[66] = 0.0;
   out_8221305666287256291[67] = 0.0;
   out_8221305666287256291[68] = 0.0;
   out_8221305666287256291[69] = 0.0;
   out_8221305666287256291[70] = 1.0;
   out_8221305666287256291[71] = 0.0;
   out_8221305666287256291[72] = 0.0;
   out_8221305666287256291[73] = 0.0;
   out_8221305666287256291[74] = 0.0;
   out_8221305666287256291[75] = 0.0;
   out_8221305666287256291[76] = 0.0;
   out_8221305666287256291[77] = 0.0;
   out_8221305666287256291[78] = 0.0;
   out_8221305666287256291[79] = 0.0;
   out_8221305666287256291[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4355494038563606728) {
   out_4355494038563606728[0] = state[0];
   out_4355494038563606728[1] = state[1];
   out_4355494038563606728[2] = state[2];
   out_4355494038563606728[3] = state[3];
   out_4355494038563606728[4] = state[4];
   out_4355494038563606728[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4355494038563606728[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4355494038563606728[7] = state[7];
   out_4355494038563606728[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8878866990102607558) {
   out_8878866990102607558[0] = 1;
   out_8878866990102607558[1] = 0;
   out_8878866990102607558[2] = 0;
   out_8878866990102607558[3] = 0;
   out_8878866990102607558[4] = 0;
   out_8878866990102607558[5] = 0;
   out_8878866990102607558[6] = 0;
   out_8878866990102607558[7] = 0;
   out_8878866990102607558[8] = 0;
   out_8878866990102607558[9] = 0;
   out_8878866990102607558[10] = 1;
   out_8878866990102607558[11] = 0;
   out_8878866990102607558[12] = 0;
   out_8878866990102607558[13] = 0;
   out_8878866990102607558[14] = 0;
   out_8878866990102607558[15] = 0;
   out_8878866990102607558[16] = 0;
   out_8878866990102607558[17] = 0;
   out_8878866990102607558[18] = 0;
   out_8878866990102607558[19] = 0;
   out_8878866990102607558[20] = 1;
   out_8878866990102607558[21] = 0;
   out_8878866990102607558[22] = 0;
   out_8878866990102607558[23] = 0;
   out_8878866990102607558[24] = 0;
   out_8878866990102607558[25] = 0;
   out_8878866990102607558[26] = 0;
   out_8878866990102607558[27] = 0;
   out_8878866990102607558[28] = 0;
   out_8878866990102607558[29] = 0;
   out_8878866990102607558[30] = 1;
   out_8878866990102607558[31] = 0;
   out_8878866990102607558[32] = 0;
   out_8878866990102607558[33] = 0;
   out_8878866990102607558[34] = 0;
   out_8878866990102607558[35] = 0;
   out_8878866990102607558[36] = 0;
   out_8878866990102607558[37] = 0;
   out_8878866990102607558[38] = 0;
   out_8878866990102607558[39] = 0;
   out_8878866990102607558[40] = 1;
   out_8878866990102607558[41] = 0;
   out_8878866990102607558[42] = 0;
   out_8878866990102607558[43] = 0;
   out_8878866990102607558[44] = 0;
   out_8878866990102607558[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8878866990102607558[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8878866990102607558[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8878866990102607558[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8878866990102607558[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8878866990102607558[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8878866990102607558[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8878866990102607558[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8878866990102607558[53] = -9.8100000000000005*dt;
   out_8878866990102607558[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8878866990102607558[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8878866990102607558[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8878866990102607558[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8878866990102607558[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8878866990102607558[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8878866990102607558[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8878866990102607558[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8878866990102607558[62] = 0;
   out_8878866990102607558[63] = 0;
   out_8878866990102607558[64] = 0;
   out_8878866990102607558[65] = 0;
   out_8878866990102607558[66] = 0;
   out_8878866990102607558[67] = 0;
   out_8878866990102607558[68] = 0;
   out_8878866990102607558[69] = 0;
   out_8878866990102607558[70] = 1;
   out_8878866990102607558[71] = 0;
   out_8878866990102607558[72] = 0;
   out_8878866990102607558[73] = 0;
   out_8878866990102607558[74] = 0;
   out_8878866990102607558[75] = 0;
   out_8878866990102607558[76] = 0;
   out_8878866990102607558[77] = 0;
   out_8878866990102607558[78] = 0;
   out_8878866990102607558[79] = 0;
   out_8878866990102607558[80] = 1;
}
void h_25(double *state, double *unused, double *out_7662070615539319427) {
   out_7662070615539319427[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6916966556095284671) {
   out_6916966556095284671[0] = 0;
   out_6916966556095284671[1] = 0;
   out_6916966556095284671[2] = 0;
   out_6916966556095284671[3] = 0;
   out_6916966556095284671[4] = 0;
   out_6916966556095284671[5] = 0;
   out_6916966556095284671[6] = 1;
   out_6916966556095284671[7] = 0;
   out_6916966556095284671[8] = 0;
}
void h_24(double *state, double *unused, double *out_552573547376297234) {
   out_552573547376297234[0] = state[4];
   out_552573547376297234[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5718391886591489980) {
   out_5718391886591489980[0] = 0;
   out_5718391886591489980[1] = 0;
   out_5718391886591489980[2] = 0;
   out_5718391886591489980[3] = 0;
   out_5718391886591489980[4] = 1;
   out_5718391886591489980[5] = 0;
   out_5718391886591489980[6] = 0;
   out_5718391886591489980[7] = 0;
   out_5718391886591489980[8] = 0;
   out_5718391886591489980[9] = 0;
   out_5718391886591489980[10] = 0;
   out_5718391886591489980[11] = 0;
   out_5718391886591489980[12] = 0;
   out_5718391886591489980[13] = 0;
   out_5718391886591489980[14] = 1;
   out_5718391886591489980[15] = 0;
   out_5718391886591489980[16] = 0;
   out_5718391886591489980[17] = 0;
}
void h_30(double *state, double *unused, double *out_9064035073689776395) {
   out_9064035073689776395[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2389270225967676473) {
   out_2389270225967676473[0] = 0;
   out_2389270225967676473[1] = 0;
   out_2389270225967676473[2] = 0;
   out_2389270225967676473[3] = 0;
   out_2389270225967676473[4] = 1;
   out_2389270225967676473[5] = 0;
   out_2389270225967676473[6] = 0;
   out_2389270225967676473[7] = 0;
   out_2389270225967676473[8] = 0;
}
void h_26(double *state, double *unused, double *out_1162711888116392193) {
   out_1162711888116392193[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3175463237221228447) {
   out_3175463237221228447[0] = 0;
   out_3175463237221228447[1] = 0;
   out_3175463237221228447[2] = 0;
   out_3175463237221228447[3] = 0;
   out_3175463237221228447[4] = 0;
   out_3175463237221228447[5] = 0;
   out_3175463237221228447[6] = 0;
   out_3175463237221228447[7] = 1;
   out_3175463237221228447[8] = 0;
}
void h_27(double *state, double *unused, double *out_4113321920138957337) {
   out_4113321920138957337[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4612864297151619690) {
   out_4612864297151619690[0] = 0;
   out_4612864297151619690[1] = 0;
   out_4612864297151619690[2] = 0;
   out_4612864297151619690[3] = 1;
   out_4612864297151619690[4] = 0;
   out_4612864297151619690[5] = 0;
   out_4612864297151619690[6] = 0;
   out_4612864297151619690[7] = 0;
   out_4612864297151619690[8] = 0;
}
void h_29(double *state, double *unused, double *out_7215941399213971055) {
   out_7215941399213971055[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2899501570282068657) {
   out_2899501570282068657[0] = 0;
   out_2899501570282068657[1] = 1;
   out_2899501570282068657[2] = 0;
   out_2899501570282068657[3] = 0;
   out_2899501570282068657[4] = 0;
   out_2899501570282068657[5] = 0;
   out_2899501570282068657[6] = 0;
   out_2899501570282068657[7] = 0;
   out_2899501570282068657[8] = 0;
}
void h_28(double *state, double *unused, double *out_1529407950941999498) {
   out_1529407950941999498[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2182897446787461917) {
   out_2182897446787461917[0] = 1;
   out_2182897446787461917[1] = 0;
   out_2182897446787461917[2] = 0;
   out_2182897446787461917[3] = 0;
   out_2182897446787461917[4] = 0;
   out_2182897446787461917[5] = 0;
   out_2182897446787461917[6] = 0;
   out_2182897446787461917[7] = 0;
   out_2182897446787461917[8] = 0;
}
void h_31(double *state, double *unused, double *out_5470065409481246982) {
   out_5470065409481246982[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6947612517972245099) {
   out_6947612517972245099[0] = 0;
   out_6947612517972245099[1] = 0;
   out_6947612517972245099[2] = 0;
   out_6947612517972245099[3] = 0;
   out_6947612517972245099[4] = 0;
   out_6947612517972245099[5] = 0;
   out_6947612517972245099[6] = 0;
   out_6947612517972245099[7] = 0;
   out_6947612517972245099[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1326346818289980211) {
  err_fun(nom_x, delta_x, out_1326346818289980211);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7721308480372758585) {
  inv_err_fun(nom_x, true_x, out_7721308480372758585);
}
void car_H_mod_fun(double *state, double *out_8221305666287256291) {
  H_mod_fun(state, out_8221305666287256291);
}
void car_f_fun(double *state, double dt, double *out_4355494038563606728) {
  f_fun(state,  dt, out_4355494038563606728);
}
void car_F_fun(double *state, double dt, double *out_8878866990102607558) {
  F_fun(state,  dt, out_8878866990102607558);
}
void car_h_25(double *state, double *unused, double *out_7662070615539319427) {
  h_25(state, unused, out_7662070615539319427);
}
void car_H_25(double *state, double *unused, double *out_6916966556095284671) {
  H_25(state, unused, out_6916966556095284671);
}
void car_h_24(double *state, double *unused, double *out_552573547376297234) {
  h_24(state, unused, out_552573547376297234);
}
void car_H_24(double *state, double *unused, double *out_5718391886591489980) {
  H_24(state, unused, out_5718391886591489980);
}
void car_h_30(double *state, double *unused, double *out_9064035073689776395) {
  h_30(state, unused, out_9064035073689776395);
}
void car_H_30(double *state, double *unused, double *out_2389270225967676473) {
  H_30(state, unused, out_2389270225967676473);
}
void car_h_26(double *state, double *unused, double *out_1162711888116392193) {
  h_26(state, unused, out_1162711888116392193);
}
void car_H_26(double *state, double *unused, double *out_3175463237221228447) {
  H_26(state, unused, out_3175463237221228447);
}
void car_h_27(double *state, double *unused, double *out_4113321920138957337) {
  h_27(state, unused, out_4113321920138957337);
}
void car_H_27(double *state, double *unused, double *out_4612864297151619690) {
  H_27(state, unused, out_4612864297151619690);
}
void car_h_29(double *state, double *unused, double *out_7215941399213971055) {
  h_29(state, unused, out_7215941399213971055);
}
void car_H_29(double *state, double *unused, double *out_2899501570282068657) {
  H_29(state, unused, out_2899501570282068657);
}
void car_h_28(double *state, double *unused, double *out_1529407950941999498) {
  h_28(state, unused, out_1529407950941999498);
}
void car_H_28(double *state, double *unused, double *out_2182897446787461917) {
  H_28(state, unused, out_2182897446787461917);
}
void car_h_31(double *state, double *unused, double *out_5470065409481246982) {
  h_31(state, unused, out_5470065409481246982);
}
void car_H_31(double *state, double *unused, double *out_6947612517972245099) {
  H_31(state, unused, out_6947612517972245099);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
