#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4497386892446686963) {
   out_4497386892446686963[0] = delta_x[0] + nom_x[0];
   out_4497386892446686963[1] = delta_x[1] + nom_x[1];
   out_4497386892446686963[2] = delta_x[2] + nom_x[2];
   out_4497386892446686963[3] = delta_x[3] + nom_x[3];
   out_4497386892446686963[4] = delta_x[4] + nom_x[4];
   out_4497386892446686963[5] = delta_x[5] + nom_x[5];
   out_4497386892446686963[6] = delta_x[6] + nom_x[6];
   out_4497386892446686963[7] = delta_x[7] + nom_x[7];
   out_4497386892446686963[8] = delta_x[8] + nom_x[8];
   out_4497386892446686963[9] = delta_x[9] + nom_x[9];
   out_4497386892446686963[10] = delta_x[10] + nom_x[10];
   out_4497386892446686963[11] = delta_x[11] + nom_x[11];
   out_4497386892446686963[12] = delta_x[12] + nom_x[12];
   out_4497386892446686963[13] = delta_x[13] + nom_x[13];
   out_4497386892446686963[14] = delta_x[14] + nom_x[14];
   out_4497386892446686963[15] = delta_x[15] + nom_x[15];
   out_4497386892446686963[16] = delta_x[16] + nom_x[16];
   out_4497386892446686963[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4020535164465364860) {
   out_4020535164465364860[0] = -nom_x[0] + true_x[0];
   out_4020535164465364860[1] = -nom_x[1] + true_x[1];
   out_4020535164465364860[2] = -nom_x[2] + true_x[2];
   out_4020535164465364860[3] = -nom_x[3] + true_x[3];
   out_4020535164465364860[4] = -nom_x[4] + true_x[4];
   out_4020535164465364860[5] = -nom_x[5] + true_x[5];
   out_4020535164465364860[6] = -nom_x[6] + true_x[6];
   out_4020535164465364860[7] = -nom_x[7] + true_x[7];
   out_4020535164465364860[8] = -nom_x[8] + true_x[8];
   out_4020535164465364860[9] = -nom_x[9] + true_x[9];
   out_4020535164465364860[10] = -nom_x[10] + true_x[10];
   out_4020535164465364860[11] = -nom_x[11] + true_x[11];
   out_4020535164465364860[12] = -nom_x[12] + true_x[12];
   out_4020535164465364860[13] = -nom_x[13] + true_x[13];
   out_4020535164465364860[14] = -nom_x[14] + true_x[14];
   out_4020535164465364860[15] = -nom_x[15] + true_x[15];
   out_4020535164465364860[16] = -nom_x[16] + true_x[16];
   out_4020535164465364860[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_163641472803010022) {
   out_163641472803010022[0] = 1.0;
   out_163641472803010022[1] = 0.0;
   out_163641472803010022[2] = 0.0;
   out_163641472803010022[3] = 0.0;
   out_163641472803010022[4] = 0.0;
   out_163641472803010022[5] = 0.0;
   out_163641472803010022[6] = 0.0;
   out_163641472803010022[7] = 0.0;
   out_163641472803010022[8] = 0.0;
   out_163641472803010022[9] = 0.0;
   out_163641472803010022[10] = 0.0;
   out_163641472803010022[11] = 0.0;
   out_163641472803010022[12] = 0.0;
   out_163641472803010022[13] = 0.0;
   out_163641472803010022[14] = 0.0;
   out_163641472803010022[15] = 0.0;
   out_163641472803010022[16] = 0.0;
   out_163641472803010022[17] = 0.0;
   out_163641472803010022[18] = 0.0;
   out_163641472803010022[19] = 1.0;
   out_163641472803010022[20] = 0.0;
   out_163641472803010022[21] = 0.0;
   out_163641472803010022[22] = 0.0;
   out_163641472803010022[23] = 0.0;
   out_163641472803010022[24] = 0.0;
   out_163641472803010022[25] = 0.0;
   out_163641472803010022[26] = 0.0;
   out_163641472803010022[27] = 0.0;
   out_163641472803010022[28] = 0.0;
   out_163641472803010022[29] = 0.0;
   out_163641472803010022[30] = 0.0;
   out_163641472803010022[31] = 0.0;
   out_163641472803010022[32] = 0.0;
   out_163641472803010022[33] = 0.0;
   out_163641472803010022[34] = 0.0;
   out_163641472803010022[35] = 0.0;
   out_163641472803010022[36] = 0.0;
   out_163641472803010022[37] = 0.0;
   out_163641472803010022[38] = 1.0;
   out_163641472803010022[39] = 0.0;
   out_163641472803010022[40] = 0.0;
   out_163641472803010022[41] = 0.0;
   out_163641472803010022[42] = 0.0;
   out_163641472803010022[43] = 0.0;
   out_163641472803010022[44] = 0.0;
   out_163641472803010022[45] = 0.0;
   out_163641472803010022[46] = 0.0;
   out_163641472803010022[47] = 0.0;
   out_163641472803010022[48] = 0.0;
   out_163641472803010022[49] = 0.0;
   out_163641472803010022[50] = 0.0;
   out_163641472803010022[51] = 0.0;
   out_163641472803010022[52] = 0.0;
   out_163641472803010022[53] = 0.0;
   out_163641472803010022[54] = 0.0;
   out_163641472803010022[55] = 0.0;
   out_163641472803010022[56] = 0.0;
   out_163641472803010022[57] = 1.0;
   out_163641472803010022[58] = 0.0;
   out_163641472803010022[59] = 0.0;
   out_163641472803010022[60] = 0.0;
   out_163641472803010022[61] = 0.0;
   out_163641472803010022[62] = 0.0;
   out_163641472803010022[63] = 0.0;
   out_163641472803010022[64] = 0.0;
   out_163641472803010022[65] = 0.0;
   out_163641472803010022[66] = 0.0;
   out_163641472803010022[67] = 0.0;
   out_163641472803010022[68] = 0.0;
   out_163641472803010022[69] = 0.0;
   out_163641472803010022[70] = 0.0;
   out_163641472803010022[71] = 0.0;
   out_163641472803010022[72] = 0.0;
   out_163641472803010022[73] = 0.0;
   out_163641472803010022[74] = 0.0;
   out_163641472803010022[75] = 0.0;
   out_163641472803010022[76] = 1.0;
   out_163641472803010022[77] = 0.0;
   out_163641472803010022[78] = 0.0;
   out_163641472803010022[79] = 0.0;
   out_163641472803010022[80] = 0.0;
   out_163641472803010022[81] = 0.0;
   out_163641472803010022[82] = 0.0;
   out_163641472803010022[83] = 0.0;
   out_163641472803010022[84] = 0.0;
   out_163641472803010022[85] = 0.0;
   out_163641472803010022[86] = 0.0;
   out_163641472803010022[87] = 0.0;
   out_163641472803010022[88] = 0.0;
   out_163641472803010022[89] = 0.0;
   out_163641472803010022[90] = 0.0;
   out_163641472803010022[91] = 0.0;
   out_163641472803010022[92] = 0.0;
   out_163641472803010022[93] = 0.0;
   out_163641472803010022[94] = 0.0;
   out_163641472803010022[95] = 1.0;
   out_163641472803010022[96] = 0.0;
   out_163641472803010022[97] = 0.0;
   out_163641472803010022[98] = 0.0;
   out_163641472803010022[99] = 0.0;
   out_163641472803010022[100] = 0.0;
   out_163641472803010022[101] = 0.0;
   out_163641472803010022[102] = 0.0;
   out_163641472803010022[103] = 0.0;
   out_163641472803010022[104] = 0.0;
   out_163641472803010022[105] = 0.0;
   out_163641472803010022[106] = 0.0;
   out_163641472803010022[107] = 0.0;
   out_163641472803010022[108] = 0.0;
   out_163641472803010022[109] = 0.0;
   out_163641472803010022[110] = 0.0;
   out_163641472803010022[111] = 0.0;
   out_163641472803010022[112] = 0.0;
   out_163641472803010022[113] = 0.0;
   out_163641472803010022[114] = 1.0;
   out_163641472803010022[115] = 0.0;
   out_163641472803010022[116] = 0.0;
   out_163641472803010022[117] = 0.0;
   out_163641472803010022[118] = 0.0;
   out_163641472803010022[119] = 0.0;
   out_163641472803010022[120] = 0.0;
   out_163641472803010022[121] = 0.0;
   out_163641472803010022[122] = 0.0;
   out_163641472803010022[123] = 0.0;
   out_163641472803010022[124] = 0.0;
   out_163641472803010022[125] = 0.0;
   out_163641472803010022[126] = 0.0;
   out_163641472803010022[127] = 0.0;
   out_163641472803010022[128] = 0.0;
   out_163641472803010022[129] = 0.0;
   out_163641472803010022[130] = 0.0;
   out_163641472803010022[131] = 0.0;
   out_163641472803010022[132] = 0.0;
   out_163641472803010022[133] = 1.0;
   out_163641472803010022[134] = 0.0;
   out_163641472803010022[135] = 0.0;
   out_163641472803010022[136] = 0.0;
   out_163641472803010022[137] = 0.0;
   out_163641472803010022[138] = 0.0;
   out_163641472803010022[139] = 0.0;
   out_163641472803010022[140] = 0.0;
   out_163641472803010022[141] = 0.0;
   out_163641472803010022[142] = 0.0;
   out_163641472803010022[143] = 0.0;
   out_163641472803010022[144] = 0.0;
   out_163641472803010022[145] = 0.0;
   out_163641472803010022[146] = 0.0;
   out_163641472803010022[147] = 0.0;
   out_163641472803010022[148] = 0.0;
   out_163641472803010022[149] = 0.0;
   out_163641472803010022[150] = 0.0;
   out_163641472803010022[151] = 0.0;
   out_163641472803010022[152] = 1.0;
   out_163641472803010022[153] = 0.0;
   out_163641472803010022[154] = 0.0;
   out_163641472803010022[155] = 0.0;
   out_163641472803010022[156] = 0.0;
   out_163641472803010022[157] = 0.0;
   out_163641472803010022[158] = 0.0;
   out_163641472803010022[159] = 0.0;
   out_163641472803010022[160] = 0.0;
   out_163641472803010022[161] = 0.0;
   out_163641472803010022[162] = 0.0;
   out_163641472803010022[163] = 0.0;
   out_163641472803010022[164] = 0.0;
   out_163641472803010022[165] = 0.0;
   out_163641472803010022[166] = 0.0;
   out_163641472803010022[167] = 0.0;
   out_163641472803010022[168] = 0.0;
   out_163641472803010022[169] = 0.0;
   out_163641472803010022[170] = 0.0;
   out_163641472803010022[171] = 1.0;
   out_163641472803010022[172] = 0.0;
   out_163641472803010022[173] = 0.0;
   out_163641472803010022[174] = 0.0;
   out_163641472803010022[175] = 0.0;
   out_163641472803010022[176] = 0.0;
   out_163641472803010022[177] = 0.0;
   out_163641472803010022[178] = 0.0;
   out_163641472803010022[179] = 0.0;
   out_163641472803010022[180] = 0.0;
   out_163641472803010022[181] = 0.0;
   out_163641472803010022[182] = 0.0;
   out_163641472803010022[183] = 0.0;
   out_163641472803010022[184] = 0.0;
   out_163641472803010022[185] = 0.0;
   out_163641472803010022[186] = 0.0;
   out_163641472803010022[187] = 0.0;
   out_163641472803010022[188] = 0.0;
   out_163641472803010022[189] = 0.0;
   out_163641472803010022[190] = 1.0;
   out_163641472803010022[191] = 0.0;
   out_163641472803010022[192] = 0.0;
   out_163641472803010022[193] = 0.0;
   out_163641472803010022[194] = 0.0;
   out_163641472803010022[195] = 0.0;
   out_163641472803010022[196] = 0.0;
   out_163641472803010022[197] = 0.0;
   out_163641472803010022[198] = 0.0;
   out_163641472803010022[199] = 0.0;
   out_163641472803010022[200] = 0.0;
   out_163641472803010022[201] = 0.0;
   out_163641472803010022[202] = 0.0;
   out_163641472803010022[203] = 0.0;
   out_163641472803010022[204] = 0.0;
   out_163641472803010022[205] = 0.0;
   out_163641472803010022[206] = 0.0;
   out_163641472803010022[207] = 0.0;
   out_163641472803010022[208] = 0.0;
   out_163641472803010022[209] = 1.0;
   out_163641472803010022[210] = 0.0;
   out_163641472803010022[211] = 0.0;
   out_163641472803010022[212] = 0.0;
   out_163641472803010022[213] = 0.0;
   out_163641472803010022[214] = 0.0;
   out_163641472803010022[215] = 0.0;
   out_163641472803010022[216] = 0.0;
   out_163641472803010022[217] = 0.0;
   out_163641472803010022[218] = 0.0;
   out_163641472803010022[219] = 0.0;
   out_163641472803010022[220] = 0.0;
   out_163641472803010022[221] = 0.0;
   out_163641472803010022[222] = 0.0;
   out_163641472803010022[223] = 0.0;
   out_163641472803010022[224] = 0.0;
   out_163641472803010022[225] = 0.0;
   out_163641472803010022[226] = 0.0;
   out_163641472803010022[227] = 0.0;
   out_163641472803010022[228] = 1.0;
   out_163641472803010022[229] = 0.0;
   out_163641472803010022[230] = 0.0;
   out_163641472803010022[231] = 0.0;
   out_163641472803010022[232] = 0.0;
   out_163641472803010022[233] = 0.0;
   out_163641472803010022[234] = 0.0;
   out_163641472803010022[235] = 0.0;
   out_163641472803010022[236] = 0.0;
   out_163641472803010022[237] = 0.0;
   out_163641472803010022[238] = 0.0;
   out_163641472803010022[239] = 0.0;
   out_163641472803010022[240] = 0.0;
   out_163641472803010022[241] = 0.0;
   out_163641472803010022[242] = 0.0;
   out_163641472803010022[243] = 0.0;
   out_163641472803010022[244] = 0.0;
   out_163641472803010022[245] = 0.0;
   out_163641472803010022[246] = 0.0;
   out_163641472803010022[247] = 1.0;
   out_163641472803010022[248] = 0.0;
   out_163641472803010022[249] = 0.0;
   out_163641472803010022[250] = 0.0;
   out_163641472803010022[251] = 0.0;
   out_163641472803010022[252] = 0.0;
   out_163641472803010022[253] = 0.0;
   out_163641472803010022[254] = 0.0;
   out_163641472803010022[255] = 0.0;
   out_163641472803010022[256] = 0.0;
   out_163641472803010022[257] = 0.0;
   out_163641472803010022[258] = 0.0;
   out_163641472803010022[259] = 0.0;
   out_163641472803010022[260] = 0.0;
   out_163641472803010022[261] = 0.0;
   out_163641472803010022[262] = 0.0;
   out_163641472803010022[263] = 0.0;
   out_163641472803010022[264] = 0.0;
   out_163641472803010022[265] = 0.0;
   out_163641472803010022[266] = 1.0;
   out_163641472803010022[267] = 0.0;
   out_163641472803010022[268] = 0.0;
   out_163641472803010022[269] = 0.0;
   out_163641472803010022[270] = 0.0;
   out_163641472803010022[271] = 0.0;
   out_163641472803010022[272] = 0.0;
   out_163641472803010022[273] = 0.0;
   out_163641472803010022[274] = 0.0;
   out_163641472803010022[275] = 0.0;
   out_163641472803010022[276] = 0.0;
   out_163641472803010022[277] = 0.0;
   out_163641472803010022[278] = 0.0;
   out_163641472803010022[279] = 0.0;
   out_163641472803010022[280] = 0.0;
   out_163641472803010022[281] = 0.0;
   out_163641472803010022[282] = 0.0;
   out_163641472803010022[283] = 0.0;
   out_163641472803010022[284] = 0.0;
   out_163641472803010022[285] = 1.0;
   out_163641472803010022[286] = 0.0;
   out_163641472803010022[287] = 0.0;
   out_163641472803010022[288] = 0.0;
   out_163641472803010022[289] = 0.0;
   out_163641472803010022[290] = 0.0;
   out_163641472803010022[291] = 0.0;
   out_163641472803010022[292] = 0.0;
   out_163641472803010022[293] = 0.0;
   out_163641472803010022[294] = 0.0;
   out_163641472803010022[295] = 0.0;
   out_163641472803010022[296] = 0.0;
   out_163641472803010022[297] = 0.0;
   out_163641472803010022[298] = 0.0;
   out_163641472803010022[299] = 0.0;
   out_163641472803010022[300] = 0.0;
   out_163641472803010022[301] = 0.0;
   out_163641472803010022[302] = 0.0;
   out_163641472803010022[303] = 0.0;
   out_163641472803010022[304] = 1.0;
   out_163641472803010022[305] = 0.0;
   out_163641472803010022[306] = 0.0;
   out_163641472803010022[307] = 0.0;
   out_163641472803010022[308] = 0.0;
   out_163641472803010022[309] = 0.0;
   out_163641472803010022[310] = 0.0;
   out_163641472803010022[311] = 0.0;
   out_163641472803010022[312] = 0.0;
   out_163641472803010022[313] = 0.0;
   out_163641472803010022[314] = 0.0;
   out_163641472803010022[315] = 0.0;
   out_163641472803010022[316] = 0.0;
   out_163641472803010022[317] = 0.0;
   out_163641472803010022[318] = 0.0;
   out_163641472803010022[319] = 0.0;
   out_163641472803010022[320] = 0.0;
   out_163641472803010022[321] = 0.0;
   out_163641472803010022[322] = 0.0;
   out_163641472803010022[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7113476067971581844) {
   out_7113476067971581844[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7113476067971581844[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7113476067971581844[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7113476067971581844[3] = dt*state[12] + state[3];
   out_7113476067971581844[4] = dt*state[13] + state[4];
   out_7113476067971581844[5] = dt*state[14] + state[5];
   out_7113476067971581844[6] = state[6];
   out_7113476067971581844[7] = state[7];
   out_7113476067971581844[8] = state[8];
   out_7113476067971581844[9] = state[9];
   out_7113476067971581844[10] = state[10];
   out_7113476067971581844[11] = state[11];
   out_7113476067971581844[12] = state[12];
   out_7113476067971581844[13] = state[13];
   out_7113476067971581844[14] = state[14];
   out_7113476067971581844[15] = state[15];
   out_7113476067971581844[16] = state[16];
   out_7113476067971581844[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4806322824000620331) {
   out_4806322824000620331[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4806322824000620331[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4806322824000620331[2] = 0;
   out_4806322824000620331[3] = 0;
   out_4806322824000620331[4] = 0;
   out_4806322824000620331[5] = 0;
   out_4806322824000620331[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4806322824000620331[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4806322824000620331[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4806322824000620331[9] = 0;
   out_4806322824000620331[10] = 0;
   out_4806322824000620331[11] = 0;
   out_4806322824000620331[12] = 0;
   out_4806322824000620331[13] = 0;
   out_4806322824000620331[14] = 0;
   out_4806322824000620331[15] = 0;
   out_4806322824000620331[16] = 0;
   out_4806322824000620331[17] = 0;
   out_4806322824000620331[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4806322824000620331[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4806322824000620331[20] = 0;
   out_4806322824000620331[21] = 0;
   out_4806322824000620331[22] = 0;
   out_4806322824000620331[23] = 0;
   out_4806322824000620331[24] = 0;
   out_4806322824000620331[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4806322824000620331[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4806322824000620331[27] = 0;
   out_4806322824000620331[28] = 0;
   out_4806322824000620331[29] = 0;
   out_4806322824000620331[30] = 0;
   out_4806322824000620331[31] = 0;
   out_4806322824000620331[32] = 0;
   out_4806322824000620331[33] = 0;
   out_4806322824000620331[34] = 0;
   out_4806322824000620331[35] = 0;
   out_4806322824000620331[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4806322824000620331[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4806322824000620331[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4806322824000620331[39] = 0;
   out_4806322824000620331[40] = 0;
   out_4806322824000620331[41] = 0;
   out_4806322824000620331[42] = 0;
   out_4806322824000620331[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4806322824000620331[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4806322824000620331[45] = 0;
   out_4806322824000620331[46] = 0;
   out_4806322824000620331[47] = 0;
   out_4806322824000620331[48] = 0;
   out_4806322824000620331[49] = 0;
   out_4806322824000620331[50] = 0;
   out_4806322824000620331[51] = 0;
   out_4806322824000620331[52] = 0;
   out_4806322824000620331[53] = 0;
   out_4806322824000620331[54] = 0;
   out_4806322824000620331[55] = 0;
   out_4806322824000620331[56] = 0;
   out_4806322824000620331[57] = 1;
   out_4806322824000620331[58] = 0;
   out_4806322824000620331[59] = 0;
   out_4806322824000620331[60] = 0;
   out_4806322824000620331[61] = 0;
   out_4806322824000620331[62] = 0;
   out_4806322824000620331[63] = 0;
   out_4806322824000620331[64] = 0;
   out_4806322824000620331[65] = 0;
   out_4806322824000620331[66] = dt;
   out_4806322824000620331[67] = 0;
   out_4806322824000620331[68] = 0;
   out_4806322824000620331[69] = 0;
   out_4806322824000620331[70] = 0;
   out_4806322824000620331[71] = 0;
   out_4806322824000620331[72] = 0;
   out_4806322824000620331[73] = 0;
   out_4806322824000620331[74] = 0;
   out_4806322824000620331[75] = 0;
   out_4806322824000620331[76] = 1;
   out_4806322824000620331[77] = 0;
   out_4806322824000620331[78] = 0;
   out_4806322824000620331[79] = 0;
   out_4806322824000620331[80] = 0;
   out_4806322824000620331[81] = 0;
   out_4806322824000620331[82] = 0;
   out_4806322824000620331[83] = 0;
   out_4806322824000620331[84] = 0;
   out_4806322824000620331[85] = dt;
   out_4806322824000620331[86] = 0;
   out_4806322824000620331[87] = 0;
   out_4806322824000620331[88] = 0;
   out_4806322824000620331[89] = 0;
   out_4806322824000620331[90] = 0;
   out_4806322824000620331[91] = 0;
   out_4806322824000620331[92] = 0;
   out_4806322824000620331[93] = 0;
   out_4806322824000620331[94] = 0;
   out_4806322824000620331[95] = 1;
   out_4806322824000620331[96] = 0;
   out_4806322824000620331[97] = 0;
   out_4806322824000620331[98] = 0;
   out_4806322824000620331[99] = 0;
   out_4806322824000620331[100] = 0;
   out_4806322824000620331[101] = 0;
   out_4806322824000620331[102] = 0;
   out_4806322824000620331[103] = 0;
   out_4806322824000620331[104] = dt;
   out_4806322824000620331[105] = 0;
   out_4806322824000620331[106] = 0;
   out_4806322824000620331[107] = 0;
   out_4806322824000620331[108] = 0;
   out_4806322824000620331[109] = 0;
   out_4806322824000620331[110] = 0;
   out_4806322824000620331[111] = 0;
   out_4806322824000620331[112] = 0;
   out_4806322824000620331[113] = 0;
   out_4806322824000620331[114] = 1;
   out_4806322824000620331[115] = 0;
   out_4806322824000620331[116] = 0;
   out_4806322824000620331[117] = 0;
   out_4806322824000620331[118] = 0;
   out_4806322824000620331[119] = 0;
   out_4806322824000620331[120] = 0;
   out_4806322824000620331[121] = 0;
   out_4806322824000620331[122] = 0;
   out_4806322824000620331[123] = 0;
   out_4806322824000620331[124] = 0;
   out_4806322824000620331[125] = 0;
   out_4806322824000620331[126] = 0;
   out_4806322824000620331[127] = 0;
   out_4806322824000620331[128] = 0;
   out_4806322824000620331[129] = 0;
   out_4806322824000620331[130] = 0;
   out_4806322824000620331[131] = 0;
   out_4806322824000620331[132] = 0;
   out_4806322824000620331[133] = 1;
   out_4806322824000620331[134] = 0;
   out_4806322824000620331[135] = 0;
   out_4806322824000620331[136] = 0;
   out_4806322824000620331[137] = 0;
   out_4806322824000620331[138] = 0;
   out_4806322824000620331[139] = 0;
   out_4806322824000620331[140] = 0;
   out_4806322824000620331[141] = 0;
   out_4806322824000620331[142] = 0;
   out_4806322824000620331[143] = 0;
   out_4806322824000620331[144] = 0;
   out_4806322824000620331[145] = 0;
   out_4806322824000620331[146] = 0;
   out_4806322824000620331[147] = 0;
   out_4806322824000620331[148] = 0;
   out_4806322824000620331[149] = 0;
   out_4806322824000620331[150] = 0;
   out_4806322824000620331[151] = 0;
   out_4806322824000620331[152] = 1;
   out_4806322824000620331[153] = 0;
   out_4806322824000620331[154] = 0;
   out_4806322824000620331[155] = 0;
   out_4806322824000620331[156] = 0;
   out_4806322824000620331[157] = 0;
   out_4806322824000620331[158] = 0;
   out_4806322824000620331[159] = 0;
   out_4806322824000620331[160] = 0;
   out_4806322824000620331[161] = 0;
   out_4806322824000620331[162] = 0;
   out_4806322824000620331[163] = 0;
   out_4806322824000620331[164] = 0;
   out_4806322824000620331[165] = 0;
   out_4806322824000620331[166] = 0;
   out_4806322824000620331[167] = 0;
   out_4806322824000620331[168] = 0;
   out_4806322824000620331[169] = 0;
   out_4806322824000620331[170] = 0;
   out_4806322824000620331[171] = 1;
   out_4806322824000620331[172] = 0;
   out_4806322824000620331[173] = 0;
   out_4806322824000620331[174] = 0;
   out_4806322824000620331[175] = 0;
   out_4806322824000620331[176] = 0;
   out_4806322824000620331[177] = 0;
   out_4806322824000620331[178] = 0;
   out_4806322824000620331[179] = 0;
   out_4806322824000620331[180] = 0;
   out_4806322824000620331[181] = 0;
   out_4806322824000620331[182] = 0;
   out_4806322824000620331[183] = 0;
   out_4806322824000620331[184] = 0;
   out_4806322824000620331[185] = 0;
   out_4806322824000620331[186] = 0;
   out_4806322824000620331[187] = 0;
   out_4806322824000620331[188] = 0;
   out_4806322824000620331[189] = 0;
   out_4806322824000620331[190] = 1;
   out_4806322824000620331[191] = 0;
   out_4806322824000620331[192] = 0;
   out_4806322824000620331[193] = 0;
   out_4806322824000620331[194] = 0;
   out_4806322824000620331[195] = 0;
   out_4806322824000620331[196] = 0;
   out_4806322824000620331[197] = 0;
   out_4806322824000620331[198] = 0;
   out_4806322824000620331[199] = 0;
   out_4806322824000620331[200] = 0;
   out_4806322824000620331[201] = 0;
   out_4806322824000620331[202] = 0;
   out_4806322824000620331[203] = 0;
   out_4806322824000620331[204] = 0;
   out_4806322824000620331[205] = 0;
   out_4806322824000620331[206] = 0;
   out_4806322824000620331[207] = 0;
   out_4806322824000620331[208] = 0;
   out_4806322824000620331[209] = 1;
   out_4806322824000620331[210] = 0;
   out_4806322824000620331[211] = 0;
   out_4806322824000620331[212] = 0;
   out_4806322824000620331[213] = 0;
   out_4806322824000620331[214] = 0;
   out_4806322824000620331[215] = 0;
   out_4806322824000620331[216] = 0;
   out_4806322824000620331[217] = 0;
   out_4806322824000620331[218] = 0;
   out_4806322824000620331[219] = 0;
   out_4806322824000620331[220] = 0;
   out_4806322824000620331[221] = 0;
   out_4806322824000620331[222] = 0;
   out_4806322824000620331[223] = 0;
   out_4806322824000620331[224] = 0;
   out_4806322824000620331[225] = 0;
   out_4806322824000620331[226] = 0;
   out_4806322824000620331[227] = 0;
   out_4806322824000620331[228] = 1;
   out_4806322824000620331[229] = 0;
   out_4806322824000620331[230] = 0;
   out_4806322824000620331[231] = 0;
   out_4806322824000620331[232] = 0;
   out_4806322824000620331[233] = 0;
   out_4806322824000620331[234] = 0;
   out_4806322824000620331[235] = 0;
   out_4806322824000620331[236] = 0;
   out_4806322824000620331[237] = 0;
   out_4806322824000620331[238] = 0;
   out_4806322824000620331[239] = 0;
   out_4806322824000620331[240] = 0;
   out_4806322824000620331[241] = 0;
   out_4806322824000620331[242] = 0;
   out_4806322824000620331[243] = 0;
   out_4806322824000620331[244] = 0;
   out_4806322824000620331[245] = 0;
   out_4806322824000620331[246] = 0;
   out_4806322824000620331[247] = 1;
   out_4806322824000620331[248] = 0;
   out_4806322824000620331[249] = 0;
   out_4806322824000620331[250] = 0;
   out_4806322824000620331[251] = 0;
   out_4806322824000620331[252] = 0;
   out_4806322824000620331[253] = 0;
   out_4806322824000620331[254] = 0;
   out_4806322824000620331[255] = 0;
   out_4806322824000620331[256] = 0;
   out_4806322824000620331[257] = 0;
   out_4806322824000620331[258] = 0;
   out_4806322824000620331[259] = 0;
   out_4806322824000620331[260] = 0;
   out_4806322824000620331[261] = 0;
   out_4806322824000620331[262] = 0;
   out_4806322824000620331[263] = 0;
   out_4806322824000620331[264] = 0;
   out_4806322824000620331[265] = 0;
   out_4806322824000620331[266] = 1;
   out_4806322824000620331[267] = 0;
   out_4806322824000620331[268] = 0;
   out_4806322824000620331[269] = 0;
   out_4806322824000620331[270] = 0;
   out_4806322824000620331[271] = 0;
   out_4806322824000620331[272] = 0;
   out_4806322824000620331[273] = 0;
   out_4806322824000620331[274] = 0;
   out_4806322824000620331[275] = 0;
   out_4806322824000620331[276] = 0;
   out_4806322824000620331[277] = 0;
   out_4806322824000620331[278] = 0;
   out_4806322824000620331[279] = 0;
   out_4806322824000620331[280] = 0;
   out_4806322824000620331[281] = 0;
   out_4806322824000620331[282] = 0;
   out_4806322824000620331[283] = 0;
   out_4806322824000620331[284] = 0;
   out_4806322824000620331[285] = 1;
   out_4806322824000620331[286] = 0;
   out_4806322824000620331[287] = 0;
   out_4806322824000620331[288] = 0;
   out_4806322824000620331[289] = 0;
   out_4806322824000620331[290] = 0;
   out_4806322824000620331[291] = 0;
   out_4806322824000620331[292] = 0;
   out_4806322824000620331[293] = 0;
   out_4806322824000620331[294] = 0;
   out_4806322824000620331[295] = 0;
   out_4806322824000620331[296] = 0;
   out_4806322824000620331[297] = 0;
   out_4806322824000620331[298] = 0;
   out_4806322824000620331[299] = 0;
   out_4806322824000620331[300] = 0;
   out_4806322824000620331[301] = 0;
   out_4806322824000620331[302] = 0;
   out_4806322824000620331[303] = 0;
   out_4806322824000620331[304] = 1;
   out_4806322824000620331[305] = 0;
   out_4806322824000620331[306] = 0;
   out_4806322824000620331[307] = 0;
   out_4806322824000620331[308] = 0;
   out_4806322824000620331[309] = 0;
   out_4806322824000620331[310] = 0;
   out_4806322824000620331[311] = 0;
   out_4806322824000620331[312] = 0;
   out_4806322824000620331[313] = 0;
   out_4806322824000620331[314] = 0;
   out_4806322824000620331[315] = 0;
   out_4806322824000620331[316] = 0;
   out_4806322824000620331[317] = 0;
   out_4806322824000620331[318] = 0;
   out_4806322824000620331[319] = 0;
   out_4806322824000620331[320] = 0;
   out_4806322824000620331[321] = 0;
   out_4806322824000620331[322] = 0;
   out_4806322824000620331[323] = 1;
}
void h_4(double *state, double *unused, double *out_2146936515699344985) {
   out_2146936515699344985[0] = state[6] + state[9];
   out_2146936515699344985[1] = state[7] + state[10];
   out_2146936515699344985[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9176625892716694514) {
   out_9176625892716694514[0] = 0;
   out_9176625892716694514[1] = 0;
   out_9176625892716694514[2] = 0;
   out_9176625892716694514[3] = 0;
   out_9176625892716694514[4] = 0;
   out_9176625892716694514[5] = 0;
   out_9176625892716694514[6] = 1;
   out_9176625892716694514[7] = 0;
   out_9176625892716694514[8] = 0;
   out_9176625892716694514[9] = 1;
   out_9176625892716694514[10] = 0;
   out_9176625892716694514[11] = 0;
   out_9176625892716694514[12] = 0;
   out_9176625892716694514[13] = 0;
   out_9176625892716694514[14] = 0;
   out_9176625892716694514[15] = 0;
   out_9176625892716694514[16] = 0;
   out_9176625892716694514[17] = 0;
   out_9176625892716694514[18] = 0;
   out_9176625892716694514[19] = 0;
   out_9176625892716694514[20] = 0;
   out_9176625892716694514[21] = 0;
   out_9176625892716694514[22] = 0;
   out_9176625892716694514[23] = 0;
   out_9176625892716694514[24] = 0;
   out_9176625892716694514[25] = 1;
   out_9176625892716694514[26] = 0;
   out_9176625892716694514[27] = 0;
   out_9176625892716694514[28] = 1;
   out_9176625892716694514[29] = 0;
   out_9176625892716694514[30] = 0;
   out_9176625892716694514[31] = 0;
   out_9176625892716694514[32] = 0;
   out_9176625892716694514[33] = 0;
   out_9176625892716694514[34] = 0;
   out_9176625892716694514[35] = 0;
   out_9176625892716694514[36] = 0;
   out_9176625892716694514[37] = 0;
   out_9176625892716694514[38] = 0;
   out_9176625892716694514[39] = 0;
   out_9176625892716694514[40] = 0;
   out_9176625892716694514[41] = 0;
   out_9176625892716694514[42] = 0;
   out_9176625892716694514[43] = 0;
   out_9176625892716694514[44] = 1;
   out_9176625892716694514[45] = 0;
   out_9176625892716694514[46] = 0;
   out_9176625892716694514[47] = 1;
   out_9176625892716694514[48] = 0;
   out_9176625892716694514[49] = 0;
   out_9176625892716694514[50] = 0;
   out_9176625892716694514[51] = 0;
   out_9176625892716694514[52] = 0;
   out_9176625892716694514[53] = 0;
}
void h_10(double *state, double *unused, double *out_7324595289411116285) {
   out_7324595289411116285[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7324595289411116285[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7324595289411116285[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6720236421065597274) {
   out_6720236421065597274[0] = 0;
   out_6720236421065597274[1] = 9.8100000000000005*cos(state[1]);
   out_6720236421065597274[2] = 0;
   out_6720236421065597274[3] = 0;
   out_6720236421065597274[4] = -state[8];
   out_6720236421065597274[5] = state[7];
   out_6720236421065597274[6] = 0;
   out_6720236421065597274[7] = state[5];
   out_6720236421065597274[8] = -state[4];
   out_6720236421065597274[9] = 0;
   out_6720236421065597274[10] = 0;
   out_6720236421065597274[11] = 0;
   out_6720236421065597274[12] = 1;
   out_6720236421065597274[13] = 0;
   out_6720236421065597274[14] = 0;
   out_6720236421065597274[15] = 1;
   out_6720236421065597274[16] = 0;
   out_6720236421065597274[17] = 0;
   out_6720236421065597274[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6720236421065597274[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6720236421065597274[20] = 0;
   out_6720236421065597274[21] = state[8];
   out_6720236421065597274[22] = 0;
   out_6720236421065597274[23] = -state[6];
   out_6720236421065597274[24] = -state[5];
   out_6720236421065597274[25] = 0;
   out_6720236421065597274[26] = state[3];
   out_6720236421065597274[27] = 0;
   out_6720236421065597274[28] = 0;
   out_6720236421065597274[29] = 0;
   out_6720236421065597274[30] = 0;
   out_6720236421065597274[31] = 1;
   out_6720236421065597274[32] = 0;
   out_6720236421065597274[33] = 0;
   out_6720236421065597274[34] = 1;
   out_6720236421065597274[35] = 0;
   out_6720236421065597274[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6720236421065597274[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6720236421065597274[38] = 0;
   out_6720236421065597274[39] = -state[7];
   out_6720236421065597274[40] = state[6];
   out_6720236421065597274[41] = 0;
   out_6720236421065597274[42] = state[4];
   out_6720236421065597274[43] = -state[3];
   out_6720236421065597274[44] = 0;
   out_6720236421065597274[45] = 0;
   out_6720236421065597274[46] = 0;
   out_6720236421065597274[47] = 0;
   out_6720236421065597274[48] = 0;
   out_6720236421065597274[49] = 0;
   out_6720236421065597274[50] = 1;
   out_6720236421065597274[51] = 0;
   out_6720236421065597274[52] = 0;
   out_6720236421065597274[53] = 1;
}
void h_13(double *state, double *unused, double *out_3077593966437383014) {
   out_3077593966437383014[0] = state[3];
   out_3077593966437383014[1] = state[4];
   out_3077593966437383014[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6057844355660524301) {
   out_6057844355660524301[0] = 0;
   out_6057844355660524301[1] = 0;
   out_6057844355660524301[2] = 0;
   out_6057844355660524301[3] = 1;
   out_6057844355660524301[4] = 0;
   out_6057844355660524301[5] = 0;
   out_6057844355660524301[6] = 0;
   out_6057844355660524301[7] = 0;
   out_6057844355660524301[8] = 0;
   out_6057844355660524301[9] = 0;
   out_6057844355660524301[10] = 0;
   out_6057844355660524301[11] = 0;
   out_6057844355660524301[12] = 0;
   out_6057844355660524301[13] = 0;
   out_6057844355660524301[14] = 0;
   out_6057844355660524301[15] = 0;
   out_6057844355660524301[16] = 0;
   out_6057844355660524301[17] = 0;
   out_6057844355660524301[18] = 0;
   out_6057844355660524301[19] = 0;
   out_6057844355660524301[20] = 0;
   out_6057844355660524301[21] = 0;
   out_6057844355660524301[22] = 1;
   out_6057844355660524301[23] = 0;
   out_6057844355660524301[24] = 0;
   out_6057844355660524301[25] = 0;
   out_6057844355660524301[26] = 0;
   out_6057844355660524301[27] = 0;
   out_6057844355660524301[28] = 0;
   out_6057844355660524301[29] = 0;
   out_6057844355660524301[30] = 0;
   out_6057844355660524301[31] = 0;
   out_6057844355660524301[32] = 0;
   out_6057844355660524301[33] = 0;
   out_6057844355660524301[34] = 0;
   out_6057844355660524301[35] = 0;
   out_6057844355660524301[36] = 0;
   out_6057844355660524301[37] = 0;
   out_6057844355660524301[38] = 0;
   out_6057844355660524301[39] = 0;
   out_6057844355660524301[40] = 0;
   out_6057844355660524301[41] = 1;
   out_6057844355660524301[42] = 0;
   out_6057844355660524301[43] = 0;
   out_6057844355660524301[44] = 0;
   out_6057844355660524301[45] = 0;
   out_6057844355660524301[46] = 0;
   out_6057844355660524301[47] = 0;
   out_6057844355660524301[48] = 0;
   out_6057844355660524301[49] = 0;
   out_6057844355660524301[50] = 0;
   out_6057844355660524301[51] = 0;
   out_6057844355660524301[52] = 0;
   out_6057844355660524301[53] = 0;
}
void h_14(double *state, double *unused, double *out_5838993491781915029) {
   out_5838993491781915029[0] = state[6];
   out_5838993491781915029[1] = state[7];
   out_5838993491781915029[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5306877324653372573) {
   out_5306877324653372573[0] = 0;
   out_5306877324653372573[1] = 0;
   out_5306877324653372573[2] = 0;
   out_5306877324653372573[3] = 0;
   out_5306877324653372573[4] = 0;
   out_5306877324653372573[5] = 0;
   out_5306877324653372573[6] = 1;
   out_5306877324653372573[7] = 0;
   out_5306877324653372573[8] = 0;
   out_5306877324653372573[9] = 0;
   out_5306877324653372573[10] = 0;
   out_5306877324653372573[11] = 0;
   out_5306877324653372573[12] = 0;
   out_5306877324653372573[13] = 0;
   out_5306877324653372573[14] = 0;
   out_5306877324653372573[15] = 0;
   out_5306877324653372573[16] = 0;
   out_5306877324653372573[17] = 0;
   out_5306877324653372573[18] = 0;
   out_5306877324653372573[19] = 0;
   out_5306877324653372573[20] = 0;
   out_5306877324653372573[21] = 0;
   out_5306877324653372573[22] = 0;
   out_5306877324653372573[23] = 0;
   out_5306877324653372573[24] = 0;
   out_5306877324653372573[25] = 1;
   out_5306877324653372573[26] = 0;
   out_5306877324653372573[27] = 0;
   out_5306877324653372573[28] = 0;
   out_5306877324653372573[29] = 0;
   out_5306877324653372573[30] = 0;
   out_5306877324653372573[31] = 0;
   out_5306877324653372573[32] = 0;
   out_5306877324653372573[33] = 0;
   out_5306877324653372573[34] = 0;
   out_5306877324653372573[35] = 0;
   out_5306877324653372573[36] = 0;
   out_5306877324653372573[37] = 0;
   out_5306877324653372573[38] = 0;
   out_5306877324653372573[39] = 0;
   out_5306877324653372573[40] = 0;
   out_5306877324653372573[41] = 0;
   out_5306877324653372573[42] = 0;
   out_5306877324653372573[43] = 0;
   out_5306877324653372573[44] = 1;
   out_5306877324653372573[45] = 0;
   out_5306877324653372573[46] = 0;
   out_5306877324653372573[47] = 0;
   out_5306877324653372573[48] = 0;
   out_5306877324653372573[49] = 0;
   out_5306877324653372573[50] = 0;
   out_5306877324653372573[51] = 0;
   out_5306877324653372573[52] = 0;
   out_5306877324653372573[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4497386892446686963) {
  err_fun(nom_x, delta_x, out_4497386892446686963);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4020535164465364860) {
  inv_err_fun(nom_x, true_x, out_4020535164465364860);
}
void pose_H_mod_fun(double *state, double *out_163641472803010022) {
  H_mod_fun(state, out_163641472803010022);
}
void pose_f_fun(double *state, double dt, double *out_7113476067971581844) {
  f_fun(state,  dt, out_7113476067971581844);
}
void pose_F_fun(double *state, double dt, double *out_4806322824000620331) {
  F_fun(state,  dt, out_4806322824000620331);
}
void pose_h_4(double *state, double *unused, double *out_2146936515699344985) {
  h_4(state, unused, out_2146936515699344985);
}
void pose_H_4(double *state, double *unused, double *out_9176625892716694514) {
  H_4(state, unused, out_9176625892716694514);
}
void pose_h_10(double *state, double *unused, double *out_7324595289411116285) {
  h_10(state, unused, out_7324595289411116285);
}
void pose_H_10(double *state, double *unused, double *out_6720236421065597274) {
  H_10(state, unused, out_6720236421065597274);
}
void pose_h_13(double *state, double *unused, double *out_3077593966437383014) {
  h_13(state, unused, out_3077593966437383014);
}
void pose_H_13(double *state, double *unused, double *out_6057844355660524301) {
  H_13(state, unused, out_6057844355660524301);
}
void pose_h_14(double *state, double *unused, double *out_5838993491781915029) {
  h_14(state, unused, out_5838993491781915029);
}
void pose_H_14(double *state, double *unused, double *out_5306877324653372573) {
  H_14(state, unused, out_5306877324653372573);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
