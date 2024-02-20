syms k t a n
disp('Transformada de la place')
pause(3)
clc
disp('a) 1 ')
disp('Resp --------------')
respuesta=laplace(t);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('b) t^n ')
disp('Resp --------------')
respuesta=laplace(t^n);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('c) e^at ')
disp('Resp --------------')
respuesta=laplace(exp(a*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('d) sen kt')
disp('Resp --------------')
respuesta=laplace(sin(k*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('e) cos kt')
disp('Resp --------------')
respuesta=laplace((k*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc


disp('f) senh kt')
disp('Resp --------------')
respuesta=laplace(sinh(k*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('g) cosh kt')
disp('Resp --------------')
respuesta=laplace(cosh(k*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('1) 4t - 10')
disp('Resp --------------')
respuesta=laplace(4*t - 10);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('2) t^2 + 6t -3')
disp('Resp --------------')
respuesta=laplace(t^2 + 6*t -3);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('3) (t + 1)^3')
disp('Resp --------------')
respuesta=laplace((t + 1)^3);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause() 
clc

disp('4) 1 + e^4t')
disp('Resp --------------')
respuesta=laplace(1 + exp(4*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('5) (1 + e^2t)^2')
disp('Resp --------------')
respuesta=laplace((1 + exp(2*t))^2);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('6) 4t^2 - 5 sen 3t')
disp('Resp --------------')
respuesta=laplace(4*t^2 - 5*sin(3*t));
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('7) 7t + 3')
disp('Resp --------------')
respuesta=laplace(7*t + 3);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('8) -4t^2 + 16t + 9')
disp('Resp --------------')
respuesta=laplace(-4*t^2 + 16*t + 9);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('9) (2t-1)^3 ')
disp('Resp --------------')
respuesta=laplace((2*t - 1)^3 );
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc

disp('10)t^2-e^(-9t)+5')
disp('Resp --------------')
respuesta=laplace(t^2 - exp(-9*t) + 5);
res=simplify(respuesta);
pretty(res)
disp('Oprime tecla para continuar')
pause()
clc