# Imagen base con ROS 2 Humble y herramientas GUI
FROM osrf/ros:humble-desktop-full

# Evitar prompts interactivos
ARG DEBIAN_FRONTEND=noninteractive

# Usar el usuario root para instalar dependencias
USER root

# Instalar herramientas básicas del sistema
RUN apt update && apt install -y \
    libx11-xcb1 \
    libxrender1 \
    libxcb-render0 \
    libxcb-shape0 \
    libxcb-xfixes0 \
    libxcb1 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-shm0 \
    libxcb-sync1 \
    libxcb-xinerama0 \
    libxcb-xkb1 \
    libxkbcommon-x11-0\
    curl \
    git \
    build-essential \
    python3-colcon-common-extensions \
    python3-pip \
    locales \
    nano \
    lsb-release \
    software-properties-common \
    && rm -rf /var/lib/apt/lists/*

# Configurar locales (opcional, pero recomendado)
RUN locale-gen en_US en_US.UTF-8 && \
    update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 && \
    export LANG=en_US.UTF-8

ENV QT_X11_NO_MITSHM=1
# Crear espacio de trabajo
RUN mkdir -p /root/ros2_ws/src

# Fuente de ROS al entrar
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# Establecer directorio de trabajo
WORKDIR /root/ros2_ws

# Usar bash por defecto
CMD ["bash"]
