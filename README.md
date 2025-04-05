
# Proyecto Grupo Amep

Instrucciones para preparar el entorno de trabajo

Dependencias:
- PHP 8.3.6
- Mariadb
- Composer 2.7.1

Instalación para un Debian/Ubuntu:

```
sudo apt update
sudo apt install php php-cli php-fpm php-mbstring php-xml php-mysql php-curl php-zip php-json php-common php-mysql php-cli mariadb-server mariadb-client composer

```
Configurar
Una vez instalado, en la carpeta del proyecto instalar composer:
```
composer install
```


Ejecutar el servidor de forma local:
```
php -S localhost:8000
```

Desde el navegador, acceder a http://localhost:8000


