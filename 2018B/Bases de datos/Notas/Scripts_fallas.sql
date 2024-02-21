//Creacion de la base de datos Fallas
create database fallas;
---------------------------------------
//Creacion de la tabla compañia
create table compania(Rfc_compania char(13)primary key,nombre varchar(50) not null, direccion varchar(50) not null);
-----------------------------------------------------------------------------
//Creacion de la tabla automovil
create table automovil(Num_serie varchar(20)primary key,modelo char(4) not null,kilometraje varchar(20) not null, marca varchar(20) not null,rfc_compania_a char(13) not null,foreign key(rfc_compania_a) references compania(rfc_compania));
--------------------------------------------------------------------------
//Creacion de la tabla propietario
create table propietario(Rfc_propietario char(13)primary key,nombre varchar(20) not null, telefono char(10) not null,num_serie_p varchar(20) not null, foreign key(num_serie_p) references automovil(num_serie));
-----------------------------------------------------------------------------
//Creacion de la tabla taller
create table taller(Rfc_taller char(13)primary key, nombre varchar(50) not null, direccion varchar(50) not null);
-----------------------------------------------------------------------------
//Creacion de la tabla reporte quejas
create table reporte_quejas(num_reporte_q char(9)primary key,def_detectado varchar(50) not null,kilometraje varchar(20) not null ,fecha date default now(),Rfc_propietario_q char(13),foreign key(rfc_propietario_q) references propietario (rfc_propietario), num_serie_q varchar(20),foreign key(num_serie_q) references automovil(num_serie));
------------------------------------------------------------------------------
//creacion de la tabla reporte taller
create table reporte_taller(num_reportet char(13) primary key,estado_gen varchar(50) not null, falla_marca char(1) not null, falla_modelo char(1) not null, fecha date default now(),rfc_taller_r char(13),foreign key(rfc_taller_r) references taller(rfc_taller));
----------------------------------------------------------------------------
//Creacion de la tabla inspeccion
create table inspeccion(estado_siscom varchar(300) not null,sistema_eficiencia_concat char(1) not null, interruptores char(1) not null, sistema_senoxg char(1) not null, sensores char(1) not null, actuadores char(1), sistema_det_igncil char(1) not null, rfc_taller_i char(13) not null,foreign key(rfc_taller_i)references taller(rfc_taller));
---------------------------------------------------------------------------------------
//Insercion compañia
insert into compania(rfc_compania,nombre,direccion)values('CUPU800825569','FORD','fictisio #110 narnia');
insert into compania(rfc_compania,nombre,direccion)values('AFCD931513510','CHEVROLET','sueños #999 cielo');
insert into compania(rfc_compania,nombre,direccion)values('ZXCV674301920','NISSAN','suerte #158 paraiso');
insert into compania(rfc_compania,nombre,direccion)values('QWER106277590','TOYOTA','realidad #470 tierra');
insert into compania(rfc_compania,nombre,direccion)values('HLKJ651038296','BMW','infernus #666 dolores');
----------------------------------------------------------------------
//insercion automovil
insert into automovil(num_serie,modelo,kilometraje,marca,rfc_compania_a)values('123456789','2016','120','Ford Fiesta','CUPU800825569');
insert into automovil(num_serie,modelo,kilometraje,marca,rfc_compania_a)values('987654321','2015','100','Chevrolet suburban','AFCD931513510');
insert into automovil(num_serie,modelo,kilometraje,marca,rfc_compania_a)values('987612345','2017','100','Nissan Tsuru','ZXCV674301920');
insert into automovil(num_serie,modelo,kilometraje,marca,rfc_compania_a)values('123459876','2014','110','Toyota Avanza','QWER106277590');
insert into automovil(num_serie,modelo,kilometraje,marca,rfc_compania_a)values('678954321','2019','130','BMW i3','HLKJ651038296');
---------------------------------------------------------------
//Insercion propietario
insert into propietario(rfc_propietario,nombre,telefono,num_serie_p)values('LAGF459828279','Mario','3376223372','123456789');
insert into propietario(rfc_propietario,nombre,telefono,num_serie_p)values('POSV929381229','Carlos','3345103308','987654321');
insert into propietario(rfc_propietario,nombre,telefono,num_serie_p)values('GKJH847280998','Javier','3346501299','987612345');
insert into propietario(rfc_propietario,nombre,telefono,num_serie_p)values('MNBV123589715','Claudia','3321984137','123459876');
insert into propietario(rfc_propietario,nombre,telefono,num_serie_p)values('CGYU678554312','Sofia','3336898743','678954321');
---------------------------------------------------------------------
//Insercion taller
insert into taller(rfc_taller,nombre,direccion)values('ASER349981356','Comprometido', 'locura # 589 san ignacio');
insert into taller(rfc_taller,nombre,direccion)values('BJKO136701524','Confiable', 'aderezo # 541 chinatown');
insert into taller(rfc_taller,nombre,direccion)values('MLPZO24680268','Responsable', 'manzano # 1020 reforma');
insert into taller(rfc_taller,nombre,direccion)values('DFUI468024792','Leal', 'aguacte # 111 rio nilo');
insert into taller(rfc_taller,nombre,direccion)values('ZXKL7925813','VELOZ', 'cactus # 555 zapote');
-----------------------------------------------------------------
//insercion reporte_quejas
insert into reporte_quejas(num_reporte_q,def_detectado,kilometraje,fecha,rfc_propietario_q,num_serie_q)values('345','Chasis','120','2016-08-15','LAGF459828279','123456789');
insert into reporte_quejas(num_reporte_q,def_detectado,kilometraje,fecha,rfc_propietario_q,num_serie_q)values('109','Motor','100','2015-01-29','POSV929381229','987654321');
insert into reporte_quejas(num_reporte_q,def_detectado,kilometraje,fecha,rfc_propietario_q,num_serie_q)values('194','Rodaje','100','2017-09-01','GKJH847280998','987612345');
insert into reporte_quejas(num_reporte_q,def_detectado,kilometraje,fecha,rfc_propietario_q,num_serie_q)values('315','Aceite','110','2014-09-01','MNBV123589715','123459876');
insert into reporte_quejas(num_reporte_q,def_detectado,kilometraje,fecha,rfc_propietario_q,num_serie_q)values('400','Alarma','130','2019-04-20','CGYU678554312','678954321');
---------------------------------------------------------------------------
//insercion reporte_taller
insert into reporte_taller(num_reportet,estado_gen,falla_marca,falla_modelo,fecha,rfc_taller_r)values('11','Reparable','1','0','2016-09-01','ASER349981356');
insert into reporte_taller(num_reportet,estado_gen,falla_marca,falla_modelo,fecha,rfc_taller_r)values('100','Situacion precaria','0','1','2015-02-05','BJKO136701524');
insert into reporte_taller(num_reportet,estado_gen,falla_marca,falla_modelo,fecha,rfc_taller_r)values('1200','Reparacion','1','1','2017-09-15','MLPZO24680268');
insert into reporte_taller(num_reportet,estado_gen,falla_marca,falla_modelo,fecha,rfc_taller_r)values('300','Restauracio completa','1','1','2014-10-20','DFUI468024792');
insert into reporte_taller(num_reportet,estado_gen,falla_marca,falla_modelo,fecha,rfc_taller_r)values('500','Sin fallas','0','0','2019-04-22','ZXKL7925813');
----------------------------------------------------------------------------
//insercion inspeccion
insert into inspeccion(estado_siscom,sistema_eficiencia_concat,interruptores,sistema_senoxg,sensores, actuadores,sistema_det_igncil, rfc_taller_i)values('Funcionable','0','0','0','1','0','1','ASER349981356');
insert into inspeccion(estado_siscom,sistema_eficiencia_concat,interruptores,sistema_senoxg,sensores, actuadores,sistema_det_igncil, rfc_taller_i)values('No funcinable','1','1','1','0','1','0','BJKO136701524');
insert into inspeccion(estado_siscom,sistema_eficiencia_concat,interruptores,sistema_senoxg,sensores, actuadores,sistema_det_igncil, rfc_taller_i)values('No funcionable','1','1','0','0','0','1','MLPZO24680268');
insert into inspeccion(estado_siscom,sistema_eficiencia_concat,interruptores,sistema_senoxg,sensores, actuadores,sistema_det_igncil, rfc_taller_i)values('Funcionable','0','0','0','0','0','0','DFUI468024792');
insert into inspeccion(estado_siscom,sistema_eficiencia_concat,interruptores,sistema_senoxg,sensores, actuadores,sistema_det_igncil, rfc_taller_i)values('Funcionable','0','0','0','0','0','0','ZXKL7925813');

Fabricantes de automóviles
Consultar los reportes de fallas de un mes, elaborados por cada taller
select num_reportet, estado_gen, falla_marca, falla_modelo, rfc_taller_r, nombre from reporte_taller join taller on rfc_taller = rfc_taller_r where fecha between '2016-09-01' and '2017-09-30';