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
insert into compania(rfc_compania,nombre,direccion)values('QWER106277590','VOLKSWAGEN','realidad #470 tierra');
insert into compania(rfc_compania,nombre,direccion)values('HLKJ651038296','KENTWORTH','infernus #666 dolores');
//insercion automovil

