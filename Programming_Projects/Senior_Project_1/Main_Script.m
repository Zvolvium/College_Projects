%%  Main_Script.m 
% Description: Sample script to extract optical properties from raw images
% and using all functions (demodulaiton, calibration, optical properties
% extraction)
% See "Spatial Frequency Domain Imaging in 2019: Principles, Applications
% and Perspectives" - https://doi.org/10.1117/1.JBO.24.7.071613
%==========================================================================
%DO NOT FORGET TO SPECIFY THE DESIRED SPATIAL FREQUENCY AS WELL AS LINK TO
%THE APPROPRIATE CALIBRATION AND SAMPLE IMAGES
%==========================================================================
% Input: 
% Raw images
%--------------------------------------------------------------------------
% Output:
% 1) Mua : Absorption
% 2) Musp : Reduced scattering
%==========================================================================
% Last update: v1.0 - 2020/05/14
% @author    : Enagnon Aguénounon - faguenounon@unistra.fr
%==========================================================================
addpath('.\Demodulation');
addpath('.\OP extraction');

%% Demodulation 7 phases DATA
% Calibration phantom
load('PH7_calibration_0_0.mat')
[MDC_Calibration, MAC, Imagpart, Realpart] = compute_7phases(mesdata);
load('PH7_calibration_0_2.mat')
[MDC, MAC_Calibration, Imagpart_Calibration, Realpart_Calibration] = compute_7phases(mesdata);
Phase_Calibration = atan2(Imagpart_Calibration,Realpart_Calibration);

% Hand sample
load('PH7_hand_0_0.mat')
[MDC_Hand, MAC, Imagpart, Realpart] = compute_7phases(mesdata);
load('PH7_hand_0_2.mat')
[MDC, MAC_Hand, Imagpart_Hand, Realpart_Hand] = compute_7phases(mesdata);
Phase_Hand = atan2(Imagpart_Hand,Realpart_Hand);

%% Demodulation 3 phases DATA
% Calibration phantom
load('PH3_calibration_0_0.mat')
[MDC_Calibration, MAC, Imagpart, Realpart] = compute_3phases(mesdata);
load(['PH3_calibration_0_2.mat'])
[MDC, MAC_Calibration, Imagpart_Calibration, Realpart_Calibration] = compute_3phases(mesdata);
Phase_Calibration = atan2(Imagpart_Calibration,Realpart_Calibration);

% Hand sample
load('PH3_hand_0_0.mat')
[MDC_Hand, MAC, Imagpart, Realpart] = compute_3phases(mesdata);
load('PH3_hand_0_2.mat')
[MDC, MAC_Hand, Imagpart_Hand, Realpart_Hand] = compute_3phases(mesdata);
Phase_Hand = atan2(Imagpart_Hand,Realpart_Hand);

%% Demodulation 1 phase DATA % Filtering
% Calibration phantom
load('PH3_calibration_0_2.mat');
data_1phase = mesdata(:,:,1,1);
[mask_DC, mask_AC, mask_PH] = design_mask(data_1phase);
[MDC_Calibration, MAC_Calibration, Imagpart, Realpart] = compute_1phase(data_1phase,mask_DC,mask_AC,mask_PH);
Phase_Calibration = atan2(Imagpart,Realpart);

% Hand sample
load('PH3_hand_0_2.mat');
data_1phase = mesdata(:,:,1,1);
[MDC_Hand, MAC_Hand, Imagpart, Realpart] = compute_1phase(data_1phase,mask_DC,mask_AC,mask_PH);
Phase_Hand = atan2(Imagpart,Realpart);

%% OP extraction
% Load calibration phantom diffuse reflectance
load('calibs_rdc_rac.mat');
fx = 0.2; % spatial frequency
calibs_rdc = calibs_rdc_rac(1);
calibs_rac = calibs_rdc_rac((fx*10) + 1);
% Load LUTs
load('LUT_mua_fx_02.mat');
load('LUT_musp_fx_02.mat'); 
% Diffuse reflectance
[sample_Rdc, sample_Rac] = compute_Rd(MDC_Calibration,MAC_Calibration,MDC_Hand,MAC_Hand,calibs_rdc,calibs_rac);
% Optical properties
[Mua, Musp] = OP_extraction(sample_Rdc,sample_Rac,LUT_mua_fx_02,LUT_musp_fx_02);
