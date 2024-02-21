CREATE DATABASE biblioteca;
CREATE TABLE tipo_usuarios(
	id_role   SERIAL,
	usuario   VARCHAR(30),
	CONSTRAINT          pk_tipo_usuarios  PRIMARY KEY(id_role)
);

CREATE TABLE cede_biblioteca(
	nom_cede 	   VARCHAR(25) 	 NOT NULL,
	num_cede 	   INT 		 NOT NULL,
	CONSTRAINT 	   pk_cede_biblioteca  	 PRIMARY KEY(num_cede),
	CONSTRAINT 	   key_nom_cede 	 UNIQUE (nom_cede)	
);


CREATE TABLE usuario(
	id_usuario          SERIAL,
	usuario             VARCHAR(50)  NOT NULL,
	nombre              VARCHAR(50)  NOT NULL,
	edad                INT          NOT NULL,
	domicilio           VARCHAR(50)  NOT NULL,
	correo_electronico  VARCHAR(50)  NOT NULL,
	telefono            VARCHAR(15)  NOT NULL,
	password            VARCHAR(50)  NOT NULL,
	last_session	    TIMESTAMP    DEFAULT now(),
	id_tipo		    INT          NOT NULL,
	num_cede 	    INT 	 NOT NULL,
	CONSTRAINT          pk_usuario   	 PRIMARY KEY(id_usuario),
	CONSTRAINT          fk_cede_biblioteca   FOREIGN KEY(num_cede)  REFERENCES cede_biblioteca(num_cede)
);

CREATE TABLE libro(
	isbn           SERIAL,
	nombre         VARCHAR(30)  NOT NULL,
	genero         VARCHAR(15)  NOT NULL,
	editorial      VARCHAR(30)  NOT NULL,
	num_cede       INT	    NOT NULL,
	CONSTRAINT     pk_libro     PRIMARY KEY(isbn),
	CONSTRAINT          fk_cede_biblioteca   FOREIGN KEY(num_cede)  REFERENCES cede_biblioteca(num_cede)
);

CREATE TABLE autor(
	id_autor       SERIAL,
	nombre         VARCHAR(30)  NOT NULL,
	nacionalidad   VARCHAR(15)  NOT NULL,
	CONSTRAINT     pk_autor     PRIMARY KEY(id_autor)
);

CREATE TABLE ejemplar(
	num_ejem               SERIAL,
	disponibilidad         VARCHAR(30)  NOT NULL,
	fecha_disponibilidad   VARCHAR(15)  NOT NULL,
	id_usuario             INT,
	isbn                   INT,
	num_cede 	       INT 	    NOT NULL,
	CONSTRAINT             pk_ejemplar  PRIMARY KEY(num_ejem),
	CONSTRAINT             fk_usuario   FOREIGN KEY(id_usuario)  REFERENCES usuario(id_usuario),
	CONSTRAINT             fk_libro     FOREIGN KEY(isbn)        REFERENCES libro(isbn),
	CONSTRAINT             fk_cede_biblioteca   FOREIGN KEY(num_cede)  REFERENCES cede_biblioteca(num_cede)   	
);

CREATE TABLE multa(
	num_multa      SERIAL,
	monto          VARCHAR(30)  NOT NULL,
	num_ejem       INT          NOT NULL,
	id_usuario     INT,
	CONSTRAINT     pk_multa     PRIMARY KEY(num_multa),
	CONSTRAINT     fk_ejemplar  FOREIGN KEY(num_ejem)    REFERENCES ejemplar(num_ejem),
	CONSTRAINT     fk_usuario   FOREIGN KEY(id_usuario)  REFERENCES usuario(id_usuario)
);

CREATE TABLE reserva_libro(
	num_ejem       INT,
	id_usuario     INT,
	CONSTRAINT     pk_reserva_libro  PRIMARY KEY(num_ejem, id_usuario),
	CONSTRAINT     fk_ejemplar       FOREIGN KEY(num_ejem )          REFERENCES ejemplar(num_ejem),
	CONSTRAINT     fk_usuario        FOREIGN KEY(id_usuario)         REFERENCES usuario(id_usuario)
);

CREATE TABLE autor_libro(
	isbn           INT,
	id_autor       INT,
	CONSTRAINT     pk_autor_libro      PRIMARY KEY(isbn, id_autor),
	CONSTRAINT     fk_libro            FOREIGN KEY(isbn)             REFERENCES libro(isbn),
	CONSTRAINT     fk_autor            FOREIGN KEY(id_autor)         REFERENCES autor(id_autor)
);