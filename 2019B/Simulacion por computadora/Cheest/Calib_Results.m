% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1237.596607846813200 ; 1236.767091029737200 ];

%-- Principal point:
cc = [ 614.109219937676580 ; 802.621344310796530 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.134002108659501 ; -0.358186899932579 ; 0.000199776463677 ; 0.000710335180500 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 97.732613390016652 ; 94.978259326105430 ];

%-- Principal point uncertainty:
cc_error = [ 27.493160613945054 ; 59.657890464041166 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.107025875061178 ; 0.762271512681118 ; 0.011305496859474 ; 0.010154325322898 ; 0.000000000000000 ];

%-- Image size:
nx = 1200;
ny = 1600;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 6;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.192670e+00 ; 2.191820e+00 ; -3.412621e-02 ];
Tc_1  = [ -1.990890e+01 ; -2.367378e+01 ; 7.947863e+01 ];
omc_error_1 = [ 1.576300e-02 ; 1.788611e-02 ; 3.546390e-02 ];
Tc_error_1  = [ 1.795845e+00 ; 3.805588e+00 ; 6.369512e+00 ];

%-- Image #2:
omc_2 = [ 1.924058e+00 ; 1.939558e+00 ; -4.836989e-01 ];
Tc_2  = [ -2.209839e+01 ; -9.975814e+00 ; 1.340204e+02 ];
omc_error_2 = [ 2.684448e-02 ; 2.871486e-02 ; 4.725861e-02 ];
Tc_error_2  = [ 2.968807e+00 ; 6.443060e+00 ; 1.061668e+01 ];

%-- Image #3:
omc_3 = [ 2.579045e+00 ; 2.579710e-01 ; -6.495903e-03 ];
Tc_3  = [ -2.508933e+01 ; 1.061421e+01 ; 1.004603e+02 ];
omc_error_3 = [ 4.428136e-02 ; 9.031804e-03 ; 3.029573e-02 ];
Tc_error_3  = [ 2.237502e+00 ; 4.887378e+00 ; 8.232208e+00 ];

%-- Image #4:
omc_4 = [ 1.622269e+00 ; -2.404854e+00 ; 2.549421e-01 ];
Tc_4  = [ 1.902165e+01 ; 2.727833e+00 ; 1.073291e+02 ];
omc_error_4 = [ 2.021052e-02 ; 2.837532e-02 ; 4.415078e-02 ];
Tc_error_4  = [ 2.389507e+00 ; 5.178967e+00 ; 8.537454e+00 ];

%-- Image #5:
omc_5 = [ -1.989078e+00 ; -2.322062e+00 ; 5.800542e-01 ];
Tc_5  = [ -2.887521e+01 ; -2.526987e+01 ; 1.400512e+02 ];
omc_error_5 = [ 2.329344e-02 ; 1.573273e-02 ; 6.284772e-02 ];
Tc_error_5  = [ 3.138970e+00 ; 6.701954e+00 ; 1.114361e+01 ];

%-- Image #6:
omc_6 = [ 2.686646e+00 ; 1.127329e-01 ; 7.180668e-02 ];
Tc_6  = [ -3.131465e+01 ; 1.487553e+01 ; 1.203252e+02 ];
omc_error_6 = [ 4.373161e-02 ; 7.788424e-03 ; 3.233248e-02 ];
Tc_error_6  = [ 2.683560e+00 ; 5.863959e+00 ; 9.741300e+00 ];

