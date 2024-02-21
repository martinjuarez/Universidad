CREATE TABLE  Agenda (
	codigo VARCHAR(4) PRIMARY KEY, 
	dia DATE NOT NULL DEFAULT now());

CREATE TABLE Sector (
	Codigo varchar(4) PRIMARY KEY, 
	zona VARCHAR(40) NOT NULL,
	Responsable VARCHAR(40) UNIQUE NOT NULL);

CREATE TABLE Chofer (
	codigo 	varchar (4) PRIMARY KEY, 
	nombreOperador varchar(40) NOT NULL, 
	responsableAsignado  VARCHAR(40) NOT NULL UNIQUE, 
	FOREIGN KEY (responsableAsignado) REFERENCES sector (Responsable), 
	codigoAgenda VARCHAR(4) NOT NULL UNIQUE, 
	FOREIGN KEY (codigoAgenda) REFERENCES agenda (codigo));

CREATE TABLE Unidad (
	NoPlaca VARCHAR(8) PRIMARY KEY, 
	ubicacionActual VARCHAR(13) NOT NULL, 
	capacidadCamion INTEGER NOT NULL, 
	choferAsignado VARCHAR(4) NOT NULL UNIQUE, 
	FOREIGN KEY (choferAsignado) REFERENCES chofer(codigo));

CREATE TABLE Viaje (
	codigo VARCHAR(4) primary key, 
	inicioViaje VARCHAR(20) NOT NULL, 
	finViaje VARCHAR(20) NOT NULL, 
	unidadAsignada VARCHAR(8) NOT NULL UNIQUE, 
	FOREIGN KEY (unidadAsignada) REFERENCES Unidad (NoPlaca));

CREATE TABLE Vertedero (
	Codigo VARCHAR(4) PRIMARY KEY,
	Nombre VARCHAR (40) NOT NULL); 

CREATE TABLE Ruta (
	codigo VARCHAR(4) PRIMARY KEY, 
	Destino VARCHAR (40) NOT NULL, 
	TipoResiduo VARCHAR(20) NOT NULL, 
	inicioHorario TIME NOT NULL, 
	finHorario TIME NOT NULL, 
	codigoAgenda VARCHAR(4) NOT NULL UNIQUE, 
	FOREIGN KEY (codigoAgenda) REFERENCES agenda (codigo), 
	vertederoAsignado VARCHAR (4) NOT NULL UNIQUE, 
	FOREIGN KEY (vertederoAsignado) REFERENCES vertedero (codigo),
	sectorCodigo VARCHAR (4) NOT NULL UNIQUE, 
	FOREIGN KEY (sectorCodigo) REFERENCES sector (codigo)); 