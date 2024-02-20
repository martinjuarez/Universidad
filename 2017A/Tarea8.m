syms x
disp('Fracciones parciales')
pause(3)
clc
disp('1) 7x-14/(x-4)(x+3)')
f_x = ((7*x)/(x-4))+(-14/(x+3));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('2) 9x+21/(x+5)(x-3)')
f_x = ((9*x)/(x+5))+(21/(x-3));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('3) 17x-1/(2x-3)(3x-1)')
f_x = ((17*x)/(2*x-3))+(-1/(3*x-1));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('4) x-11/(3x+2)(2x-1)')
f_x = (x/(3*x+2))+(-11/(2*x-1));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('5) 3x^2+7x+1/x(x+1)^2')
f_x = ((3*x^2)/x)+(7*x/(x+1))+(1/(x+1)^2);
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
disp('6) x^2-6x+11/(x+1)(x-2)^2')
f_x = (x^2/(x+1))+(-6*x/(x-2))+(11/(x-2)^2);
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
disp('7) 3x^2+x/(x-2)(x^2+3)')
f_x = (3*x^2/(x-2))+(x*x+1/((x^2)+3));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('8) 5x^2-9x+19/(x-4)(x^2+5)')
f_x = (5*x^2/(x-4))+(-9*x+19/(x^2+5));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
disp('9) 2x^2+4x-1/(x^2-x+3)^2')
f_x = (((2*x^2)*x)+4*x/(x^2+x+1))+((-1*x)+1/(x^2+x+1)^2);
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
disp('10) 3x^3-3x^2+10x-4)/(x^2-x+3)^2')
f_x = (3*x^3-3*x^2+10*x-4)/(x^2-x+3)^2;
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('Ejemplo 1) 5x+7/x^2+2x-3')
f_x = (5*x+7)/(x^2+2*x-3);
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)
clc
disp('Ejemplo 2) 6x^2-14x-27/(x+2)+(x-3)^2')
f_x = (6*x^2)/(x+2)+(-14/(x-3)^2)+(-27/(x-3));
pretty(f_x)
disp('respuesta')
disp('-----------------------')
pause(3)
pretty(partfrac(f_x))
pause(3)

