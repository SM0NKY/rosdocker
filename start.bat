@echo off
REM Obtener la IP de WSL (adaptador "vEthernet (WSL)" o similar)
for /f "tokens=2 delims=:" %%A in ('ipconfig ^| findstr /R /C:"vEthernet.*IPv4"') do (
    set ip=%%A
)
REM Limpiar espacios en blanco al inicio
set ip=%ip:~1%

echo Usando DISPLAY=%ip%:0

REM Lanzar el contenedor Docker con DISPLAY configurado
docker run -it --rm ^
  -e DISPLAY=%ip%:0 ^
  -e QT_X11_NO_MITSHM=1 ^
  -v "E:/UABC/CIUDSE/Rover - Software/PruebasDocker/ROS_HUMBLE/ros2_wks:/root/ros2_ws" ^
  -v /tmp/.X11-unix:/tmp/.X11-unix ^
  ros2_hum1
