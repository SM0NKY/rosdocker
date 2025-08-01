@echo off
title Lanzador ROS2 Docker

REM Verificar si Docker está en ejecución
docker info >nul 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo Docker Desktop no esta en ejecucion. Intentando iniciarlo...
    start "" "C:\Program Files\Docker\Docker\Docker Desktop.exe"
    
    REM Esperar a que Docker esté listo
    echo Esperando a que Docker este listo...
    :wait_docker
    timeout /t 2 >nul
    docker info >nul 2>&1
    IF %ERRORLEVEL% NEQ 0 (
        goto wait_docker
    )
    echo Docker esta listo.
)

REM Obtener la IP de WSL para el DISPLAY
for /f "tokens=2 delims=:" %%A in ('ipconfig ^| findstr /R /C:"vEthernet.*IPv4"') do (
    set ip=%%A
)
set ip=%ip:~1%

echo Usando DISPLAY=%ip%:0

REM Obtener ruta del script
set SCRIPT_DIR=%~dp0

REM Reemplazar '\' por '/'
set MOUNT_DIR=%SCRIPT_DIR:\=/%
set MOUNT_DIR=%MOUNT_DIR%ros2_wks

echo Montando volumen local: %MOUNT_DIR%

REM Lanzar contenedor Docker
docker run -it --rm ^
  -e DISPLAY=%ip%:0 ^
  -e QT_X11_NO_MITSHM=1 ^
  -v "%MOUNT_DIR%:/root/ros2_ws" ^
  -v /tmp/.X11-unix:/tmp/.X11-unix ^
  ros2_hum1 & REM ros2_hum1 es el nombre del build de docker, se puede cambiar a uno diferente
