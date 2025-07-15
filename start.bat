@echo off
REM Obtener la IP de WSL (adaptador "vEthernet (WSL)" o similar)
for /f "tokens=2 delims=:" %%A in ('ipconfig ^| findstr /R /C:"vEthernet.*IPv4"') do (
    set ip=%%A
)
REM Limpiar espacios en blanco al inicio
set ip=%ip:~1%

echo Usando DISPLAY=%ip%:0

REM Obtener directorio del script (con barra invertida al final)
set SCRIPT_DIR=%~dp0

REM Cambiar \ a / para la ruta Docker (opcional, Docker suele aceptar \ pero / es más seguro)
set MOUNT_DIR=%SCRIPT_DIR:\=/%

REM Añadir ros2_wks al final
set MOUNT_DIR=%MOUNT_DIR%ros2_wks

echo Montando volumen local: %MOUNT_DIR%

REM Lanzar el contenedor Docker con DISPLAY configurado y volumen dinámico
docker run -it --rm ^
  -e DISPLAY=%ip%:0 ^
  -e QT_X11_NO_MITSHM=1 ^
  -v "%MOUNT_DIR%:/root/ros2_ws" ^
  -v /tmp/.X11-unix:/tmp/.X11-unix ^
  ros2_hum1 & REM ros2_humb es el nombre del build de docker, se puede cambiar a uno diferente
