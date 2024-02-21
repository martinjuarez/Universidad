@echo off
SET PG_BIN="C:\Program Files\PostgreSQL\12\bin\psql.exe"
SET PG_HOST=localhost
SET PG_PORT=5432
SET PG_DATABASE=biblioteca
SET PG_USER=postgres
SET PGPASSWORD=212575181
SET PG_PATH=C:\Users\marti\Desktop\Respaldo y Recuperacion
SET PG_FILENAME=respaldoBiblioteca.txt
%PG_BIN% -U %PG_USER% -h %PG_HOST% -p %PG_PORT% %PG_DATABASE% < %PG_FILENAME%