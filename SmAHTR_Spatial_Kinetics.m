
%%SmAHTR Spatial Kinetics Model Initialization Script 


%% PKE Parameters

B1=.00021; B2=.00142; B3=.00127; B4=.00257; B5=.00075; B6=.00027;
% Beta = B1 + B2 + B3 + B4 + B5 + B6;
Beta = B1 + B2;
L1=.0124; L2=.0305; L3=.111; L4=.301; L5=1.14; L6=3.01;
lambda=.00002;

A_pke = [(0-Beta)/lambda, L1/lambda, L2/lambda;...
    B1, -L1, 0;...
    B2, 0, -L2];

% [V,D] = eig(A_pke);
% 
% A_pke*V

% A = [(0-Beta)/lambda L1/lambda L2/lambda L3/lambda L4/lambda L5/lambda L6/lambda;...
%     B1 -L1 0 0 0 0 0;...
%     B2 0 -L2 0 0 0 0;...
%     B3 0 0 -L3 0 0 0;...
%     B4 0 0 0 -L4 0 0;...
%     B5 0 0 0 0 -L5 0;...
%     B6 0 0 0 0 0 -L6];


%% Coupling Coefficient Matrix

% k12 = 0.001;
% k13 = k12^2;
% k14 = 0.0005;
% k15 = sqrt(k12*k14);
% k16 = sqrt(k13*k14);
% k17 = k14^2;
% k18 = sqrt(k12*k17);
% k19 = sqrt(k13*k17);
% k110 = k14^3;
% k111 = sqrt(k110*k12);
% k112 = sqrt(k110*k13);

k12 = 0.01;
k13 = 0.01;
k14 = 0.01;
k15 = 0.01;
k16 = 0.01;
k17 = 0.01;
k18 = 0.01;
k19 = 0.01;
k110 = 0.01;
k111 = 0.01;
k112 = 0.01;

K=zeros(12,12);

ki=[0 k12 k13 k14 k15 k16 k17 k18 k19 k110 k111 k112];

K(1,:)=ki;
K(2,:)=[0 0 ki(2) ki(5) ki(4) ki(5) ki(8) ki(7) ki(8) ki(11) ki(10) ki(11)];
K(3,:)=[0 0 0 ki(6) ki(5) ki(4) ki(9) ki(8) ki(7) ki(12) ki(11) ki(10)];
K(4,:)=[0 0 0 0 ki(2) ki(3) ki(4) ki(5) ki(6) ki(7) ki(8) ki(9)];
K(5,:)=[0 0 0 0 0 ki(2) ki(5) ki(4) ki(5) ki(8) ki(7) ki(8)];
K(6,:)=[0 0 0 0 0 0 ki(6) ki(5) ki(4) ki(9) ki(8) ki(7)];
K(7,:)=[0 0 0 0 0 0 0 ki(2) ki(3) ki(4) ki(5) ki(6)];
K(8,:)=[0 0 0 0 0 0 0 0 ki(2) ki(5) ki(4) ki(5)];
K(9,:)=[0 0 0 0 0 0 0 0 0 ki(6) ki(5) ki(4)];
K(10,:)=[0 0 0 0 0 0 0 0 0 0 ki(2) ki(3)];
K(11,:)=[0 0 0 0 0 0 0 0 0 0 0 ki(2)];

K=K+K';

Lcoupling=K(:)';

%% Temperature reactivity feedback

pcm = 1e-5;
alpha = [ -2.61*pcm -0.53*pcm ];

%% Fuel coolant heat exchange

uh=(4700+6380)/2; %Effective heat transfer coefficient
Ar=60.92/3; %Effective heat transfer area
mf=1810/3; %mass of fuel
cpf=0.12*1000; %specific heat of fuel
mc=4834/3; %mass of coolant
cpc=2414; %specific heat of coolant

m_dot=1050;  %initial mass flowrate of primary fluid

n=1/3; %initial power
T_c=650; %initial primary fluid temperature

u0=[n;T_c]; %initial input vector

Kp=125000000/3;

Atemp=[-(uh*Ar)/(mf*cpf), (uh*Ar)/(mf*cpf); (uh*Ar)/(mc*cpc), -(uh*Ar)/(mc*cpc)-(2*m_dot)/mc]; %initial A matrix for fuel-coolant state space system
btemp=[Kp/(mf*cpf), 0; 0 2*m_dot/mc]; %initial input vector

Ctemp=[1 0; 0 1; 0 2];
Dtemp=[0 0;0 0; 0 -1];

% systemFC=ss(Atemp,btemp,Ctemp,Dtemp);
% figure(10)
% step(systemFC)

xfc0=-Atemp\btemp*u0

% FCIC = [1100;800]

%% Dark rod curve fitting

%IAEA documentation uses 21 data points, including 0 and 100% withdrawn

x=zeros(21,1);

for i=2:length(x)
    x(i)=x(i-1)+5/100;
end

Lower = [0.7 0.9 0.95 0.98 0.99 0.93 0.62 0.18 0.05 0.02 0 0 0 0 0 0 0 0 0 0 0]';

Middle = [0.21 0.37 0.57 0.75 0.89 0.94 0.97 0.99 0.97 0.94 0.88 0.69 0.59 0.39 0.2 0.17 0.15 0.1 0.07 0.05 0]';

Upper = [0 0.01 0.02 0.04 0.05 0.07 0.12 0.2 0.5 0.85 0.95 0.97 0.99 0.96 0.94 0.79 0.41 0.19 0.1 0.05 0]';

RodData=[x Lower Middle Upper];

% figure(1)
% plot(x,Lower,'x',x,Middle,'*',x,Upper,'o')
% legend('Lower','Middle','Upper')

ppDarkLower = spline(x,Lower);
ppDarkMiddle = spline(x,Middle);
ppDarkUpper = spline(x,Upper);

DarkLowerCoeffs = ppDarkLower.coefs;
DarkMiddleCoeffs = ppDarkMiddle.coefs;
DarkUpperCoeffs = ppDarkUpper.coefs;

DarkLowerBreaks = ppDarkLower.breaks;
DarkMiddleBreaks = ppDarkMiddle.breaks;
DarkUpperBreaks = ppDarkUpper.breaks;

%Set a common variable name for the breaks since they are all the same
%as a result from how IAEA documentation gives us the data
breaks = DarkLowerBreaks;

%% Dark rod worth

%We need to come up with a reasonable rod worth for a fully-inserted
%control rod.  I think that -$3.00 is reasonable.  Therefore, we define:

DarkRodWorthInserted = -3*Beta;

%% Gray rod curve fitting

xg=[0 25 35 40 48 68 75 100]';
xg = xg/100;

UpperG = [1 1.05 0.976 0.95 0.8 0.775 0.6 0]';

MiddleG = [1 1.05 0.825 0.675 0.42 0.1 0.01 0]';

LowerG = [1 0.8 0.625 0.5 0.325 0.175 0.0875 0]';

GrayRodData = [xg UpperG MiddleG LowerG];

[ppGrayLower,gof1] = fit(xg,LowerG,'linear');
[ppGrayMiddle,gof2] = fit(xg,MiddleG,'linear');
[ppGrayUpper,gof3] = fit(xg,UpperG,'linear');

ppGlower = coeffvalues(ppGrayLower);
ppGmiddle = coeffvalues(ppGrayMiddle);
ppGupper = coeffvalues(ppGrayUpper);

GrayLowerCoeffs = ppGlower.coefs;
GrayMiddleCoeffs = ppGmiddle.coefs;
GrayUpperCoeffs = ppGupper.coefs;

GrayLowerBreaks = ppGlower.breaks;
GrayMiddleBreaks = ppGmiddle.breaks;
GrayUpperBreaks = ppGupper.breaks;

breaksGray = GrayLowerBreaks;

%% Gray Rod Worth
%We need to come up with a reasonable rod worth for a fully-inserted
%control rod.  I think that -$5.00 is reasonable.  Therefore, we define:

GrayRodWorthInserted = -5*Beta;

%% Reactor coolant pump time constant

rcpt=0.1; %Secondary-side pump time constant
rcp_activatetime=20;

%% Brayton Cycle Initialization Script

P_ratio=14; %Cycle pressure ratio
CompressorInletPressure=15; %psia
CompressorInletPressureSI=CompressorInletPressure*6894 %Pa
eta_C=0.83;
eta_T=0.87;
data=janload('nasa.fit');
BraytonTempTurb=800; %Kelvin
gamma=spratio(data,'CO2',1,BraytonTempTurb);
r=(P_ratio)^((gamma-1)/gamma);

Tc_i=10;
Tt_i=560;

Tc_o=(Tc_i+273)*((r-1)/eta_C+1)-273 %Compressor outlet temperature
Tt_o=(Tt_i+273)*(1-eta_T*(1-(1/r)))-273; %Turbine outlet temperature

TurbineTempAve=(Tt_i+Tt_o)/2;
CompTempAve=(Tc_i+Tc_o)/2;

cpCO2Turbine=spheat(data,'CO2',1,TurbineTempAve)%J/kg-K
cpCO2Compressor=spheat(data,'CO2',1,CompTempAve) %J/kg-K
rhoCO2=density(data,'CO2',1,Tc_o,P_ratio*CompressorInletPressureSI) %kg/m3; this will be used for input to the mass of CO2 in the salt vault HX process
mdotBraytonInitial=300; %kg/s

Pc=mdotBraytonInitial*cpCO2Compressor*(Tc_o-Tc_i);
Pt=mdotBraytonInitial*cpCO2Turbine*(Tt_i-Tt_o);

%Steady-state Power (MW)
Pm=(Pt-Pc)*10^-6
cpCO2_23=spheat(data,'CO2',1,(Tt_i+Tc_o)/2);
Qin=(mdotBraytonInitial*cpCO2_23*(Tt_i-Tc_o))*10^-6;
eta_Cycle=Pm/Qin

%Turbine-compressor time constant
tau_t=30;

%Note that I have not calculated initial conditions yet.

%% Cross flow heat exchanger initialization script

%Specific heat capacities
cpp=2414;   %Primary fluid
cps=1901;   %Secondary fluid
cpw=578;    %Wall (Hastelloy-N)

%Initial temperatures
Tw_i=650;
Tp_i=700;
Ts_i=600;

%Effective area
A=292.2;
V_tube=0.4675;
V_secondary=1.5127;
V_primary=1.1508;

rho_tube= 8860;
rho_secondary= 2020;
rho_primary= 1940;

h_primary=3400*7;
h_secondary=3500*7;

%Primary coolant constant parameter definitions
Kh1=1/(rho_primary*V_primary);
Kh2=(h_primary*A)/(cpp*rho_primary*V_primary);

%Wall constant parameter definitions
Kw1=h_primary;
Kw2=h_secondary;
Kw3=A/(rho_tube*cpw*V_tube);

%Secondary coolant constant parameter definitions
Kc1=1/(rho_secondary*V_secondary);
Kc2=(h_secondary*A)/(cps*rho_secondary*V_secondary);


%% Expanded Salt Vault Model

mdotR1=270*3;
mdotR2=270*3;
mdotR3=270*3;
mdotR4=270*3;
mdotB1=300;
mdotB2=300;
mdotB3=300;
mdotCT=10;

u0=[650;650;650;650;20;20;450;450;450];

hr1=3400*7;
hr2=hr1;
hr3=hr1;
hr4=hr1;
hb1=1000*3;
hb2=hb1;
hb3=hb1;
hct=3000;
hamb=1;

mr1=3055;
mr2=mr1;
mr3=mr1;
mr4=mr1;
ms=60000;
mb1=40*1.5127;
mb2=mb1;
mb3=mb1;
mct=2000;

cr1=1901;
cr2=cr1;
cr3=cr1;
cr4=cr1;
cs=1901;
cb1=965;
cb2=cb1;
cb3=cb1;
cct=1000;

Ar1=292;
Ar2=Ar1;
Ar3=Ar1;
Ar4=Ar1;
Ab1=Ar1;
Ab2=Ar1;
Ab3=Ar1;
Act=Ar1;
Asurface=2000*pi();

SALT=(1/(ms*cs))*(-hr1*Ar1-hr2*Ar2-hr3*Ar3-hr4*Ar4-hamb*Asurface-hb1*Ab1-hb2*Ab2-hb3*Ab3-hct*Act);

Asv=[-2*mdotR1/mr1-hr1*Ar1/(mr1*cr1),0,0,0,hr1*Ar1/(mr1*cr1),0,0,0,0;...
    0,-2*mdotR2/mr2-hr2*Ar2/(mr2*cr2),0,0,hr2*Ar2/(mr2*cr2),0,0,0,0;...
    0,0,-2*mdotR3/mr3-hr3*Ar3/(mr3*cr3),0,hr3*Ar3/(mr3*cr3),0,0,0,0;...
    0,0,0,-2*mdotR4/mr4-hr4*Ar4/(mr4*cr4),hr4*Ar4/(mr4*cr4),0,0,0,0;...
    hr1*Ar1/(ms*cs),hr2*Ar2/(ms*cs),hr3*Ar3/(ms*cs),hr4*Ar4/(ms*cs),SALT,hb1*Ab1/(ms*cs), hb2*Ab2/(ms*cs),hb3*Ab3/(ms*cs),hct*Act/(ms*cs);...
    0,0,0,0,hb1*Ab1/(mb1*cb1),-2*mdotB1/mb1-hb1*Ab1/(mb1*cb1),0,0,0;...
    0,0,0,0,hb2*Ab2/(mb2*cb2),0,-2*mdotB2/mb2-hb2*Ab2/(mb2*cb2),0,0;...
    0,0,0,0,hb3*Ab3/(mb3*cb3),0,0,-2*mdotB3/mb3-hb3*Ab3/(mb3*cb3),0;...
    0,0,0,0,hct*Act/(mct*cct),0,0,0,-2*mdotCT/mct-hct*Act/(mct*cct)];

Bsv=[2*mdotR1/mr1,0,0,0,0,0,0,0,0;...
    0,2*mdotR2/mr2,0,0,0,0,0,0,0;...
    0,0,2*mdotR3/mr3,0,0,0,0,0,0;...
    0,0,0,2*mdotR4/mr4,0,0,0,0,0;...
    0,0,0,0,hamb*Asurface/(ms*cs),0,0,0,0;...
    0,0,0,0,0,0,2*mdotB1/mb1,0,0;...
    0,0,0,0,0,0,0,2*mdotB2/mb2,0;...
    0,0,0,0,0,0,0,0,2*mdotB3/mb3;...
    0,0,0,0,0,2*mdotCT/mct,0,0,0];

C=[2,0,0,0,0,0,0,0,0;...
    0,2,0,0,0,0,0,0,0;...
    0,0,2,0,0,0,0,0,0;...
    0,0,0,2,0,0,0,0,0;...
    0,0,0,0,1,0,0,0,0;...
    0,0,0,0,0,2,0,0,0;...
    0,0,0,0,0,0,2,0,0;...
    0,0,0,0,0,0,0,2,0;...
    0,0,0,0,0,0,0,0,2];

D=[-1,0,0,0,0,0,0,0,0;...
    0,-1,0,0,0,0,0,0,0;...
    0,0,-1,0,0,0,0,0,0;...
    0,0,0,-1,0,0,0,0,0;...
    0,0,0,0,0,0,0,0,0;...
    0,0,0,0,0,0,-1,0,0;...
    0,0,0,0,0,0,0,-1,0;...
    0,0,0,0,0,0,0,0,-1;...
    0,0,0,0,0,-1,0,0,0];

eig(Asv)
x0SaltVaultExpanded=-Asv\Bsv*u0

O=obsv(Asv,C);
rank(O)


%% Salt Vault 3 State Prototype - Passive RC component for Salt

Tamb=20;
u0=[690;Tamb;450];
mdotC=300;
mdotH=270*3;


m1=V_secondary*rho_secondary;
c1=cps;
m2=708; %Supercritical CO2 mass (TBD)
c2=1000;   %Supercritical CO2 specific heat (TBD)
h1=3400*7;  %Primary side of salt vault (secondary salt) effective heat transfer coefficient
h2=1000*3; %Supercritical CO2-side effective heat transfer coefficient (TBD)
ms=600000; %Mass of salt
cs=cps;    %Specific heat of salt
Area=292; %Heat transfer area within salt vault common to both HX sides

AtempSALT=[-mdotC/m1-h1*Area/(m1*c1), h1*Area/(m1*c1), 0;...
    h1*Area/(ms*cs), -h1*Area/(ms*cs)-h2*Area/(ms*cs)-(1*20000*pi())/(ms*cs), h2*Area/(ms*cs);...
    0,h2*Area/(m2*c2), -mdotH/m2-h2*Area/(m2*c2)];

btempSALT=[mdotC/m1 0 0;0 (1*20000*pi())/(ms*cs) 0; 0 0 mdotH/m2];

CtempSALT=[1 0 0;0 1 0;0 0 1];

DtempSALT=zeros(3,3);

SaltVaultEigs=eig(AtempSALT)

SaltVaultICs=-AtempSALT\btempSALT*u0

% xdot=A*x+b*u;
% y=C*x+D*u;
