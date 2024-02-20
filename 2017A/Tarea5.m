syms x
disp('Ecuaciones no homogeneas')
pause(3)
clc
disp('1) y´´+3y´+2y=6, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y+3*Dy+2*y=6,y(0)=2,Dy(0)=3');
pause(3)
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('2) 4y´´+9y=15, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('4*D2y+9*y=15, y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('3) y´´-10y´+25y=30x+3, y(0)=2,y´(0)=3')
pause (3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y-10*Dy+25*y=30*x+3, y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('4) y´´+y´-6y=2x, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y+Dy-6*y=2*x, y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('5) 1/4y´´+y´+y=x^2-2x, y(0)=2,y´(0)=3')
pause (3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('1/4*D2y+Dy+y=x^2-2*x, y(0)=2,Dy(0)=3');
pretty(y)
pause (3)
ezplot(y)
pause(3)
clc
disp('6) y´´-8y´+20y=100x^2-26xe^x, y(0)=2,y´(0)=3')
pause (3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y-8*Dy+20*y=100*x^2-26*x*exp(x), y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('7) y´´+3y=-48x^2+exp(3*x), y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y+3*y=-48*x^2+exp(3*x), y(0)=2,Dy(0)=3');
pretty(y)
pause (3)
ezplot(y)
pause(3)
clc
disp('8) 4y´´-4y´-3y=cos2x, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('4*D2y-4*Dy-3*y=cos(2*x), y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('9) y´´-y´=-3, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y-Dy=-3, y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('10) y´´+2y´=2x+5-e^-2x, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y+2*Dy=2*x+5-exp(-2*x), y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc
disp('11) y´´-y´+1/4y=3+e^x/2, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y-Dy+1/4*y=+3-exp(x/2), y(0)=2,Dy(0)=3');
pretty(y)
ezplot(y)
pause(3)
clc
disp('12) y´´-16y=2exp^4x, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y-16*y=2*exp(4*x), y(0)=2,Dy(0)=3');
pretty(y)
pause (3)
ezplot(y)
pause(3)
clc
disp('13) y´´+4y=3 sen2x, y(0)=2,y´(0)=3')
pause(3)
disp('Respuesta:')
disp('--------------------------------')
y=dsolve('D2y+4*y=3*sin(2*x), y(0)=2,Dy(0)=3');
pretty(y)
pause(3)
ezplot(y)
pause(3)
clc