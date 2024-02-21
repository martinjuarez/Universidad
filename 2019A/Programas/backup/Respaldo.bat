@echo off
SET PG_BIN="C:\Program Files\PostgreSQL\11\bin\pg_dump.exe"
SET PG_HOST=localhost
SET PG_PORT=5432
SET PG_DATABASE=reciclaje
SET PG_USER=postgres
SET PGPASSWORD=212575181
SET PG_PATH=C:\Users\marti\Desktop\backup
SET PG_FILENAME=respaldo.txt
%PG_BIN% -U %PG_USER% -h %PG_HOST% -p %PG_PORT% %PG_DATABASE% > %PG_FILENAME%